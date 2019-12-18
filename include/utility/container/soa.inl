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

namespace ece
{
	namespace utility
	{
		namespace container
		{
			template <class First, class... Args>
			SoA<First, Args...>::SoA() noexcept(noexcept(SoA<First, Args...>::allocator_type());

			template <class First, class... Args>
			SoA<First, Args...>::SoA(const SoA<First, Args...>::allocator_type & alloc) noexcept;
			
			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...>::size_type count, const First & first, Args &&... args);

			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...>::size_type count, const SoA<First, Args...>::allocator_type & alloc = SoA<First, Args...>::allocator_type());
			
			template <class First, class... Args>
			template <class InputIt>
			SoA<First, Args...>::SoA(InputIt first, InputIt last, const SoA<First, Args...>::allocator_type & alloc = SoA<First, Args...>::allocator_type());
			
			template <class First, class... Args>
			SoA<First, Args...>::SoA(const SoA<First, Args...> & other);
			
			template <class First, class... Args>
			SoA<First, Args...>::SoA(const SoA<First, Args...> & other, const SoA<First, Args...>::allocator_type & alloc);
		
			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...> && other) noexcept;
		
			template <class First, class... Args>
			SoA<First, Args...>::SoA(SoA<First, Args...> && other, const SoA<First, Args...>::allocator_type & alloc);
		
			template <class First, class... Args>
			SoA<First, Args...>::SoA(std::initializer_list<std::tuple<First, Args...>> init, const SoA<First, Args...>::allocator_type & alloc = SoA<First, Args...>::allocator_type());

			template <class First, class... Args>
			SoA<First, Args...>::~SoA() noexcept;

			template <class First, class... Args>
			SoA<First, Args...> & SoA<First, Args...>::operator=(const SoA<First, Args...> & rhs);

			template <class First, class... Args>
			SoA<First, Args...> & SoA<First, Args...>::operator=(SoA<First, Args...> && rhs) noexcept(std::allocator_traits<allocator_type>::propagate_on_container_move_assignment::value || std::allocator_traits<allocator_type>::is_always_equal::value);

			template <class First, class... Args>
			SoA<First, Args...> & SoA<First, Args...>::operator=(std::initializer_list<std::tuple<First, Args...>> ilist);

			template <class First, class... Args>
			void SoA<First, Args...>::assign(size_type count, const First & first, Args &&... args)
			{
				this->_internal.assign(count, first);
				SoA<Args...>::assign(count, args...);
			}

			template <class First, class... Args>
			template <class InputIt, class... InputArgs>
			void SoA<First, Args...>::assign(std::tuple<InputIt, InputArgs...> first, InputIt last);

			template <class First, class... Args>
			void SoA<First, Args...>::assign(std::initializer_list<std::tuple<First, Args...>> ilist);

			template <class First, class... Args>
			auto SoA<First, Args...>::get_allocator() const
			{
				return std::tuple_cat(std::make_tuple(this->_internal.get_allocator()), SoA<Args...>::get_allocator());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::at(SoA<First, Args...>::size_type index) -> std::tuple<First &, Args & ...>;

			template <class First, class... Args>
			auto SoA<First, Args...>::at(SoA<First, Args...>::size_type index) const -> std::tuple<const First, const Args & ...>
			{
				return std::tuple_cat(std::tie(this->_internal.at(index)), SoA<Args...>::at(index));
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::operator[](SoA<First, Args...>::size_type index) -> std::tuple<First &, Args & ...>;

			template <class First, class... Args>
			auto SoA<First, Args...>::operator[](SoA<First, Args...>::size_type index) const -> std::tuple<const First &, const Args & ...>
			{
				return std::tuple_cat(std::tie(this->_internal[index]), SoA<Args...>::operator[](index));
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::front()
			{
				return std::tuple_cat(std::tie(this->_internal.front()), SoA<Args...>::front());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::front() const
			{
				return std::tuple_cat(std::make_tuple(this->_internal.front()), SoA<Args...>::front());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::back()
			{
				return std::tuple_cat(std::tie(this->_internal.back()), SoA<Args...>::back());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::back() const
			{
				return std::tuple_cat(std::make_tuple(this->_internal.back()), SoA<Args...>::back());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::data() noexcept
			{
				return std::tuple_cat(std::tie(this->_internal.data()), SoA<Args...>::data());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::data() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.data()), SoA<Args...>::data());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::begin() noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.begin()), SoA<Args...>::begin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::begin() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.begin()), SoA<Args...>::begin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::cbegin() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.cbegin()), SoA<Args...>::cbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::end() noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.end()), SoA<Args...>::end());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::end() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.end()), SoA<Args...>::end());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::cend() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.cend()), SoA<Args...>::cend());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rbegin() noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rbegin()), SoA<Args...>::rbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rbegin() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rbegin()), SoA<Args...>::rbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::crbegin() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.crbegin()), SoA<Args...>::crbegin());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rend() noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rend()), SoA<Args...>::rend());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::rend() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.rend()), SoA<Args...>::rend());
			}

			template <class First, class... Args>
			auto SoA<First, Args...>::crend() const noexcept
			{
				return std::tuple_cat(std::make_tuple(this->_internal.crend()), SoA<Args...>::crend());
			}

			template <class First, class... Args>
			bool SoA<First, Args...>::empty() const noexcept { return this->_internal.empty(); }

			template <class First, class... Args>
			SoA<First, Args...>::size_type SoA<First, Args...>::size() const noexcept { return this->_internal.size(); }

			template <class First, class... Args>
			SoA<First, Args...>::size_type SoA<First, Args...>::max_size() const noexcept { return this->_internal.max_size(); }

			template <class First, class... Args>
			void SoA<First, Args...>::reserve(size_type new_cap)
			{
				this->_internal.reserve(new_cap);
				SoA<Args...>::reserve(new_cap);
			}

			template <class First, class... Args>
			SoA<First, Args...>::size_type SoA<First, Args...>::capacity() const noexcept { return this->_internal.capacity(); }

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
		} // namespace container
	} // namespace utility
} // namespace ece