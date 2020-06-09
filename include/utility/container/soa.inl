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

#include "utility/container/tuple_trait.hpp"

namespace ece
{
	namespace utility
	{
		namespace container
		{
			template <class First, class... Args>
			SoA<First, Args...>::SoA() noexcept : SoA<Args...>(), _internal()
			{
			}

			template <class First, class... Args>
			SoA<First, Args...>::SoA(const SoA<First, Args...>::allocator_type & alloc) noexcept : SoA<Args...>(unshift(alloc)), _internal(std::get<0>(alloc))
			{
			}

			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...>::size_type count, const First & first, Args &&... args) : SoA<Args...>(count, args...), _internal(count, first)
			{
			}

			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...>::size_type count, const SoA<First, Args...>::allocator_type & alloc) : SoA<Args...>(count, unshift(alloc)), _internal(count, std::get<0>(alloc))
			{
			}
			
			template <class First, class... Args>
			template <class InputIt>
			SoA<First, Args...>::SoA(InputIt first, InputIt last, const SoA<First, Args...>::allocator_type & alloc) : SoA<Args...>(unshift(first), unshift(last), unshift(alloc)), _internal(std::get<0>(first), std::get<0>(last), std::get<0>(alloc))
			{
			}

			template <class First, class... Args>
			SoA<First, Args...>::SoA(const SoA<First, Args...> & other) : SoA<Args...>(other), _internal(other._internal)
			{
			}
			
