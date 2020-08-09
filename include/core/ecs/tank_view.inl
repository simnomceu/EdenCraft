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

#include "core/ecs/component_tank.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			template <class ComponentType>
			TankView<ComponentType>::TankView(ComponentTank<ComponentType>& owner) noexcept: _owner(owner)
			{
			}

			template <class ComponentType>
			void TankView<ComponentType>::forEach(const std::function<void(ComponentType&)>& routine)
			{
				for (auto& component : this->_owner) {
					if (component) {
						routine(component);
					}
				}
			}

			template <class ComponentType>
			void TankView<ComponentType>::forEach(std::function<void(ComponentType&)>&& routine)
			{
				for (auto& component : this->_owner) {
					if (component) {
						routine(component);
					}
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forEach(T& object, void (T::* routine)(ComponentType&))
			{
				for (auto& component : this->_owner) {
					if (component) {
						routine(component);
					}
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forEach(std::weak_ptr<T>& object, void (T::* routine)(ComponentType&))
			{
				for (auto& component : this->_owner) {
					if (component) {
						(object.lock()->*routine)(component);
					}
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forEach(const T& object, void (T::* routine)(ComponentType&) const)
			{
				for (auto& component : this->_owner) {
					if (component) {
						(object.*routine)(component);
					}
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forEach(const std::weak_ptr<T>& object, void (T::* routine)(ComponentType&) const)
			{
				for (auto& component : this->_owner) {
					if (component) {
						(object.lock()->*routine)(component);
					}
				}
			}

			template <class ComponentType>
			void TankView<ComponentType>::forAll(const std::function<void(ComponentType&)>& routine)
			{
				for (auto& component : this->_owner) {
					routine(component);
				}
			}

			template <class ComponentType>
			void TankView<ComponentType>::forAll(std::function<void(ComponentType&)>&& routine)
			{
				for (auto& component : this->_owner) {
					routine(component);
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forAll(T& object, void (T::* routine)(ComponentType&))
			{
				for (auto& component : this->_owner) {
					(object.*routine)(component);
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forAll(std::weak_ptr<T>& object, void (T::* routine)(ComponentType&))
			{
				for (auto& component : this->_owner) {
					(object.lock()->*routine)(component);
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forAll(const T& object, void (T::* routine)(ComponentType&) const)
			{
				for (auto& component : this->_owner) {
					(object.*routine)(component);
				}
			}

			template <class ComponentType>
			template <class T>
			void TankView<ComponentType>::forAll(const std::weak_ptr<T>& object, void (T::* routine)(ComponentType&) const)
			{
				for (auto& component : this->_owner) {
					(object.lock()->*routine)(component);
				}
			}

			template <class ComponentType>
			auto TankView<ComponentType>::size() const -> std::size_t
			{
				return std::accumulate(this->_owner.begin(), this->_owner.end(), std::size_t{ 0 }, [](std::size_t result, const ComponentType & rhs) -> std::size_t {
					return result + (!rhs ? 0 : 1);
				});
			}

			template <class ComponentType>
			ComponentType& TankView<ComponentType>::at(const std::size_t index)
			{
				return this->_owner.at(index);
			}

			template <class ComponentType>
			const ComponentType& TankView<ComponentType>::at(const std::size_t index) const
			{
				return this->_owner.at(index);
			}

		}
	}
}