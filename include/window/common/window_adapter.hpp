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

#ifndef WINDOW_ADAPTER_HPP
#define WINDOW_ADAPTER_HPP

#include "window/common/base_window_adapter.hpp"

namespace ece
{
	/**
	 * @class WindowAdapter
	 * @extends BaseWindowAdapter
	 * @brief Adapting window method to use the platform implementation.
	 */
	class WindowAdapter: public BaseWindowAdapter
	{
	public:
		/**
		 * @fn WindowAdapter() noexcept
		 * @brief Default constructor. The platform specific implementation is built with.
		 * @throw noexcept
		 */
		WindowAdapter() noexcept;

		/**
		 * @fn WindowAdapter(const WindowAdapter & copy)
		 * @param[in] copy The adapter to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		WindowAdapter(const WindowAdapter & copy) = default;
		
		/**
		 * @fn WindowAdapter(WindowAdapter && move) noexcept
		 * @param[in] move The adapter to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		WindowAdapter(WindowAdapter && move) noexcept = default;

		/**
		 * @fn ~WindowAdapter() noexcept 
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~WindowAdapter() noexcept = default;

		/**
		 * @fn WindowAdapter & operator=(const WindowAdapter & copy)
		 * @param[in] copy The adapter to copy from.
		 * @return The adapter copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		WindowAdapter & operator=(const WindowAdapter & copy) = default;

		/**
		 * @fn WindowAdapter & operator=(WindowAdapter && move) noexcept
		 * @param[in] move The adapter to move.
		 * @return The adapter moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		WindowAdapter & operator=(WindowAdapter && move) noexcept = default;

		/**
		 * @fn void createWindow()
		 * @brief Generate a window.
		 * @throw
		 * @see void BaseWindowAdapter::createWindow()
		 */
		virtual void createWindow() override;

		/**
		 * @fn void deleteWindow()
		 * @brief Delete a window.
		 * If that window does not exist, the behaviour is unknown.
		 * @throw
		 * @see void BaseWindowAdapter::deleteWindow()
		 */
		virtual void deleteWindow() override;

		/**
		 * @fn bool isWindowCreated() const
		 * @return True if window exist, false else.
		 * @brief Check if the window is existing or not.
		 * @throw
		 * @see bool BaseWindowAdapter::isWindowCreated() const
		 */
		virtual bool isWindowCreated() const override;

		/**
		 * @fn void setTitle(const std::string & title)
		 * @param[in] title The title to set.
		 * @brief Set the window title.
		 * @throw
		 * @see void BaseWindowAdapter::setTitle(const std::string & title)
		 */
		virtual void setTitle(const std::string & title) override;

		/**
		 * @fn std::string getTitle() const
		 * @return The title of the window.
		 * @brief Get the window title.
		 * @throw
		 * @see std::string BaseWindowAdapter::getTitle() const
		 */
		virtual std::string getTitle() const override;

		/**
		 * @fn void setPosition(const IntVector2u & position)
		 * @param[in] position The position to set the window to.
		 * @brief Set the window to the position.
		 * throw
		 * @see void BaseWindowAdapter::setPosition(const IntVector2u & position)
		 */
		virtual void setPosition(const IntVector2u & position) override;
		 
		/**
		 * @fn IntVector2u getPosition() const
		 * @return The window position.
		 * @brief Get the position of the window.
		 * @throw
		 * @see IntVector2u BaseWindowAdapter::getPosition() const
		 */
		virtual IntVector2u getPosition() const override;

		/**
		 * @fn void minimize()
		 * @brief Set the window to its minimum size.
		 * @throw
		 * @see void BaseWindowAdapter::minimize()
		 */
		virtual void minimize() override;

		/**
		 * @fn void maximize()
		 * @brief Set the window to its maximum size.
		 * @throw
		 * @see void BaseWindowAdapter::maximize()
		 */
		virtual void maximize() override;

		/**
		 * @fn void processEvent(const bool blocking)
		 * @param[in] blocking Block the thread until an event has been processed.
		 * @brief Process a window event.
		 * @throw
		 * @see void BaseWindowAdapter::processEvent(const bool blocking)
		 */
		virtual void processEvent(const bool blocking) override;

		/**
		 * @fn Pimpl<DataWindowAdapter> & getImpl()
		 * @return The platform implementation of the window.
		 * @brief Get the platform implementation of the window.
		 * @throw
		 * @see Pimpl<DataWindowAdapter> & BaseWindowAdapter::getImpl()
		 */
		virtual inline Pimpl<DataWindowAdapter> & getImpl() override;

		/**
		 * @fn void processMessage(const WindowMessage & message)
		 * @param[in] message The message to process.
		 * @brief Process a message regarding a window event.
		 * @throw
		 */
		void processMessage(const WindowMessage & message);

	private:
		/**
		 * @property _data
		 * @brief The platform implementation of the window.
		 */
		Pimpl<DataWindowAdapter> _data;
	};
}

#include "window/common/window_adapter.inl"

#endif // WINDOW_ADAPTER_HPP
