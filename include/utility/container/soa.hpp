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

				using value_type = std::tuple<First, Args...>;
				using allocator_type = std::tuple<typename std::vector<First>::allocator_type, typename std::vector<Args>::allocator_type ...>;
				using size_type = typename SoA<Args...>::size_type;
				using difference_type = typename SoA<Args...>::difference_type;
				using reference = std::tuple<First &, Args & ...>;
				using const_reference = std::tuple<const First &, const Args & ...>;
				using pointer = std::tuple<typename std::vector<First>::pointer, typename std::vector<Args>::pointer ...>;
				using const_pointer = std::tuple<typename std::vector<First>::const_pointer, typename std::vector<Args>::const_pointer ...>;
				using iterator = std::tuple<typename std::vector<First>::iterator, typename std::vector<Args>::iterator ...>;
				using const_iterator = std::tuple<typename std::vector<First>::const_iterator, typename std::vector<Args>::const_iterator ...>;
				using reverse_iterator = std::tuple<typename std::vector<First>::reverse_iterator, typename std::vector<Args>::reverse_iterator ...>;
				using const_reverse_iterator = std::tuple<typename std::vector<First>::const_reverse_iterator, typename std::vector<Args>::const_reverse_iterator ...>;

				SoA() noexcept;
				explicit SoA(const allocator_type & alloc) noexcept;
				SoA(size_type count, const First & first, Args &&... args);
				explicit SoA(size_type count, const allocator_type & alloc = allocator_type());
				template <class InputIt> inline SoA(InputIt first, InputIt last, const allocator_type & alloc = allocator_type());
				SoA(const SoA<First, Args...> & other);
				SoA(const SoA<First, Args...> & other, const allocator_type & alloc);
				SoA(SoA<First, Args...> && other) noexcept;
				SoA(SoA<First, Args...> && other, const allocator_type & alloc);
				SoA(std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> init, const allocator_type & alloc = allocator_type());
				
				~SoA() noexcept;

				SoA<First, Args...> & operator=(const SoA<First, Args...> & rhs);
				SoA<First, Args...> & operator=(SoA<First, Args...> && rhs) noexcept;
				SoA<First, Args...> & operator=(std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> ilist);

				void assign(size_type count, const First & first, Args &&... args);
				template <class InputIt> void assign(InputIt first, InputIt last);
				void assign(std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> ilist);
				auto get_allocator() const;

				auto at(size_type index) -> reference;
				auto at(size_type index) const -> const_reference;
				
				auto operator[](size_type index) -> reference;
				auto operator[](size_type index) const -> const_reference;

				auto front() -> reference;
				auto front() const -> const_reference;
				
				auto back() -> reference;
				auto back() const -> const_reference;
				
				auto data() noexcept -> pointer;
				auto data() const noexcept -> const_pointer;

				auto begin() noexcept -> iterator;
				auto begin() const noexcept -> const_iterator;
				auto cbegin() const noexcept -> const_iterator;

				auto end() noexcept -> iterator;
				auto end() const noexcept -> const_iterator;
				auto cend() const noexcept -> const_iterator;

				auto rbegin() noexcept -> reverse_iterator;
				auto rbegin() const noexcept -> const_reverse_iterator;
				auto crbegin() const noexcept -> const_reverse_iterator;

				auto rend() noexcept -> reverse_iterator;
				auto rend() const noexcept -> const_reverse_iterator;
				auto crend() const noexcept -> const_reverse_iterator;

				bool empty() const noexcept;
				size_type size() const noexcept;
				size_type max_size() const noexcept;
				void reserve(size_type new_cap);
				size_type capacity() const noexcept;
				void shrink_to_fit();

				void clear() noexcept;
				iterator insert(const_iterator pos, const First & first, Args && ... args);
				iterator insert(const_iterator pos, First && first, Args && ... args);
				iterator insert(const_iterator pos, size_type count, const First & first, Args && ... args);
				template <class InputIt> iterator insert(const_iterator pos, InputIt first, InputIt last);
				iterator insert(const_iterator pos, std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> ilist);
				iterator emplace(const_iterator pos, First && first, Args&&... args);
				iterator erase(const_iterator pos);
				iterator erase(const_iterator first, const_iterator last);
				void push_back(const First & first, Args &&... args);
				void push_back(First && first, Args &&... args);
				void emplace_back(First && first, Args &&... args);
				void pop_back();
				void resize(size_type count);
				void resize(size_type count, const First & first, Args &&... args);
				void swap(SoA<First, Args...> & other);

				friend bool operator==(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
				friend bool operator!=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
				friend bool operator<(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
				friend bool operator<=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
				friend bool operator>(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
				friend bool operator>=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);

				friend void swap(SoA<First, Args...> & lhs, SoA<First, Args...> & rhs) noexcept(noexcept(lhs.swap(rhs)));

				typename SoA::container & getAll();

			protected:
				container _internal;
			};

			template <class First, class... Args> bool operator==(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
			template <class First, class... Args> bool operator!=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
			template <class First, class... Args> bool operator<(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
			template <class First, class... Args> bool operator<=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
			template <class First, class... Args> bool operator>(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);
			template <class First, class... Args> bool operator>=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs);

			template <class First, class... Args> void swap(SoA<First, Args...> & lhs, SoA<First, Args...> & rhs) noexcept(noexcept(lhs.swap(rhs)));

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
				using reference = typename std::tuple<E &>;
				using const_reference = typename std::tuple<const E &>;
				using pointer = typename std::vector<E>::pointer;
				using const_pointer = typename std::vector<E>::const_pointer;
				using iterator = typename std::vector<E>::iterator;
				using const_iterator = typename std::vector<E>::const_iterator;
				using reverse_iterator = typename std::vector<E>::reverse_iterator;
				using const_reverse_iterator = typename std::vector<E>::const_reverse_iterator;

				SoA() noexcept;
				explicit SoA(const allocator_type & alloc) noexcept;
				SoA(size_type count, const E & first);
				explicit SoA(size_type count, const allocator_type & alloc = allocator_type());
				template <class InputIt> inline SoA(InputIt first, InputIt last, const allocator_type & alloc = allocator_type());
				SoA(const SoA<E> & other);
				SoA(const SoA<E> & other, const allocator_type & alloc);
				SoA(SoA<E> && other) noexcept;
				SoA(SoA<E> && other, const allocator_type & alloc);
				SoA(std::initializer_list<E> init, const allocator_type & alloc = allocator_type());

				~SoA() noexcept;

				SoA<E> & operator=(const SoA<E> & rhs);
				SoA<E> & operator=(SoA<E> && rhs) noexcept;
				SoA<E> & operator=(std::initializer_list<E> ilist);

				void assign(size_type count, const E & first);
				template <class InputIt> void assign(InputIt first, InputIt last);
				void assign(std::initializer_list<E> ilist);
				auto get_allocator() const;

				auto at(size_type index) -> reference;
				auto at(size_type index) const -> const_reference;

				auto operator[](size_type index) -> reference;
				auto operator[](size_type index) const -> const_reference;

				auto front() -> reference;
				auto front() const -> const_reference;

				auto back() -> reference;
				auto back() const -> const_reference;

				auto data() noexcept -> pointer;
				auto data() const noexcept -> const_pointer;

				auto begin() noexcept -> iterator;
				auto begin() const noexcept->const_iterator;
				auto cbegin() const noexcept->const_iterator;

				auto end() noexcept -> iterator;
				auto end() const noexcept -> const_iterator;
				auto cend() const noexcept -> const_iterator;

				auto rbegin() noexcept -> reverse_iterator;
				auto rbegin() const noexcept -> const_reverse_iterator;
				auto crbegin() const noexcept -> const_reverse_iterator;

				auto rend() noexcept -> reverse_iterator;
				auto rend() const noexcept -> const_reverse_iterator;
				auto crend() const noexcept -> const_reverse_iterator;

				bool empty() const noexcept;
				size_type size() const noexcept;
				size_type max_size() const noexcept;
				void reserve(size_type new_cap);
				size_type capacity() const noexcept;
				void shrink_to_fit();

				void clear() noexcept;
				iterator insert(const_iterator pos, const E & first);
				iterator insert(const_iterator pos, E && first);
				iterator insert(const_iterator pos, size_type count, const E & first);
				template <class InputIt> iterator insert(const_iterator pos, InputIt first, InputIt last);
				iterator insert(const_iterator pos, std::initializer_list<E> ilist);
				iterator emplace(const_iterator pos, E && first);
				iterator erase(const_iterator pos);
				iterator erase(const_iterator first, const_iterator last);
				void push_back(const E & first);
				void push_back(E && first);
				void emplace_back(E && first);
				void pop_back();
				void resize(size_type count);
				void resize(size_type count, const E & first);
				void swap(SoA<E> & other);

				friend bool operator==(const SoA<E> & lhs, const SoA<E> & rhs);
				friend bool operator!=(const SoA<E> & lhs, const SoA<E> & rhs);
				friend bool operator<(const SoA<E> & lhs, const SoA<E> & rhs);
				friend bool operator<=(const SoA<E> & lhs, const SoA<E> & rhs);
				friend bool operator>(const SoA<E> & lhs, const SoA<E> & rhs);
				friend bool operator>=(const SoA<E> & lhs, const SoA<E> & rhs);

				friend void swap(SoA<E> & lhs, SoA<E> & rhs) noexcept(noexcept(lhs.swap(rhs)));

				typename SoA::container & getAll();

			protected:
				container _internal;
			};

			template <class E> bool operator==(const SoA<E> & lhs, const SoA<E> & rhs);
			template <class E> bool operator!=(const SoA<E> & lhs, const SoA<E> & rhs);
			template <class E> bool operator<(const SoA<E> & lhs, const SoA<E> & rhs);
			template <class E> bool operator<=(const SoA<E> & lhs, const SoA<E> & rhs);
			template <class E> bool operator>(const SoA<E> & lhs, const SoA<E> & rhs);
			template <class E> bool operator>=(const SoA<E> & lhs, const SoA<E> & rhs);

			template <class E> void swap(SoA<E> & lhs, SoA<E> & rhs) noexcept(noexcept(lhs.swap(rhs)));
		} // namespace container
	} // namespace utility
} // namespace ece

#include "utility/container/soa.inl"

#endif // SOA_HPP