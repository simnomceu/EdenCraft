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

#ifndef CHAIN_LIST_HPP
#define CHAIN_LIST_HPP

#include <iterator>
#include <memory>

namespace ece
{
	namespace utility
	{
		namespace container
		{
			/**
			 * @class ChainList
			 * @tparam T The type of elements in the chainlist.
			 * @brief A chain list of elements.
			 */
			template <class T>
			class ChainList: protected std::enable_shared_from_this<ChainList<T>>
			{
			public:
				template <class T> class Iterator;
				template <class T> class ConstIterator;

				/**
				 * @fn constexpr ChainList() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr ChainList() noexcept;

				/**
				 * @fn ChainList(const ChainList<T> & copy) noexcept
				 * @param[in] copy The ChainList to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ChainList(const ChainList<T> & copy) noexcept;

				/**
				 * @fn ChainList(ChainList<T> && move) noexcept
				 * @param[in] move The ChainList to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ChainList(ChainList<T> && move) noexcept;

				/**
				 * @fn ~ChainList() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ChainList() noexcept;

				/**
				 * @fn ChainList<T> & operator=(const ChainList<T> & copy) noexcept
				 * @param[in] copy The ChainList to copy from.
				 * @return The ChainList copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ChainList<T> & operator=(const ChainList<T> & copy) noexcept;

				/**
				 * @fn ChainList<T> & operator=(ChainList<T> && move) noexcept
				 * @param[in] move The ChainList to move.
				 * @return The ChainList moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ChainList<T> & operator=(ChainList<T> && move) noexcept;

				Iterator<T> begin();
				ConstIterator<T> begin() const;
				Iterator<T> end();
				ConstIterator<T> end() const;

				ChainList<T> & next();
				const ChainList<T> & next() const;

				size_t size() const;
				bool empty() const;

				T & operator[](const size_t index);
				const T & operator[](const size_t index) const;
				T & at(const size_t index);
				const T & operator[](const size_t index);

				T & front();
				const T & front() const;
				T & back();
				const T & back() const;

				void push_back(const T & data);
				template <class... Args> void emplace_back(Args&&... args);

				void insert(Iterator<T> position, const T & data);
				template <class... Args> void emplace(Iterator<T> position, Args&&... args);

				void erase(Iterator<T> position);
				void erase(Iterator<T> begin, Iterator<T> end);
				void clear();

				void swap(Iterator<T> lhs, Iterator<T> rhs);

			protected:
				std::shared_ptr<T> _data;
				std::shared_ptr<ChainList<T>> _next;
			};

			/**
			* @class Iterator
			 * @tparam T The type of elements in the chainlist.
			* @brief
			*/
			template <class T>
			class Iterator: public std::iterator<std::forward_iterator_tag, T>
			{
			public:
				/**
				* @fn constexpr Iterator() noexcept
				* @brief Default constructor.
				* @throw noexcept
				*/
				constexpr Iterator() noexcept = default;

				/**
				* @fn Iterator(const Iterator & copy) noexcept
				* @param[in] copy The Iterator to copy from.
				* @brief Default copy constructor.
				* @throw noexcept
				*/
				Iterator(const Iterator & copy) noexcept = default;

				/**
				* @fn Iterator(Iterator && move) noexcept
				* @param[in] move The Iterator to move.
				* @brief Default move constructor.
				* @throw noexcept
				*/
				Iterator(Iterator && move) noexcept = default;

				/**
				* @fn ~Iterator() noexcept
				* @brief Default destructor.
				* @throw noexcept
				*/
				~Iterator() noexcept = default;

				/**
				* @fn Iterator & operator=(const Iterator & copy) noexcept
				* @param[in] copy The Iterator to copy from.
				* @return The Iterator copied.
				* @brief Default copy assignment operator.
				* @throw noexcept
				*/
				Iterator & operator=(const Iterator & copy) noexcept = default;

				/**
				* @fn Iterator & operator=(Iterator && move) noexcept
				* @param[in] move The Iterator to move.
				* @return The Iterator moved.
				* @brief Default move assignment operator.
				* @throw noexcept
				*/
				Iterator & operator=(Iterator && move) noexcept = default;
			};

			/**
			 * @class ConstIterator
			 * @tparam T The type of elements in the chainlist.
			 * @brief
			 */
			template <class T>
			class ConstIterator: public std::iterator<std::forward_iterator_tag, const T>
			{
			public:
				/**
				 * @fn constexpr ConstIterator() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr ConstIterator() noexcept = default;

				/**
				 * @fn ConstIterator(const ConstIterator & copy) noexcept
				 * @param[in] copy The ConstIterator to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ConstIterator(const ConstIterator & copy) noexcept = default;

				/**
				 * @fn ConstIterator(ConstIterator && move) noexcept
				 * @param[in] move The ConstIterator to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ConstIterator(ConstIterator && move) noexcept = default;

				/**
				 * @fn ~ConstIterator() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ConstIterator() noexcept = default;

				/**
				 * @fn ConstIterator & operator=(const ConstIterator & copy) noexcept
				 * @param[in] copy The ConstIterator to copy from.
				 * @return The ConstIterator copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ConstIterator & operator=(const ConstIterator & copy) noexcept = default;

				/**
				 * @fn ConstIterator & operator=(ConstIterator && move) noexcept
				 * @param[in] move The ConstIterator to move.
				 * @return The ConstIterator moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ConstIterator & operator=(ConstIterator && move) noexcept = default;
			};
		} // namespace container
	} // namespace utility
} // namespace ece

#include "utility/container/chain_list.inl"

#endif // CHAIN_LIST_HPP