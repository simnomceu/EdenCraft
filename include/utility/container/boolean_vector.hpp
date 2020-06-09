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

#ifndef BOOLEAN_VECTOR_HPP
#define BOOLEAN_VECTOR_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace container
		{
			class ECE_UTILITY_API BooleanVector
			{
			public:
				using value_type = bool;
				using allocator_type = std::vector<char>::allocator_type;
				using size_type = std::vector<char>::size_type;
				using difference_type = std::vector<char>::difference_type;
				using reference = value_type &;
				using const_reference = const value_type &;
				using pointer = std::vector<char>::pointer;
				using const_pointer = std::vector<char>::const_pointer;
				using iterator = std::vector<char>::iterator;
				using const_iterator = std::vector<char>::const_iterator;
				using reverse_iterator = std::vector<char>::reverse_iterator;
				using const_reverse_iterator = std::vector<char>::const_reverse_iterator;

				inline BooleanVector() noexcept(noexcept(allocator_type()));
				inline explicit BooleanVector(const allocator_type & alloc) noexcept;
				inline BooleanVector(size_type count, const bool & value, const allocator_type & alloc = allocator_type());
				inline explicit BooleanVector(size_type count, const allocator_type & alloc = allocator_type());
				template <class InputIt> inline BooleanVector(InputIt first, InputIt last, const allocator_type & alloc = allocator_type());
				inline BooleanVector(const BooleanVector & other);
				inline BooleanVector(const BooleanVector & other, const allocator_type & alloc);
				inline BooleanVector(BooleanVector && other) noexcept;
				inline BooleanVector(BooleanVector && other, const allocator_type & alloc);
				inline BooleanVector(std::initializer_list<bool> init, const allocator_type & alloc = allocator_type());

				inline ~BooleanVector();

				inline BooleanVector& operator=(const BooleanVector& other);
				inline BooleanVector& operator=(BooleanVector&& other) noexcept(std::allocator_traits<allocator_type>::propagate_on_container_move_assignment::value || std::allocator_traits<allocator_type>::is_always_equal::value);
				inline BooleanVector& operator=(std::initializer_list<bool> ilist);

				inline void assign(size_type count, const bool & value);
				template <class InputIt> inline void assign(InputIt first, InputIt last);
				inline void assign(std::initializer_list<bool> ilist);
				inline allocator_type get_allocator() const;

				inline reference at(size_type pos);
				inline const_reference at(size_type pos) const;

				inline reference operator[](size_type pos);
				inline const_reference operator[](size_type pos) const;

				inline reference front();
				inline const_reference front() const;

				inline reference back();
				inline const_reference back() const;

				inline bool* data() noexcept;
				inline const bool* data() const noexcept;

				inline iterator begin() noexcept;
				inline const_iterator begin() const noexcept;
				inline const_iterator cbegin() const noexcept;

				inline iterator end() noexcept;
				inline const_iterator end() const noexcept;
				inline const_iterator cend() const noexcept;

				inline reverse_iterator rbegin() noexcept;
				inline const_reverse_iterator rbegin() const noexcept;
				inline const_reverse_iterator crbegin() const noexcept;

				inline reverse_iterator rend() noexcept;
				inline const_reverse_iterator rend() const noexcept;
				inline const_reverse_iterator crend() const noexcept;

				inline bool empty() const noexcept;
				inline size_type size() const noexcept;
				inline size_type max_size() const noexcept;
				inline void reserve(size_type new_cap);
				inline size_type capacity() const noexcept;
				inline void shrink_to_fit();

				inline void clear() noexcept;
				inline iterator insert(const_iterator pos, const bool & value);
				inline iterator insert(const_iterator pos, bool && value);
				inline iterator insert(const_iterator pos, size_type count, const bool & value);
				template <class InputIt> inline iterator insert(const_iterator pos, InputIt first, InputIt last);
				inline iterator insert(const_iterator pos, std::initializer_list<bool> ilist);
				template <class... Args> inline iterator emplace(const_iterator pos, Args&&... args);
				inline iterator erase(const_iterator pos);
				inline iterator erase(const_iterator first, const_iterator last);
				inline void push_back(const bool & value);
				inline void push_back(bool && value);
				template <class... Args> inline reference emplace_back(Args&&... args);
				inline void pop_back();
				inline void resize(size_type count);
				inline void resize(size_type count, const value_type & value);
				inline void swap(BooleanVector & other) noexcept(std::allocator_traits<allocator_type>::propagate_on_container_swap::value || std::allocator_traits<allocator_type>::is_always_equal::value);

				friend inline bool operator==(const BooleanVector & lhs, const BooleanVector & rhs);
				friend inline bool operator!=(const BooleanVector & lhs, const BooleanVector & rhs);
				friend inline bool operator<(const BooleanVector & lhs, const BooleanVector & rhs);
				friend inline bool operator<=(const BooleanVector & lhs, const BooleanVector & rhs);
				friend inline bool operator>(const BooleanVector & lhs, const BooleanVector & rhs);
				friend inline bool operator>=(const BooleanVector & lhs, const BooleanVector & rhs);

				friend void swap(BooleanVector & lhs, BooleanVector & rhs) noexcept;
			private:
				std::vector<char> _internal;
			};

			inline bool operator==(const BooleanVector & lhs, const BooleanVector & rhs);
			inline bool operator!=(const BooleanVector & lhs, const BooleanVector & rhs);
			inline bool operator<(const BooleanVector & lhs, const BooleanVector & rhs);
			inline bool operator<=(const BooleanVector & lhs, const BooleanVector & rhs);
			inline bool operator>(const BooleanVector & lhs, const BooleanVector & rhs);
			inline bool operator>=(const BooleanVector & lhs, const BooleanVector & rhs);

			void swap(BooleanVector & lhs, BooleanVector & rhs) noexcept;
		} // namespace container
	} // namespace utility
} // namespace ece

#include "utility/container/boolean_vector.inl"

#endif // BOOLEAN_VECTOR_HPP