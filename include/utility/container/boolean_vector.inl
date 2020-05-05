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
			inline BooleanVector::BooleanVector() noexcept(noexcept(BooleanVector::allocator_type())) : _internal() {}

			inline BooleanVector::BooleanVector(const BooleanVector::allocator_type & alloc) noexcept : _internal(alloc) {}

			inline BooleanVector::BooleanVector(BooleanVector::size_type count, const bool & value, const BooleanVector::allocator_type & alloc) :
				_internal(count, static_cast<char>(value), alloc) {}

			inline BooleanVector::BooleanVector(BooleanVector::size_type count, const BooleanVector::allocator_type & alloc) : _internal(count, alloc) {}

			template <class InputIt>
			inline BooleanVector::BooleanVector(InputIt first, InputIt last, const allocator_type & alloc) : _internal(first, last, alloc) {}

			inline BooleanVector::BooleanVector(const BooleanVector & other) : _internal(other._internal) {}

			inline BooleanVector::BooleanVector(const BooleanVector & other, const BooleanVector::allocator_type & alloc) : _internal(other._internal, alloc) {}

			inline BooleanVector::BooleanVector(BooleanVector && other) noexcept : _internal(std::move(other._internal)) {}

			inline BooleanVector::BooleanVector(BooleanVector && other, const BooleanVector::allocator_type & alloc) : _internal(std::move(other._internal), alloc) {}

			inline BooleanVector::BooleanVector(std::initializer_list<bool> init, const BooleanVector::allocator_type & alloc) : _internal(init.size(), alloc)
			{
				for (auto & elem : init) {
					this->_internal.push_back(static_cast<char>(elem));
				}
			}

			inline BooleanVector::~BooleanVector()
			{
			}

			inline BooleanVector & BooleanVector::operator=(const BooleanVector & other)
			{
				if (*this != other) {
					this->_internal = other._internal;
				}
				return *this;
			}

			inline BooleanVector & BooleanVector::operator=(BooleanVector && other) noexcept(std::allocator_traits<BooleanVector::allocator_type>::propagate_on_container_move_assignment::value || std::allocator_traits<BooleanVector::allocator_type>::is_always_equal::value)
			{
				if (*this != other) {
					this->_internal = std::move(other._internal);
				}
				return *this;
			}

			inline BooleanVector & BooleanVector::operator=(std::initializer_list<bool> ilist)
			{
				this->_internal.clear();
				this->_internal.resize(ilist.size());
				int i = 0;
				for (auto & elem : ilist) {
					this->_internal[0] = static_cast<char>(elem);
					i++;
				}
			}

			inline void BooleanVector::assign(BooleanVector::size_type count, const bool & value)
			{
				this->_internal.assign(count, value);
			}

			template <class InputIt>
			inline void BooleanVector::assign(InputIt first, InputIt last)
			{
				this->_internal.assign(first, last);
			}

			inline void BooleanVector::assign(std::initializer_list<bool> ilist)
			{
				this->_internal.clear();
				this->_internal.resize(ilist.size());
				int i = 0;
				for (auto & elem : ilist) {
					this->_internal[0] = static_cast<char>(elem);
					i++;
				}
			}

			inline BooleanVector::allocator_type BooleanVector::get_allocator() const
			{
				return this->_internal.get_allocator();
			}

			inline BooleanVector::reference BooleanVector::at(BooleanVector::size_type pos)
			{
				return reinterpret_cast<BooleanVector::reference>(this->_internal.at(pos));
			}

			inline BooleanVector::const_reference BooleanVector::at(BooleanVector::size_type pos) const
			{
				return static_cast<BooleanVector::const_reference>(this->_internal.at(pos));
			}

			inline BooleanVector::reference BooleanVector::operator[](BooleanVector::size_type pos)
			{
				return reinterpret_cast<BooleanVector::reference>(this->_internal[pos]);
			}

			inline BooleanVector::const_reference BooleanVector::operator[](BooleanVector::size_type pos) const
			{
				return static_cast<BooleanVector::const_reference>(this->_internal[pos]);
			}

			inline BooleanVector::reference BooleanVector::front()
			{
				return reinterpret_cast<BooleanVector::reference>(this->_internal.front());
			}

			inline BooleanVector::const_reference BooleanVector::front() const
			{
				return static_cast<BooleanVector::const_reference>(this->_internal.front());
			}

			inline BooleanVector::reference BooleanVector::back()
			{
				return reinterpret_cast<BooleanVector::reference>(this->_internal.back());
			}

			inline BooleanVector::const_reference BooleanVector::back() const
			{
				return static_cast<BooleanVector::const_reference>(this->_internal.back());
			}

			inline bool* BooleanVector::data() noexcept
			{
				return reinterpret_cast<bool *>(this->_internal.data());
			}

			inline const bool* BooleanVector::data() const noexcept
			{
				return reinterpret_cast<const bool *>(this->_internal.data());
			}

			inline BooleanVector::iterator BooleanVector::begin() noexcept
			{
				return this->_internal.begin();
			}

			inline BooleanVector::const_iterator BooleanVector::begin() const noexcept
			{
				return this->_internal.begin();
			}

			inline BooleanVector::const_iterator BooleanVector::cbegin() const noexcept
			{
				return this->_internal.cbegin();
			}

			inline BooleanVector::iterator BooleanVector::end() noexcept
			{
				return this->_internal.end();
			}

			inline BooleanVector::const_iterator BooleanVector::end() const noexcept
			{
				return this->_internal.end();
			}

			inline BooleanVector::const_iterator BooleanVector::cend() const noexcept
			{
				return this->_internal.cend();
			}

			inline BooleanVector::reverse_iterator BooleanVector::rbegin() noexcept
			{
				return this->_internal.rbegin();
			}

			inline BooleanVector::const_reverse_iterator BooleanVector::rbegin() const noexcept
			{
				return this->_internal.rbegin();
			}

			inline BooleanVector::const_reverse_iterator BooleanVector::crbegin() const noexcept
			{
				return this->_internal.crbegin();
			}

			inline BooleanVector::reverse_iterator BooleanVector::rend() noexcept
			{
				return this->_internal.rend();
			}

			inline BooleanVector::const_reverse_iterator BooleanVector::rend() const noexcept
			{
				return this->_internal.rend();
			}

			inline BooleanVector::const_reverse_iterator BooleanVector::crend() const noexcept
			{
				return this->_internal.crend();
			}

			inline bool BooleanVector::empty() const noexcept
			{
				return this->_internal.empty();
			}

			inline BooleanVector::size_type BooleanVector::size() const noexcept
			{
				return this->_internal.size();
			}

			inline BooleanVector::size_type BooleanVector::max_size() const noexcept
			{
				return this->_internal.max_size();
			}

			inline void BooleanVector::reserve(BooleanVector::size_type new_cap)
			{
				this->_internal.resize(new_cap);
			}

			inline BooleanVector::size_type BooleanVector::capacity() const noexcept
			{
				return this->_internal.capacity();
			}

			inline void BooleanVector::shrink_to_fit()
			{
				return this->_internal.shrink_to_fit();
			}

			inline void BooleanVector::clear() noexcept
			{
				this->_internal.clear();
			}

			inline BooleanVector::iterator BooleanVector::insert(BooleanVector::const_iterator pos, const bool & value)
			{
				this->_internal.insert(pos, static_cast<char>(value));
			}

			inline BooleanVector::iterator BooleanVector::insert(BooleanVector::const_iterator pos, bool && value)
			{
				this->_internal.insert(pos, static_cast<char>(std::move(value)));
			}

			inline BooleanVector::iterator BooleanVector::insert(BooleanVector::const_iterator pos, BooleanVector::size_type count, const bool & value)
			{
				this->_internal.insert(pos, count, static_cast<char>(value));
			}

			template <class InputIt> inline BooleanVector::iterator BooleanVector::insert(BooleanVector::const_iterator pos, InputIt first, InputIt last)
			{
				this->_internal.insert(pos, first, last);
			}

			inline BooleanVector::iterator BooleanVector::insert(BooleanVector::const_iterator pos, std::initializer_list<bool> ilist)
			{
				auto loc = pos;
				for (auto & elem : ilist) {
					loc = this->_internal.insert(pos, elem);
				}
				return this->begin() + (this->end() - loc);
			}

			template <class... Args> BooleanVector::iterator BooleanVector::emplace(BooleanVector::const_iterator pos, Args&&... args)
			{
				return this->_internal.emplace(pos, std::forward(args)...);
			}

			inline BooleanVector::iterator BooleanVector::erase(BooleanVector::const_iterator pos)
			{
				return this->_internal.erase(pos);
			}

			inline BooleanVector::iterator BooleanVector::erase(BooleanVector::const_iterator first, BooleanVector::const_iterator last)
			{
				return this->_internal.erase(first, last);
			}

			inline void BooleanVector::push_back(const bool & value)
			{
				this->_internal.push_back(static_cast<char>(value));
			}

			inline void BooleanVector::push_back(bool && value)
			{
				this->_internal.push_back(static_cast<char>(std::move(value)));
			}

			template <class... Args>
			inline BooleanVector::reference BooleanVector::emplace_back(Args&&... args)
			{
				return this->_internal.emplace_back(std::forward(args)...);
			}

			inline void BooleanVector::pop_back()
			{
				this->_internal.pop_back();
			}

			inline void BooleanVector::resize(BooleanVector::size_type count)
			{
				this->_internal.resize(count);
			}

			inline void BooleanVector::resize(BooleanVector::size_type count, const BooleanVector::value_type & value)
			{
				this->_internal.resize(count, static_cast<char>(value));
			}

			inline void BooleanVector::swap(BooleanVector & other) noexcept(std::allocator_traits<BooleanVector::allocator_type>::propagate_on_container_swap::value || std::allocator_traits<BooleanVector::allocator_type>::is_always_equal::value)
			{
				this->_internal.swap(other._internal);
			}

			inline bool operator==(const BooleanVector & lhs, const BooleanVector & rhs)
			{
				return lhs._internal == rhs._internal;
			}

			inline bool operator!=(const BooleanVector & lhs, const BooleanVector & rhs)
			{
				return lhs._internal != rhs._internal;
			}

			inline bool operator<(const BooleanVector & lhs, const BooleanVector & rhs)
			{
				return lhs._internal < rhs._internal;
			}

			inline bool operator<=(const BooleanVector & lhs, const BooleanVector & rhs)
			{
				return lhs._internal <= rhs._internal;
			}

			inline bool operator>(const BooleanVector & lhs, const BooleanVector & rhs)
			{
				return lhs._internal > rhs._internal;
			}

			inline bool operator>=(const BooleanVector & lhs, const BooleanVector & rhs)
			{
				return lhs._internal >= rhs._internal;
			}

			inline void swap(BooleanVector & lhs, BooleanVector & rhs) noexcept(noexcept(lhs.swap(rhs)))
			{
				std::swap(lhs._internal, rhs._internal);
			}
		} // namespace container
	} // namespace utility
} // namespace ece