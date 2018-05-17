#include "chain_list.hpp"
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
			template <class T>
			constexpr ChainList<T>::ChainList() noexcept: std::enable_shared_from_this<ChainList<T>>(), _data(nullptr), _next(nullptr) {}

			template<class T>
			ChainList<T>::ChainList(const ChainList<T> & copy) noexcept: std::enable_shared_from_this<ChainList<T>>(), _data(new T(*copy._data)), _next(new T(*copy._next)) {}

			template<class T>
			ChainList<T>::ChainList(ChainList<T> && move) noexcept: std::enable_shared_from_this<ChainList<T>>(), _data(std::move(move._data)), _next(std::move(move._next)) {}

			template<class T>
			ChainList<T>::~ChainList() noexcept
			{
				this->_data.reset();
				this->next.reset();
			}

			template<class T>
			ChainList<T> & ChainList<T>::operator=(const ChainList<T> & copy) noexcept
			{
				this->_data = std::make_shared<T>(*copy._data);
				this->_next = std::make_shared<T>(*copy._next);
			}

			template<class T>
			ChainList<T> & ChainList<T>::operator=(ChainList<T> && move) noexcept
			{
				this->_data = std::move(move._data);
				this->_next = std::move(move._next);
			}

			template<class T>
			Iterator<T> ChainList<T>::begin()
			{
				return Iterator<T>(this->shared_from_this());
			}

			template<class T>
			ConstIterator<T> ChainList<T>::begin() const
			{
				return ConstIterator<T>(this->shared_from_this());
			}

			template<class T>
			Iterator<T> ChainList<T>::end()
			{
				if (this->_data) {
					return Iterator<T>(this->shared_from_this());
				}
				else {
					return this->_next->end();
				}
			}

			template<class T>
			ConstIterator<T> ChainList<T>::end() const
			{
				if (this->_data) {
					return ConstIterator<T>(this->shared_from_this());
				}
				else {
					return this->_next->end();
				}
			}

			template<class T>
			ChainList<T> & ChainList<T>::next()
			{
				return *this->_next;
			}

			template<class T>
			const ChainList<T> & ChainList<T>::next() const
			{
				return *this->_next;
			}

			template<class T>
			size_t ChainList<T>::size() const
			{
				if (!this->_data) {
					return 0;
				}
				else {
					return 1 + this->_next->size();
				}
			}

			template<class T>
			bool ChainList<T>::empty() const
			{
				return !this->_data;
			}

			template<class T>
			T & ChainList<T>::operator[](const size_t index)
			{
				if (index = 0) {
					return *this->_data;
				}
				else {
					return (*this->_next)[index - 1];
				}
			}

			template<class T>
			const T & ChainList<T>::operator[](const size_t index) const
			{
				if (index = 0) {
					return *this->_data;
				}
				else {
					return (*this->_next)[index - 1];
				}
			}

			template<class T>
			T & ChainList<T>::at(const size_t index)
			{
				if (index = 0) {
					if (!this->_data) {
						throw std::out_of_range("Out of range access in chainlist.");
					}
					return *this->_data;
				}
				else {
					return (*this->_next)[index - 1];
				}
			}

			template<class T>
			const T & ChainList<T>::at(const size_t index) const
			{
				if (index = 0) {
					if (!this->_data) {
						throw std::out_of_range("Out of range access in chainlist.");
					}
					return *this->_data;
				}
				else {
					return (*this->_next)[index - 1];
				}
			}

			template<class T>
			T & ChainList<T>::front()
			{
				return *this->_data;
			}

			template<class T>
			const T & ChainList<T>::front() const
			{
				return *this->_data;
			}

			template<class T>
			T & ChainList<T>::back()
			{
				if (!this->_data) {
					return *this->_data;
				}
				else if (this->_next->empty()) {
					return *this->_data;
				}
				else {
					return this->_next->back();
				}
			}

			template<class T>
			const T & ChainList<T>::back() const
			{
				if (!this->_data) {
					return *this->_data;
				}
				else if (this->_next->empty()) {
					return *this->_data;
				}
				else {
					return this->_next->back();
				}
			}

			template<class T>
			void ChainList<T>::push_back(const T & data)
			{
				// TODO: neet to complete it.
			}

			template<class T>
			template<class ...Args>
			void ChainList<T>::emplace_back(Args && ...args)
			{
				// TODO: neet to complete it.
			}

			template<class T>
			inline void ChainList<T>::insert(Iterator<T> position, const T & data)
			{
				// TODO: neet to complete it.
			}

			template<class T>
			template<class ...Args>
			inline void ChainList<T>::emplace(Iterator<T> position, Args && ...args)
			{
				// TODO: neet to complete it.
			}

			template<class T>
			inline void ChainList<T>::erase(Iterator<T> position)
			{
				(position - 1)->_next = position->_next;
				position->_data.reset();
				position->_next.reset();
			}

			template<class T>
			inline void ChainList<T>::erase(Iterator<T> begin, Iterator<T> end)
			{
				// TODO: neet to complete it.
			}

			template<class T>
			inline void ChainList<T>::clear()
			{
				if (this->_next->empty()) {
					this->_data.reset();
				}
				else {
					this->_next->clear();
					this->_next.reset();
					this->_data.reset();
				}
			}

			template<class T>
			inline void ChainList<T>::swap(Iterator<T> lhs, Iterator<T> rhs)
			{
				// TODO: neet to complete it.
			}
		} // namespace container
	} // namespace utility
} // namespace ece