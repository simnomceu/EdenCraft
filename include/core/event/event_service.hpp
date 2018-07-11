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

#ifndef EVENT_SERVICE_HPP
#define EVENT_SERVICE_HPP

#include "core/config.hpp"
#include "utility/service/service_factory.hpp"
#include "utility/service/service_locator.hpp"
#include "core/event/base_event_manager.hpp"

namespace ece
{
	namespace utility
	{
		namespace service
		{

			class core::event::EventManagerConsumer;

			/**
			* @class ServiceFactory
			* @tparam Base The base class of service
			* @brief A factory for a category of services.
			*/
			template <>
			class ServiceFactory<core::event::BaseEventManager>
			{
			public:
				/**
				* @fn std::shared_ptr<Base> build()
				* @tparam Derived The derived class of the service to build
				* @return The base service built
				* @brief Build the service according to the derived implementation.
				* @throw
				* @remark It should be refactor to something like that: build(Args...&& args)
				*/
				template <class Derived>
				static std::shared_ptr<core::event::BaseEventManager> build()
				{
					if (!std::is_base_of<core::event::BaseEventManager, Derived>()) {
						throw InitializationException("This class cannot be instantiate as the service wished. Check again.");
					}
					return std::shared_ptr<core::event::BaseEventManager>(new Derived());
				}
			};

			/**
			* @class ServiceLocator
			* @tparam Base The base class of the service to locate
			* @tparam Null A default implementation for the service.
			* @brief Encapsulate a unique instance of a service category.
			*/
			class ECE_CORE_API EventServiceLocator : public ServiceLocator<core::event::BaseEventManager, core::event::BaseEventManager>
			{
				static_assert(std::is_base_of<core::event::BaseEventManager, core::event::BaseEventManager>::value, "ServiceLocator cannot be instantiate with this template parameters.");

			public:
				/**
				* @fn void provide(const std::shared_ptr<Base> & service)
				* @param[in] service The service which has to be provided by the locator.
				* @brief Set the service provided by the locator.
				* @throw
				*/
				static void provide(const std::shared_ptr<core::event::BaseEventManager> & service);

				/**
				* @fn Base & getService()
				* @return The service currently started.
				* @brief Consume the service provided.
				* @throw
				* @remark Should be rename as consume() ?
				*/
				static core::event::BaseEventManager & getService();

				//static std::weak_ptr<Base> getServicePtr();

				/**
				* @fn void stop()
				* @brief Stop the current service. The locator still exists but provide an empty service (which do nothing).
				* @throw
				*/
				static void stop();

				/**
				* @fn std::weak_ptr<BaseEventManager> getServicePtr(EventManagerConsumer & consumer)
				* @param[in] consumer A pass to access the service.
				* @return The naked pointer to the service.
				* @brief Get a naked pointer to the current service.
				*/
				static std::weak_ptr<core::event::BaseEventManager> getServicePtr(core::event::EventManagerConsumer & consumer);

			protected:
				/**
				* @property _service
				* @brief The service to expose.
				*/
				static std::shared_ptr<core::event::BaseEventManager> _service;
			};
		}
	}

	namespace core
	{
		namespace event
		{
			using utility::service::ServiceFactory;
			using utility::service::ServiceLocator;

			/**
			 * @typedef EventServiceFactory
			 * @brief A factory to build an event manager as a service.
			 */
			using EventServiceFactory = ServiceFactory<BaseEventManager>;

			/**
			 * @class EventServiceLocator
			 * @extends ServiceLocator<BaseEventManager, BaseEventManager>
			 * @brief Provide a service to access event management.
			 */
			using utility::service::EventServiceLocator;
		} // namespace event
	} // namespace core
} // namespace ece

#endif // EVENT_SERVICE_HPP
