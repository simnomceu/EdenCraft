/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															oooooo   oooooo     oooo  o8o                    .o8                             
															 `888.    `888.     .8'   `"'                   "888                             
															  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo 
															   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'  
																`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'   
																 `888'    `888'       888   888   888  888   888  888   888    `888'`888'    
																  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'    


				This file is part of EdenCraft Engine - Window module.
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

#ifndef WINDOWED_APPLICATION_HPP
#define WINDOWED_APPLICATION_HPP

#include "window/config.hpp"
#include "core/application/application.hpp"
#include "window/common/window.hpp"

#include <type_traits>
#include <memory>

namespace ece
{
	namespace window
	{
		namespace common
		{
			using core::application::Application;

			/**
			 * @class WindowedApplication
			 * @brief
			 */
			class ECE_WINDOW_API WindowedApplication: public Application
			{
			public:
				/**
				 * @fn constexpr WindowedApplication() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				WindowedApplication() noexcept;

				WindowedApplication(int argc, char * argv[]);

				/**
				 * @fn WindowedApplication(const WindowedApplication & copy) noexcept
				 * @param[in] copy The WindowedApplication to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				WindowedApplication(const WindowedApplication & copy) noexcept = default;

				/**
				 * @fn WindowedApplication(WindowedApplication && move) noexcept
				 * @param[in] move The WindowedApplication to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				WindowedApplication(WindowedApplication && move) noexcept = default;

				/**
				 * @fn ~WindowedApplication() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~WindowedApplication() noexcept = default;

				/**
				 * @fn WindowedApplication & operator=(const WindowedApplication & copy) noexcept
				 * @param[in] copy The WindowedApplication to copy from.
				 * @return The WindowedApplication copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				WindowedApplication & operator=(const WindowedApplication & copy) noexcept = default;

				/**
				 * @fn WindowedApplication & operator=(WindowedApplication && move) noexcept
				 * @param[in] move The WindowedApplication to move.
				 * @return The WindowedApplication moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				WindowedApplication & operator=(WindowedApplication && move) noexcept = default;

				virtual void run() override;

				template <class T, class ... Args>
				std::enable_if_t<std::is_base_of_v<Window, T>, std::weak_ptr<T>> addWindow(Args&&... args);

			protected:
				std::vector<std::shared_ptr<Window>> _windows;
			};
		} // namespace common
	} // namespace window
} // namespace ece

#include "window/common/windowed_application.inl"

#endif // WINDOWED_APPLICATION_HPP