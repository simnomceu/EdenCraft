/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.
															 d8P'  `Y8b
															888           .ooooo.  oooo d8b  .ooooo.
															888          d88' `88b `888""8P d88' `88b
															888          888   888  888     888ooo888
															`88b    ooo  888   888  888     888    .o
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P'



				This file is part of EdenCraft Engine - Core module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/


#include "core/application/application.hpp"

#include "utility/log/service_logger.hpp"
#include "utility/log/logger.hpp"
#include "core/event/event_service.hpp"
#include "core/event/event_manager.hpp"
#include "core/resource/service_resource.hpp"
#include "core/resource/resource_manager.hpp"
#include "core/module/module_method.hpp"
#include "utility/debug/exception.hpp"

namespace ece
{
	namespace core
	{
		namespace application
		{
			using utility::log::ServiceLoggerLocator;
			using utility::log::ServiceLoggerFactory;
			using utility::log::Logger;
			using core::event::EventServiceLocator;
			using core::event::EventServiceFactory;
			using core::event::EventManager;
			using core::resource::ServiceResourceLocator;
			using core::resource::ServiceResourceFactory;
			using core::resource::ResourceManager;

			Application::Application() : _running(false), _moduleManager(), _worlds(), _ups(0), _lifecycle(nullptr)
			{
				ServiceLoggerLocator::provide(ServiceLoggerFactory::build<Logger>());
				EventServiceLocator::provide(EventServiceFactory::build<EventManager>());
				ServiceResourceLocator::provide(ServiceResourceFactory::build<ResourceManager>());

				this->_lifecycle = std::make_shared<Lifecycle>();
			}

			Application::Application(int argc, char * argv[]) : _running(false), _moduleManager(), _worlds(), _ups(0), _lifecycle(nullptr)
			{
				ServiceLoggerLocator::provide(ServiceLoggerFactory::build<Logger>());
				EventServiceLocator::provide(EventServiceFactory::build<EventManager>());

				this->_lifecycle = std::make_shared<Lifecycle>();

				auto & argumentAnalyzer = this->addModule<ArgumentAnalyzer>(&ArgumentAnalyzer::analyze);
				argumentAnalyzer.setParameters(argc, argv);
			}

			Application::~Application() noexcept
			{
				ServiceResourceLocator::getService().clear();
			}

			void Application::run()
			{
				// TODO : add balancer to reduce usage of processor.
				this->_lifecycle->preInit();
				this->init();
				this->_lifecycle->postInit();

				while (this->isRunning()) {
					if (this->_ups.isReadyToUpdate()) {
						this->_lifecycle->preProcess();
						this->processEvents();
						this->_lifecycle->preUpdate();
						this->update();
						this->_lifecycle->postUpdate();
					}
					this->render();
					this->_lifecycle->postRender();
				}

				this->_lifecycle->preTerminate();
				this->terminate();
				this->_lifecycle->preTerminate();
			}

			World & Application::addWorld()
			{
				this->_worlds.emplace_back();
				return this->_worlds.back();
			}

			void Application::init()
			{
				try {
					this->_moduleManager.initAll();
				}
				catch (std::runtime_error & e) {
					ServiceLoggerLocator::getService().logError("Invalid command argument: " + std::string(e.what()));
				}
				this->_running = true;
			}

			void Application::update()
			{
				for (auto & world : this->_worlds) {
					world.update();
				}

				this->_moduleManager.updateAll();
			}

			void Application::processEvents()
			{
				//EventServiceLocator::getService().clear();
			}

			void Application::render()
			{
			}

			void Application::terminate()
			{
				this->_moduleManager.terminateAll();
			}
		} // namespace application
	} // namespace core
} // namespace ece
