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

#ifndef BASE_WINDOW_ADAPTER_HPP
#define BASE_WINDOW_ADAPTER_HPP

#include <memory>
#include <string>

#include "window/window_event/input_event.hpp"
#include "window/common/event_queue.hpp"
#include "utility/pattern/pimpl.hpp"

namespace ece
{
	struct DataWindowAdapter;
	struct WindowMessage;

	class BaseWindowAdapter
	{
	public:
		BaseWindowAdapter();
		BaseWindowAdapter(const BaseWindowAdapter & copy) = default;
		BaseWindowAdapter(BaseWindowAdapter && move) = default;

		virtual ~BaseWindowAdapter() = 0;

		BaseWindowAdapter & operator=(const BaseWindowAdapter & copy) = default;
		BaseWindowAdapter & operator=(BaseWindowAdapter && move) = default;

		virtual void createWindow() = 0;
		virtual void deleteWindow() = 0;
		virtual bool isWindowCreated() const = 0;

		virtual void setTitle(const std::string & title) = 0;
		virtual std::string getTitle() const = 0;

		virtual void setPosition(const IntVector2u & position) = 0;
		virtual IntVector2u getPosition() const = 0;

		virtual void minimize() = 0;
		virtual void maximize() = 0;

		void enableKeyRepeat(const bool enabled);

		virtual void processEvent(const bool blocking) = 0;
		bool hasEvents() const;
		InputEvent popEvent();

		virtual Pimpl<DataWindowAdapter> & getImpl() = 0;

	protected:
		void pushEvent(const InputEvent & nextEvent);
		InputEvent & lastEvent();

		bool _keyRepeat;

	private:
		EventQueue _eventQueue;
	};
}

#endif // BASE_WINDOW_ADAPTER_HPP