			template <class First, class... Args>
			SoA<First, Args...>::SoA(const SoA<First, Args...> & other, const SoA<First, Args...>::allocator_type & alloc) : SoA<Args...>(other, unshift(alloc)), _internal(other._internal, std::get<0>(alloc))
			{
			}

			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...> && other) noexcept : SoA<Args...>(other), _internal(std::move(other._internal))
			{
			}
		
			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...> && other, const SoA<First, Args...>::allocator_type & alloc) : SoA<Args...>(other, unshift(alloc)), _internal(std::move(other._internal), std::get<0>(alloc))
			{
			}
		
			template <class First, class... Args>
			SoA<First, Args...>::SoA(std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> init, const SoA<First, Args...>::allocator_type & alloc) : SoA<Args...>(unshift(init), unshift(alloc)), _internal(std::get<0>(init), std::get<0>(alloc))
			{
			}

			template <class First, class... Args>
			SoA<First, Args...>::~SoA() noexcept
			{
			}

			template <class First, class... Args>
			SoA<First, Args...> & SoA<First, Args...>::operator=(const SoA<First, Args...> & rhs)
			{
				if (this != &rhs) {
					this->_internal = rhs._internal;
					SoA<Args...>::operator=(rhs);
				}
				return *this;
			}

			template <class First, class... Args>
			SoA<First, Args...> & SoA<First, Args...>::operator=(SoA<First, Args...> && rhs) noexcept
			{
				if (this != &rhs) {
					this->_internal = std::move(rhs._internal);
					SoA<Args...>::operator=(std::move(rhs));
				}
				return *this;
			}


			template <class First, class... Args>
			SoA<First, Args...> & SoA<First, Args...>::operator=(std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> ilist)
			{
				if (this != &rhs) {
					this->_internal = std::get<0>(ilist);
					SoA<Args...>::operator=(unshift(ilist));
				}
				return *this;
			}

			template <class First, class... Args>
			void SoA<First, Args...>::assign(size_type count, const First & first, Args &&... args)
			{
				this->_internal.assign(count, first);
				SoA<Args...>::assign(count, args...);
			}

			template <class First, class... Args>
			template <class InputIt>
			void SoA<First, Args...>::assign(InputIt first, InputIt last)
			{
				this->_internal.assign(std::get<0>(first), std::get<0>(last));
				SoA<Args...>::assign(unshift(first), unshift(last));
			}

			template <class First, class... Args>
			void SoA<First, Args...>::assign(std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> ilist)
			{
				this->_internal.assign(std::get<0>(ilist));
				SoA<Args...>::assign(unshift(ilist));
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::get_allocator() const
			{
				return std::tuple_cat(std::make_tuple(this->_internal.get_allocator()), SoA<Args...>::get_allocator());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::at(SoA<First, Args...>::size_type index) -> std::tuple<First &, Args & ...>
			{
				return std::tuple_cat(std::tie(this->_internal.at(index)), SoA<Args...>::at(index));
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::at(SoA<First, Args...>::size_type index) const -> std::tuple<const First &, const Args & ...>
			{
				return std::tuple_cat(std::tie(this->_internal.at(index)), SoA<Args...>::at(index));
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::operator[](SoA<First, Args...>::size_type index) -> std::tuple<First &, Args & ...>
			{
				return std::tuple_cat(std::tie(this->_internal[index]), SoA<Args...>::operator[](index));
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::operator[](SoA<First, Args...>::size_type index) const -> std::tuple<const First &, const Args & ...>
			{
				return std::tuple_cat(std::tie(this->_internal[index]), SoA<Args...>::operator[](index));
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::front() -> reference
			{
				return std::tuple_cat(std::tie(this->_internal.front()), SoA<Args...>::front());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::front() const -> const_reference
			{
				return std::tuple_cat(std::make_tuple(this->_internal.front()), SoA<Args...>::front());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::back() -> reference
			{
				return std::tuple_cat(std::tie(this->_internal.back()), SoA<Args...>::back());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::back() const -> const_reference
			{
				return std::tuple_cat(std::make_tuple(this->_internal.back()), SoA<Args...>::back());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::data() noexcept -> pointer
			{
				return std::tuple_cat(std::tie(this->_internal.data()), SoA<Args...>::data());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::data() const noexcept -> const_pointer
			{
				return std::tuple_cat(std::make_tuple(this->_internal.data()), SoA<Args...>::data());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::begin() noexcept -> iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.begin()), SoA<Args...>::begin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::begin() const noexcept -> const_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.begin()), SoA<Args...>::begin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::cbegin() const noexcept -> const_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.cbegin()), SoA<Args...>::cbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::end() noexcept -> iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.end()), SoA<Args...>::end());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::end() const noexcept -> const_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.end()), SoA<Args...>::end());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::cend() const noexcept -> const_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.cend()), SoA<Args...>::cend());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rbegin() noexcept -> reverse_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rbegin()), SoA<Args...>::rbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rbegin() const noexcept -> const_reverse_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rbegin()), SoA<Args...>::rbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::crbegin() const noexcept -> const_reverse_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.crbegin()), SoA<Args...>::crbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rend() noexcept -> reverse_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rend()), SoA<Args...>::rend());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rend() const noexcept -> const_reverse_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rend()), SoA<Args...>::rend());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::crend() const noexcept -> const_reverse_iterator
			{
				return std::tuple_cat(std::make_tuple(this->_internal.crend()), SoA<Args...>::crend());
			}

			template <class First, class... Args>
			bool SoA<First, Args...>::empty() const noexcept
			{
				return this->_internal.empty();
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::size_type SoA<First, Args...>::size() const noexcept
			{
				return this->_internal.size();
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::size_type SoA<First, Args...>::max_size() const noexcept
			{
				return this->_internal.max_size();
			}

			template <class First, class... Args>
			void SoA<First, Args...>::reserve(size_type new_cap)
			{
				this->_internal.reserve(new_cap);
				SoA<Args...>::reserve(new_cap);
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::size_type SoA<First, Args...>::capacity() const noexcept
			{
				return this->_internal.capacity();
			}

			template <class First, class... Args>
			void SoA<First, Args...>::shrink_to_fit()
			{
				this->_internal.shrink_to_fit();
				SoA<Args...>::shrink_to_fit();
			}

			template <class First, class... Args>
			void SoA<First, Args...>::clear() noexcept
			{
				this->_internal.clear();
				SoA<Args...>::clear();
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::insert(SoA<First, Args...>::const_iterator pos, const First & first, Args && ... args)
			{
				return std::tuple_cat(this->_internal.insert(std::get<0>(pos), first), SoA<Args...>::insert(unshift(pos), std::forward(args)...));
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::insert(SoA<First, Args...>::const_iterator pos, First && first, Args && ... args)
			{
				return std::tuple_cat(this->_internal.insert(std::get<0>(pos), std::move(first)), SoA<Args...>::insert(unshift(pos), std::forward(args)...));
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::insert(SoA<First, Args...>::const_iterator pos, SoA<First, Args...>::size_type count, const First & first, Args && ... args)
			{
				return std::tuple_cat(this->_internal.insert(std::get<0>(pos), count, first), SoA<Args...>::insert(unshift(pos), count, std::forward(args)...));
			}

			template <class First, class... Args>
			template <class InputIt>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::insert(SoA<First, Args...>::const_iterator pos, InputIt first, InputIt last)
			{
				return std::tuple_cat(this->_internal.insert(std::get<0>(pos), std::get<0>(first), std::get<0>(last)), SoA<Args...>::insert(unshift(pos), unshift(first), unshift(last)));
			}
			
			template <class First, class... Args>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::insert(SoA<First, Args...>::const_iterator pos, std::tuple<std::initializer_list<First>, std::initializer_list<Args>...> ilist)
			{
				return std::tuple_cat(this->_internal.insert(std::get<0>(pos), std::get<0>(ilist)), SoA<Args...>::insert(unshift(pos), unshift(ilist)));
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::emplace(SoA<First, Args...>::const_iterator pos, First && first, Args&&... args)
			{
				return std::tuple_cat(this->_internal.emplace(std::get<0>(pos), std::move(first)), SoA<Args>::emplace(unshift(pos), std::forward(args)...));
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::erase(SoA<First, Args...>::const_iterator pos)
			{
				return std::tuple_cat(this->_internal.erase(std::get<0>(pos)), SoA<Args...>::erase(unshift(pos)));
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::iterator SoA<First, Args...>::erase(SoA<First, Args...>::const_iterator first, SoA<First, Args...>::const_iterator last)
			{
				return std::tuple_cat(this->_internal.erase(std::get<0>(first), std::get<0>(last)), SoA<Args...>::erase(unshift(first), unshift(last)));
			}

			template <class First, class... Args>
			void SoA<First, Args...>::push_back(const First & first, Args &&... args)
			{
				this->_internal.push_back(first);
				SoA<Args...>::push_back(std::forward<Args>(args)...);
			}

			template <class First, class... Args>
			void SoA<First, Args...>::push_back(First && first, Args &&... args)
			{
				this->_internal.push_back(std::move(first));
				SoA<Args...>::push_back(std::forward<Args>(args)...);
			}

			template <class First, class... Args>
			void SoA<First, Args...>::emplace_back(First && first, Args &&... args)
			{
				this->_internal.emplace_back(std::move(first));
				SoA<Args...>::emplace_back(std::forward<Args>(args)...);
			}

			template <class First, class... Args>
			void SoA<First, Args...>::pop_back()
			{
				this->_internal.pop_back();
				SoA<Args...>::pop_back();
			}

			template <class First, class... Args>
			void SoA<First, Args...>::resize(SoA<First, Args...>::size_type count)
			{
				this->_internal.resize(count);
				SoA<Args...>::resize(count);
			}

			template <class First, class... Args>
			void SoA<First, Args...>::resize(SoA<First, Args...>::size_type count, const First & first, Args &&... args)
			{
				this->_internal.resize(count, first);
				SoA<Args...>::resize(count, args...);
			}

			template <class First, class... Args>
			void SoA<First, Args...>::swap(SoA<First, Args...> & other)
			{
				this->_internal.swap(other.getAll());
				SoA<Args...>::swap(other);
			}

			template <class First, class... Args>
			bool operator==(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs)
			{
				return lhs._internal == rhs._internal && operator==<Args...>(lhs, rhs);
			}
			
			template <class First, class... Args>
			bool operator!=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs)
			{
				return lhs._internal != rhs._internal && operator!=<Args...>(lhs, rhs);
			}
			
			template <class First, class... Args>
			bool operator<(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs)
			{
				return lhs._internal < rhs._internal && operator< <Args...>(lhs, rhs);
			}
			
			template <class First, class... Args>
			bool operator<=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs)
			{
				return lhs._internal <= rhs._internal && operator<=<Args...>(lhs, rhs);
			}
			
			template <class First, class... Args>
			bool operator>(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs)
			{
				return lhs._internal > rhs._internal && operator><Args...>(lhs, rhs);
			}
			
			template <class First, class... Args>
			bool operator>=(const SoA<First, Args...> & lhs, const SoA<First, Args...> & rhs)
			{
				return lhs._internal >= rhs._internal && operator>=<Args...>(lhs, rhs);
			}

			template <class First, class... Args> 
			void swap(SoA<First, Args...> & lhs, SoA<First, Args...> & rhs) noexcept(noexcept(lhs.swap(rhs)))
			{
				swap(lhs._internal, rhs._internal);
				swap<Args...>(lhs, rhs);
			}

			template <class First, class... Args>
			typename SoA<First, Args...>::container & SoA<First, Args...>::getAll()
			{
				return this->_internal;
			}




















			template <class E>
			SoA<E>::SoA() noexcept : _internal()
			{
			}

			template <class E>
			SoA<E>::SoA(const SoA<E>::allocator_type & alloc) noexcept : _internal(alloc)
			{
			}

			template <class E>
			SoA<E>::SoA(SoA<E>::size_type count, const E & first) : _internal(count, first)
			{
			}

			template <class E>
			SoA<E>::SoA(SoA<E>::size_type count, const SoA<E>::allocator_type & alloc) : _internal(count, alloc)
			{
			}

			template <class E>
			template <class InputIt>
			SoA<E>::SoA(InputIt first, InputIt last, const SoA<E>::allocator_type & alloc) : _internal(first, last, alloc)
			{
			}

			template <class E>
			SoA<E>::SoA(const SoA<E> & other) : _internal(other._internal)
			{
			}

			template <class E>
			SoA<E>::SoA(const SoA<E> & other, const SoA<E>::allocator_type & alloc) : _internal(other._internal, alloc)
			{
			}

			template <class E>
			SoA<E>::SoA(SoA<E> && other) noexcept : _internal(std::move(other._internal))
			{
			}

			template <class E>
			SoA<E>::SoA(SoA<E> && other, const SoA<E>::allocator_type & alloc) : _internal(std::move(other._internal), alloc)
			{
			}

			template <class E>
			SoA<E>::SoA(std::initializer_list<E> init, const SoA<E>::allocator_type & alloc) : _internal(init, alloc)
			{
			}

			template <class E>
			SoA<E>::~SoA() noexcept
			{
			}

			template <class E>
			SoA<E> & SoA<E>::operator=(const SoA<E> & rhs)
			{
				if (this != &rhs) {
					this->_internal = rhs._internal;
				}
				return *this;
			}

			template <class E>
			SoA<E> & SoA<E>::operator=(SoA<E> && rhs) noexcept
			{
				if (this != &rhs) {
					this->_internal = std::move(rhs._internal);
				}
				return *this;
			}

			template <class E>
			SoA<E> & SoA<E>::operator=(std::initializer_list<E> ilist)
			{
				if (this != &rhs) {
					this->_internal = ilist;
				}
				return *this;
			}

			template <class E>
			void SoA<E>::assign(size_type count, const E & first)
			{
				this->_internal.assign(count, first);
				SoA<Args...>::assign(count, args...);
			}

			template <class E>
			template <class InputIt>
			void SoA<E>::assign(InputIt first, InputIt last)
			{
				this->_internal.assign(first, last);
			}

			template <class E>
			void SoA<E>::assign(std::initializer_list<E> ilist)
			{
				this->_internal.assign(ilist);
			}

			template <class E>
			auto SoA<E>::get_allocator() const
			{
				return std::make_tuple(this->_internal.get_allocator());
			}

			template <class E>
			auto SoA<E>::at(SoA<E>::size_type index) -> reference
			{
				return std::make_tuple(this->_internal.at(index));
			}

			template <class E>
			auto SoA<E>::at(SoA<E>::size_type index) const -> const_reference
			{
				return std::make_tuple(this->_internal.at(index));
			}

			template <class E>
			auto SoA<E>::operator[](SoA<E>::size_type index) -> reference
			{
				return std::tie(this->_internal[index]);
			}

			template <class E>
			auto SoA<E>::operator[](SoA<E>::size_type index) const -> const_reference
			{
				return std::make_tuple(this->_internal[index]);
			}

			template <class E>
			auto SoA<E>::front() -> reference
			{
				return std::tie(this->_internal.front());
			}

			template <class E>
			auto SoA<E>::front() const -> const_reference
			{
				return std::make_tuple(this->_internal.front());
			}

			template <class E>
			auto SoA<E>::back() -> reference
			{
				return std::tie(this->_internal.back());
			}

			template <class E>
			auto SoA<E>::back() const -> const_reference
			{
				return std::make_tuple(this->_internal.back());
			}

			template <class E>
			auto SoA<E>::data() noexcept -> pointer
			{
				return std::make_tuple(this->_internal.data());
			}

			template <class E>
			auto SoA<E>::data() const noexcept -> const_pointer
			{
				return std::make_tuple(this->_internal.data());
			}

			template <class E>
			auto SoA<E>::begin() noexcept -> iterator
			{
				return std::make_tuple(this->_internal.begin());
			}

			template <class E>
			auto SoA<E>::begin() const noexcept -> const_iterator
			{
				return std::make_tuple(this->_internal.begin());
			}

			template <class E>
			auto SoA<E>::cbegin() const noexcept -> const_iterator
			{
				return std::make_tuple(this->_internal.cbegin());
			}

			template <class E>
			auto SoA<E>::end() noexcept -> iterator
			{
				return std::make_tuple(this->_internal.end());
			}

			template <class E>
			auto SoA<E>::end() const noexcept -> const_iterator
			{
				return std::make_tuple(this->_internal.end());
			}

			template <class E>
			auto SoA<E>::cend() const noexcept -> const_iterator
			{
				return std::make_tuple(this->_internal.cend());
			}

			template <class E>
			auto SoA<E>::rbegin() noexcept -> reverse_iterator
			{
				return std::make_tuple(this->_internal.rbegin());
			}

			template <class E>
			auto SoA<E>::rbegin() const noexcept -> const_reverse_iterator
			{
				return std::make_tuple(this->_internal.rbegin());
			}

			template <class E>
			auto SoA<E>::crbegin() const noexcept -> const_reverse_iterator
			{
				return std::make_tuple(this->_internal.crbegin());
			}

			template <class E>
			auto SoA<E>::rend() noexcept -> reverse_iterator
			{
				return std::make_tuple(this->_internal.rend());
			}

			template <class E>
			auto SoA<E>::rend() const noexcept -> const_reverse_iterator
			{
				return std::make_tuple(this->_internal.rend());
			}

			template <class E>
			auto SoA<E>::crend() const noexcept -> const_reverse_iterator
			{
				return std::make_tuple(this->_internal.crend());
			}

			template <class E>
			bool SoA<E>::empty() const noexcept
			{
				return this->_internal.empty();
			}

			template <class E>
			typename SoA<E>::size_type SoA<E>::size() const noexcept
			{
				return this->_internal.size();
			}

			template <class E>
			typename SoA<E>::size_type SoA<E>::max_size() const noexcept
			{
				return this->_internal.max_size();
			}

			template <class E>
			void SoA<E>::reserve(size_type new_cap)
			{
				this->_internal.reserve(new_cap);
			}

			template <class E>
			typename SoA<E>::size_type SoA<E>::capacity() const noexcept { return this->_internal.capacity(); }

			template <class E>
			void SoA<E>::shrink_to_fit()
			{
				this->_internal.shrink_to_fit();
			}

			template <class E>
			void SoA<E>::clear() noexcept
			{
				this->_internal.clear();
			}

			template <class E>
			typename SoA<E>::iterator SoA<E>::insert(SoA<E>::const_iterator pos, const E & first)
			{
				return this->_internal.insert(pos, first);
			}

			template <class E>
			typename SoA<E>::iterator SoA<E>::insert(SoA<E>::const_iterator pos, E && first)
			{
				return this->_internal.insert(pos, std::move(first));
			}

			template <class E>
			typename SoA<E>::iterator SoA<E>::insert(SoA<E>::const_iterator pos, SoA<E>::size_type count, const E & first)
			{
				return this->_internal.insert(pos, count, first);
			}

			template <class E>
			template <class InputIt>
			typename SoA<E>::iterator SoA<E>::insert(SoA<E>::const_iterator pos, InputIt first, InputIt last)
			{
				return this->_internal.insert(pos, first, last);
			}

			template <class E>
			typename SoA<E>::iterator SoA<E>::insert(SoA<E>::const_iterator pos, std::initializer_list<E> ilist)
			{
				return this->_internal.insert(pos, ilist);
			}

			template <class E>
			typename SoA<E>::iterator SoA<E>::emplace(SoA<E>::const_iterator pos, E && first)
			{
				return this->_internal.emplace(pos, first);
			}

			template <class E>
			typename SoA<E>::iterator SoA<E>::erase(SoA<E>::const_iterator pos)
			{
				return this->_internal.erase(pos);
			}

			template <class E>
			typename SoA<E>::iterator SoA<E>::erase(SoA<E>::const_iterator first, SoA<E>::const_iterator last)
			{
				return this->_internal.erase(first, last);
			}

			template <class E>
			void SoA<E>::push_back(const E & first)
			{
				this->_internal.push_back(first);
			}

			template <class E>
			void SoA<E>::push_back(E && first)
			{
				this->_internal.push_back(std::move(first));
			}

			template <class E>
			void SoA<E>::emplace_back(E && first)
			{
				this->_internal.emplace_back(std::move(first));
			}

			template <class E>
			void SoA<E>::pop_back()
			{
				this->_internal.pop_back();
			}

			template <class E>
			void SoA<E>::resize(SoA<E>::size_type count)
			{
				this->_internal.resize(count);
			}

			template <class E>
			void SoA<E>::resize(SoA<E>::size_type count, const E & first)
			{
				this->_internal.resize(count, first);
			}

			template <class E>
			void SoA<E>::swap(SoA<E> & other)
			{
				this->_internal.swap(other.getAll());
			}

			template <class E>
			bool operator==(const SoA<E> & lhs, const SoA<E> & rhs)
			{
				return lhs._internal == rhs._internal;
			}

			template <class E>
			bool operator!=(const SoA<E> & lhs, const SoA<E> & rhs)
			{
				return lhs._internal != rhs._internal;
			}

			template <class E>
			bool operator<(const SoA<E> & lhs, const SoA<E> & rhs)
			{
				return lhs._internal < rhs._internal;
			}

			template <class E>
			bool operator<=(const SoA<E> & lhs, const SoA<E> & rhs)
			{
				return lhs._internal <= rhs._internal;
			}

			template <class E>
			bool operator>(const SoA<E> & lhs, const SoA<E> & rhs)
			{
				return lhs._internal > rhs._internal;
			}

			template <class E>
			bool operator>=(const SoA<E> & lhs, const SoA<E> & rhs)
			{
				return lhs._internal >= rhs._internal;
			}

			template <class E>
			void swap(SoA<E> & lhs, SoA<E> & rhs) noexcept(noexcept(lhs.swap(rhs)))
			{
				swap(lhs._internal,rhs._internal);
			}

			template <class E>
			typename SoA<E>::container & SoA<E>::getAll()
			{
				return this->_internal;
			}
		} // namespace container
	} // namespace utility
} // namespace ece