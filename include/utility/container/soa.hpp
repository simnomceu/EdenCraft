/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#ifndef SOA_HPP
#define SOA_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace container
		{
			template <class... Args>
			class SoA;

			template <class First, class... Args>
			class SoA<First, Args...> : public SoA<Args...>
			{
			public:
				using value_type = typename std::vector<First>::value_type;
				using allocator_type = typename std::vector<First>::allocator_type;
				using size_type = typename std::vector<First>::size_type;
				using difference_type = typename std::vector<First>::difference_type;
				using reference = typename std::vector<First>::reference;
				using const_reference = typename std::vector<First>::const_reference;
				using pointer = typename std::vector<First>::pointer;
				using const_pointer = typename std::vector<First>::const_pointer;
				using iterator = typename std::vector<First>::iterator;
				using const_iterator = typename std::vector<First>::const_iterator;
				using reverse_iterator = typename std::vector<First>::reverse_iterator;
				using const_reverse_iterator = typename std::vector<First>::const_reverse_iterator;

				SoA() noexcept = default;
				SoA(const SoA<First, Args...> & rhs) noexcept = default;
				SoA(SoA<First, Args...> && rhs) noexcept = default;
				
				~SoA() noexcept = default;

				SoA<First, Args...> & operator=(const SoA<First, Args...> & rhs) noexcept = default;
				SoA<First, Args...> & operator=(SoA<First, Args...> && rhs) noexcept = default;

				void assign(size_type count, const First & first, Args &&... args)
				{
					this->_value.assign(count, first);
					SoA<Args...>::assign(count, args...);
				}

//				template<class InputIt> void assign(InputIt first, InputIt last);
//				void assign(std::initializer_list<std::tuple<First, Args...>> ilist);

				auto get_allocator() const { return std::tuple_cat(std::make_tuple(this->_value.get_allocator()), SoA<Args...>::get_allocator()); }

				auto at(size_type index) -> std::tuple<First, Args...> { return std::tuple_cat(std::tie(this->_value.at(index)), SoA<Args...>::at(index)); }
				auto operator[](size_type index) -> std::tuple<First, Args...> { return std::tuple_cat(std::tie(this->_value[index]), SoA<Args...>::operator[](index)); }
				auto front() { return std::tuple_cat(std::tie(this->_value.front()), SoA<Args...>::front()); }
				auto front() const { return std::tuple_cat(std::make_tuple(this->_value.front()), SoA<Args...>::front()); }
				auto back() { return std::tuple_cat(std::tie(this->_value.back()), SoA<Args...>::back()); }
				auto back() const { return std::tuple_cat(std::make_tuple(this->_value.back()), SoA<Args...>::back()); }
				auto data() noexcept { return std::tuple_cat(std::tie(this->_value.data()), SoA<Args...>::data()); }
				auto data() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.data()), SoA<Args...>::data()); }

				auto begin() noexcept { return std::tuple_cat(std::make_tuple(this->_value.begin()), SoA<Args...>::begin()); }
				auto begin() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.begin()), SoA<Args...>::begin()); }
				auto cbegin() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.cbegin()), SoA<Args...>::cbegin()); }
				auto end() noexcept { return std::tuple_cat(std::make_tuple(this->_value.end()), SoA<Args...>::end()); }
				auto end() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.end()), SoA<Args...>::end()); }
				auto cend() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.cend()), SoA<Args...>::cend()); }
				auto rbegin() noexcept { return std::tuple_cat(std::make_tuple(this->_value.rbegin()), SoA<Args...>::rbegin()); }
				auto rbegin() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.rbegin()), SoA<Args...>::rbegin()); }
				auto crbegin() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.crbegin()), SoA<Args...>::crbegin()); }
				auto rend() noexcept { return std::tuple_cat(std::make_tuple(this->_value.rend()), SoA<Args...>::rend()); }
				auto rend() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.rend()), SoA<Args...>::rend()); }
				auto crend() const noexcept { return std::tuple_cat(std::make_tuple(this->_value.crend()), SoA<Args...>::crend()); }

				bool empty() const noexcept { return this->_value.empty(); }
				size_type size() const noexcept { return this->_value.size(); }
				size_type max_size() const noexcept { return this->_value.max_size(); }
				void reserve(size_type new_cap)
				{
					this->_value.reserve(new_cap);
					SoA<Args...>::reserve(new_cap);
				}
				size_type capacity() const noexcept { return this->_value.capacity(); }
				void shrink_to_fit()
				{
					this->_value.shrink_to_fit();
					SoA<Args...>::shrink_to_fit();
				}

				void clear() noexcept
				{
					this->_value.clear();
					SoA<Args...>::clear();
				}
