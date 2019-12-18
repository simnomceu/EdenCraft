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
				using type = First;
				using container = std::conditional_t<std::is_same_v<First, bool>, BooleanVector, std::vector<First>>;

				using value_type = First;
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

				SoA() noexcept(noexcept(SoA<First, Args...>::allocator_type());
				explicit SoA(const allocator_type & alloc) noexcept;
				SoA(size_type count, const First & first, Args &&... args);
				explicit SoA(size_type count, const allocator_type & alloc = allocator_type());
				template <class InputIt> inline SoA(InputIt first, InputIt last, const allocator_type & alloc = allocator_type());
				SoA(const SoA<First, Args...> & other);
				SoA(const SoA<First, Args...> & other, const allocator_type & alloc);
				SoA(SoA<First, Args...> && other) noexcept;
				SoA(SoA<First, Args...> && other, const allocator_type & alloc);
				SoA(std::initializer_list<std::tuple<First, Args...>> init, const allocator_type & alloc = allocator_type());
				
				~SoA() noexcept;

				SoA<First, Args...> & operator=(const SoA<First, Args...> & rhs);
				SoA<First, Args...> & operator=(SoA<First, Args...> && rhs) noexcept(std::allocator_traits<allocator_type>::propagate_on_container_move_assignment::value || std::allocator_traits<allocator_type>::is_always_equal::value);
				SoA<First, Args...> & operator=(std::initializer_list<std::tuple<First, Args...>> ilist);

				void assign(size_type count, const First & first, Args &&... args);
				template <class InputIt, class... InputArgs> void assign(std::tuple<InputIt, InputArgs...> first, InputIt last);
				void assign(std::initializer_list<std::tuple<First, Args...>> ilist);
				auto get_allocator() const;

				auto at(size_type index) -> std::tuple<First &, Args & ...>;
				auto at(size_type index) const -> std::tuple<const First, const Args & ...>;
				
				auto operator[](size_type index) -> std::tuple < First &, Args & ...);
				auto operator[](size_type index) const -> std::tuple<const First &, const Args & ...> { return std::tuple_cat(std::tie(this->_internal[index]), SoA<Args...>::operator[](index)); }

				auto front();
				auto front() const;
				
				auto back();
				auto back() const;
				
				auto data() noexcept;
				auto data() const noexcept;

				auto begin() noexcept;
				auto begin() const noexcept;
				auto cbegin() const noexcept;

				auto end() noexcept;
				auto end() const noexcept;
				auto cend() const noexcept;

				auto rbegin() noexcept;
				auto rbegin() const noexcept;
				auto crbegin() const noexcept;

				auto rend() noexcept;
				auto rend() const noexcept;
				auto crend() const noexcept;

				bool empty() const noexcept;
				size_type size() const noexcept;
				size_type max_size() const noexcept;
				void reserve(size_type new_cap);
				size_type capacity() const noexcept;
				void shrink_to_fit();

				void clear() noexcept;
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
					this->_internal.push_back(first);
					SoA<Args...>::push_back(std::forward<Args>(args)...);
				}
				void push_back(First && first, Args &&... args)
				{
					this->_internal.push_back(std::move(first));
					SoA<Args...>::push_back(std::forward<Args>(args)...);
				}
				void emplace_back(First && first, Args &&... args)
				{
					this->_internal.emplace_back(std::move(first));
					SoA<Args...>::emplace_back(std::forward<Args>(args)...);
				}
				void pop_back()
				{
					this->_internal.pop_back();
					SoA<Args...>::pop_back();
				}
				void resize(size_type count)
				{
					this->_internal.resize(count);
					SoA<Args...>::resize(count);
				}
				void resize(size_type count, const First & first, Args &&... args)
				{
					this->_internal.resize(count, first);
					SoA<Args...>::resize(count, args...);
				}
				void swap(SoA<First, Args...> & other)
				{
					this->_internal.swap(other.getAll());
					SoA<Args...>::swap(other);
				}

				typename SoA::container & getAll() { return this->_internal; }

			protected:
				container _internal;
			};

			template <class E>
			class SoA<E>
			{
			public:
				using type = E;
				using container = std::conditional_t<std::is_same_v<E, bool>, BooleanVector, std::vector<E>>;

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

				void assign(size_type count, const E & first) { this->_internal.assign(count, first); }

//				template<class InputIt> void assign(InputIt first, InputIt last);
//				void assign(std::initializer_list<std::tuple<First, Args...>> ilist);

				auto get_allocator() const { return std::make_tuple(this->_internal.get_allocator()); }

				auto at(size_type index) { return std::tie(this->_internal.at(index)); }
				auto operator[](size_type index) { return std::tie(this->_internal[index]); }
				auto front() { return std::tie(this->_internal.front()); }
				auto front() const { return std::make_tuple(this->_internal.front()); }
				auto back() { return std::tie(this->_internal.back()); }
				auto back() const { return std::make_tuple(this->_internal.back()); }
				auto data() noexcept { return std::tie(this->_internal.data()); }
				auto data() const noexcept { return std::make_tuple(this->_internal.data()); }

				auto begin() noexcept { return std::make_tuple(this->_internal.begin()); }
				auto begin() const noexcept { return std::make_tuple(this->_internal.begin()); }
				auto cbegin() const noexcept { return std::make_tuple(this->_internal.cbegin()); }
				auto end() noexcept { return std::make_tuple(this->_internal.end()); }
				auto end() const noexcept { return std::make_tuple(this->_internal.end()); }
				auto cend() const noexcept { return std::make_tuple(this->_internal.cend()); }
				auto rbegin() noexcept { return std::make_tuple(this->_internal.rbegin()); }
				auto rbegin() const noexcept { return std::make_tuple(this->_internal.rbegin()); }
				auto crbegin() const noexcept { return std::make_tuple(this->_internal.crbegin()); }
				auto rend() noexcept { return std::make_tuple(this->_internal.rend()); }
				auto rend() const noexcept { return std::make_tuple(this->_internal.rend()); }
				auto crend() const noexcept { return std::make_tuple(this->_internal.crend()); }

				bool empty() const noexcept { return this->_internal.empty(); }
				size_type size() const noexcept { return this->_internal.size(); }
				size_type max_size() const noexcept { return this->_internal.max_size(); }
				void reserve(size_type new_cap) { this->_internal.reserve(new_cap); }
				size_type capacity() const noexcept { return this->_internal.capacity(); }
				void shrink_to_fit() { this->_internal.shrink_to_fit(); }

				void clear() noexcept { this->_internal.clear(); }
//				iterator insert(const_iterator pos, const T& value);
//				iterator insert(const_iterator pos, T&& value);
//				iterator insert(const_iterator pos, size_type count, const T& value);
//				template <class InputIt> iterator insert(const_iterator pos, InputIt first, InputIt last);
//				iterator insert(const_iterator pos, std::initializer_list<T> ilist);
//				template <class... Args> iterator emplace(const_iterator pos, Args&&... args);
//				iterator erase(const_iterator pos);
//				iterator erase(const_iterator first, const_iterator last);
				void push_back(const value_type & first) { this->_internal.push_back(first); }
				void push_back(value_type && first) { this->_internal.push_back(std::move(first)); }
				void emplace_back(value_type && first) { this->_internal.emplace_back(std::move(first)); }
				void pop_back() { this->_internal.pop_back(); }
				void resize(size_type count) { this->_internal.resize(count); }
				void resize(size_type count, const value_type & value) { this->_internal.resize(count, value); }
				void swap(SoA<E> & other) { this->_internal.swap(other.getAll()); }

				typename SoA::container & getAll() { return this->_internal; }

			protected:
				container _internal;
			};
		} // namespace container
	} // namespace utility
} // namespace ece

#include "utility/container/soa.inl"

#endif // SOA_HPP