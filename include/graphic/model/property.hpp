/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include "graphic/config.hpp"
#include "graphic/model/base_property.hpp"

#include <functional>

// ==================WORKING CODE===========================================
/*#include <iostream>
#include <functional>
#include <memory>

auto defaultComputed = [](auto && a) { return std::forward<decltype(a)>(a); };

class BaseProperty
{
public:
	~BaseProperty() = default;
	virtual void display() = 0;
};

template <class T, class F = decltype(defaultComputed)&>
class Property final : public BaseProperty
{
public:
	Property(T a = T(), F computed = defaultComputed) : _value(a), _computedValue(computed) {}

	auto get() { return this->_computedValue(this->_value); }
	virtual void display() override { std::cerr << this->get() << std::endl; }
private:
	T _value;
	F _computedValue;
};

template <typename T, typename F = decltype(defaultComputed)&>
auto makeProperty(T&& a, F&& computed = defaultComputed) {
	return std::make_shared<Property<T, F>>(std::forward<T>(a), std::forward<F>(computed));
}

int main()
{
	std::shared_ptr<BaseProperty> a(makeProperty(5)); a->display();
	auto b = makeProperty(5, [](auto a) -> auto { return a * 2.12f; }); b->display();
	auto c = makeProperty(5, [](auto a) -> float { return a * 2.0f; }); c->display();

	return 0;
}*/
// =============================================

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			static auto DefaultComputed = [](auto && a) -> auto { return std::forward<decltype(a)>(a); };

			/**
			 * @class Property
			 * @brief
			 */
			template <class T, typename F>
			class ECE_GRAPHIC_API Property final: public BaseProperty
			{
			public:
				Property(T value, F computedValue);

				/**
				 * @fn Property(const Property & copy)
				 * @param[in] copy The Property to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Property(const Property<T, F> & copy) = default;

				/**
				 * @fn Property(Property && move)
				 * @param[in] move The Property to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				Property(Property<T, F> && move) = default;

				/**
				 * @fn ~Property() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Property() noexcept = default;

				/**
				 * @fn Property & operator=(const Property & copy)
				 * @param[in] copy The Property to copy from.
				 * @return The Property copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Property<T, F> & operator=(const Property<T, F> & copy) = default;

				/**
				 * @fn Property & operator=(Property && move)
				 * @param[in] move The Property to move.
				 * @return The Property moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				Property<T, F> & operator=(Property<T, F> && move) = default;

				virtual std::shared_ptr<BaseUniform> getUniform(std::string name) override;

				Property<T, F> & operator=(const T & value);
				Property<T, F> & operator=(T && value);

			private:
				T _value;
				F _computedValue;
			};

			/*template <typename T, typename F = decltype(DefaultComputed)&>
			auto makeProperty(T&& a, F&& computed = DefaultComputed) {
				return Property(std::forward<T>(a), std::forward<F>(computed));
			}*/

			template <typename T, typename F = decltype(DefaultComputed)&>
			ECE_GRAPHIC_API auto makeProperty(T&& a = T(), F&& computed = DefaultComputed) {
				return std::make_shared<Property<T, F>>(std::forward<T>(a), std::forward<F>(computed));
			}
		} // namespace model
	} // namespace graphic
} // namespace model

#include "graphic/model/property.inl"

#endif // PROPERTY_HPP