//				iterator insert(const_iterator pos, const T& value);
//				iterator insert(const_iterator pos, T&& value);
//				iterator insert(const_iterator pos, size_type count, const T& value);
//				template <class InputIt> iterator insert(const_iterator pos, InputIt first, InputIt last);
//				iterator insert(const_iterator pos, std::initializer_list<T> ilist);
//				template <class... Args> iterator emplace(const_iterator pos, Args&&... args);
//				iterator erase(const_iterator pos);
//				iterator erase(const_iterator first, const_iterator last);
				void push_back(const First & first, Args &&... args)
				{
					this->_value.push_back(first);
					SoA<Args...>::push_back(std::forward<Args>(args)...);
				}
				void push_back(First && first, Args &&... args)
				{
					this->_value.push_back(std::move(first));
					SoA<Args...>::push_back(std::forward<Args>(args)...);
				}
				void emplace_back(First && first, Args &&... args)
				{
					this->_value.emplace_back(std::move(first));
					SoA<Args...>::emplace_back(std::forward<Args>(args)...);
				}
				void pop_back()
				{
					this->_value.pop_back();
					SoA<Args...>::pop_back();
				}
				void resize(size_type count)
				{
					this->_value.resize(count);
					SoA<Args...>::resize(count);
				}
				void resize(size_type count, const First & first, Args &&... args)
				{
					this->_value.resize(count, first);
					SoA<Args...>::resize(count, args...);
				}
				void swap(SoA<First, Args...> & other)
				{
					this->_value.swap(other.getAll());
					SoA<Args...>::swap(other);
				}

				std::vector<First> & getAll() { return this->_value; }

			protected:
				using type = First;
				std::vector<First> _value;
			};

			template <class E>
			class SoA<E>
			{
			public:
				using value_type = typename std::vector<E>::value_type;
				using allocator_type = typename std::vector<E>::allocator_type;
				using size_type = typename std::vector<E>::size_type;
				using difference_type = typename std::vector<E>::difference_type;
				using reference = typename std::vector<E>::reference;
				using const_reference = typename std::vector<E>::const_reference;
				using pointer = typename std::vector<E>::pointer;
				using const_pointer = typename std::vector<E>::const_pointer;
				using iterator = typename std::vector<E>::iterator;
				using const_iterator = typename std::vector<E>::const_iterator;
				using reverse_iterator = typename std::vector<E>::reverse_iterator;
				using const_reverse_iterator = typename std::vector<E>::const_reverse_iterator;

				SoA() noexcept = default;
				SoA(const SoA<E> & rhs) noexcept = default;
				SoA(SoA<E> && rhs) noexcept = default;

				~SoA() noexcept = default;

				SoA<E> & operator=(const SoA<E> & rhs) noexcept = default;
				SoA<E> & operator=(SoA<E> && rhs) noexcept = default;

				void assign(size_type count, const E & first) { this->_value.assign(count, first); }

//				template<class InputIt> void assign(InputIt first, InputIt last);
//				void assign(std::initializer_list<std::tuple<First, Args...>> ilist);

				auto get_allocator() const { return std::make_tuple(this->_value.get_allocator()); }

				auto at(size_type index) { return std::tie(this->_value.at(index)); }
				auto operator[](size_type index) { return std::tie(this->_value[index]); }
				auto front() { return std::tie(this->_value.front()); }
				auto front() const { return std::make_tuple(this->_value.front()); }
				auto back() { return std::tie(this->_value.back()); }
				auto back() const { return std::make_tuple(this->_value.back()); }
				auto data() noexcept { return std::tie(this->_value.data()); }
				auto data() const noexcept { return std::make_tuple(this->_value.data()); }

				auto begin() noexcept { return std::make_tuple(this->_value.begin()); }
				auto begin() const noexcept { return std::make_tuple(this->_value.begin()); }
				auto cbegin() const noexcept { return std::make_tuple(this->_value.cbegin()); }
				auto end() noexcept { return std::make_tuple(this->_value.end()); }
				auto end() const noexcept { return std::make_tuple(this->_value.end()); }
				auto cend() const noexcept { return std::make_tuple(this->_value.cend()); }
				auto rbegin() noexcept { return std::make_tuple(this->_value.rbegin()); }
				auto rbegin() const noexcept { return std::make_tuple(this->_value.rbegin()); }
				auto crbegin() const noexcept { return std::make_tuple(this->_value.crbegin()); }
				auto rend() noexcept { return std::make_tuple(this->_value.rend()); }
				auto rend() const noexcept { return std::make_tuple(this->_value.rend()); }
				auto crend() const noexcept { return std::make_tuple(this->_value.crend()); }

				bool empty() const noexcept { return this->_value.empty(); }
				size_type size() const noexcept { return this->_value.size(); }
				size_type max_size() const noexcept { return this->_value.max_size(); }
				void reserve(size_type new_cap) { this->_value.reserve(new_cap); }
				size_type capacity() const noexcept { return this->_value.capacity(); }
				void shrink_to_fit() { this->_value.shrink_to_fit(); }

				void clear() noexcept { this->_value.clear(); }
//				iterator insert(const_iterator pos, const T& value);
//				iterator insert(const_iterator pos, T&& value);
//				iterator insert(const_iterator pos, size_type count, const T& value);
//				template <class InputIt> iterator insert(const_iterator pos, InputIt first, InputIt last);
//				iterator insert(const_iterator pos, std::initializer_list<T> ilist);
//				template <class... Args> iterator emplace(const_iterator pos, Args&&... args);
//				iterator erase(const_iterator pos);
//				iterator erase(const_iterator first, const_iterator last);
				void push_back(const value_type & first) { this->_value.push_back(first); }
				void push_back(value_type && first) { this->_value.push_back(std::move(first)); }
				void emplace_back(value_type && first) { this->_value.emplace_back(std::move(first)); }
				void pop_back() { this->_value.pop_back(); }
				void resize(size_type count) { this->_value.resize(count); }
				void resize(size_type count, const value_type & value) { this->_value.resize(count, value); }
				void swap(SoA<E> & other) { this->_value.swap(other.getAll()); }

				std::vector<E> & getAll() { return this->_value; }

			protected:
				using type = E;
				std::vector<E> _value;
			};
		} // namespace container
	} // namespace utility
} // namespace ece

#endif // SOA_HPP