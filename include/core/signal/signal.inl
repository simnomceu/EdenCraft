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

#include "core/signal/slot.hpp"

namespace ece
{
	namespace core
	{
		namespace signal
		{
			template <class... Args>
			Connection Signal<Args...>::connect(const std::function<void(Args...)> & callback)
			{
				auto slot = std::make_shared<Slot<Args...>>(callback);
				this->attach(slot);
				return Connection(this->weak_from_this(), slot);
			}

			template <class... Args>
			Connection Signal<Args...>::connect(std::function<void(Args...)> && callback)
			{
				auto slot = std::make_shared<Slot<Args...>>(callback);
				this->attach(slot);
				return Connection(this->weak_from_this(), slot);
			}

			template <class... Args>
			template <class T>
			Connection Signal<Args...>::connect(T & object, void (T::*method)(Args... args))
			{
				return this->connect([&object, method](Args... args){ (object.*function)(std::forward<Args>(args)...); });
			}

			template <class... Args>
			template <class T>
			Connection Signal<Args...>::connect(std::weak_ptr<T> & object, void (T::*method)(Args... args))
			{
				return this->connect([&object, method](Args... args) { (object.lock()->*function)(std::forward<Args>(args)...); });
			}

			template <class... Args>
			template <class T>
			Connection Signal<Args...>::connect(const T & object, void (T::*method)(Args... args) const)
			{
				return this->connect([object, method](Args... args) { (object.*function)(std::forward<Args>(args)...); });
			}

			template <class... Args>
			template <class T>
			Connection Signal<Args...>::connect(const std::weak_ptr<T> & object, void (T::*method)(Args... args) const)
			{
				return this->connect([object, method](Args... args) { (object.lock()->*function)(std::forward<Args>(args)...); });
			}

			template <class... Args>
			inline void Signal<Args...>::disconnect(const std::shared_ptr<Slot<Args...>> & slot) { this->detach(slot); }

			template <class... Args>
			inline void Signal<Args...>::disconnectAll() { this->detachAll(); }

			template <class... Args>
			inline void Signal<Args...>::operator()(Args... args) { this->notify(std::forward<Args>(args)...); }
		} // namespace signal
	} // namespace core
} // namespace ece