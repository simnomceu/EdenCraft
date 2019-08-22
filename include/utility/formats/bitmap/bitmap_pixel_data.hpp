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

#ifndef BITMAP_PIXEL_DATA_HPP
#define BITMAP_PIXEL_DATA_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				class ECE_UTILITY_API BitmapPixelData : protected std::vector<std::uint8_t>
				{
				public:
					template <class T> class iterator;
					template <class T> class const_iterator;

					inline BitmapPixelData() noexcept;
					template <class T> explicit BitmapPixelData(std::vector<std::uint8_t>::size_type count, const T & value = T());
					template <class T> explicit BitmapPixelData(std::vector<std::uint8_t>::size_type count);
					template <class T, class InputIt> BitmapPixelData(InputIt first, InputIt last);
					inline BitmapPixelData(const BitmapPixelData & other);
					inline BitmapPixelData(BitmapPixelData && other) noexcept;
					template <class T> BitmapPixelData(std::initializer_list<T> init);
					inline ~BitmapPixelData();
					inline BitmapPixelData & operator=(const BitmapPixelData & other);
					inline BitmapPixelData & operator=(BitmapPixelData && other) noexcept;
					template <class T> BitmapPixelData & operator=(std::initializer_list<T> ilist);
					template <class T> void assign(size_type count, const T& value);
					template <class T, class InputIt> void assign(InputIt first, InputIt last);
					template <class T> void assign(std::initializer_list<T> ilist);
					using std::vector<std::uint8_t>::get_allocator;

					template <class T> T & at(std::vector<std::uint8_t>::size_type index);
					template <class T> const T & at(std::vector<std::uint8_t>::size_type index) const;
					template <class T> T & operator[](std::vector<std::uint8_t>::size_type index);
					template <class T> const T & operator[](std::vector<std::uint8_t>::size_type index) const;
					template <class T> T & front();
					template <class T> const T & front() const;
					template <class T> T & back();
					template <class T> const T & back() const;
					template <class T> T * data() noexcept;
					template <class T> const T * data() const noexcept;

					template <class T> iterator<T> begin() noexcept;
					template <class T> const_iterator<T> begin() const noexcept;
					template <class T> const_iterator<T> cbegin() const noexcept;
					template <class T> iterator<T> end() noexcept;
					template <class T> const_iterator<T> end() const noexcept;
					template <class T> const_iterator<T> cend() const noexcept;

					using std::vector<std::uint8_t>::empty;
					template <class T> std::vector<std::uint8_t>::size_type size() const noexcept;
					template <class T> std::vector<std::uint8_t>::size_type max_size() const noexcept;
					template <class T> void reserve(std::vector<std::uint8_t>::size_type new_cap);
					template <class T> std::vector<std::uint8_t>::size_type capacity() const noexcept;
					using std::vector<std::uint8_t>::shrink_to_fit;

					using std::vector<std::uint8_t>::clear;
					template <class T> iterator<T> insert(const_iterator<T> pos, const T & value);
					template <class T> iterator<T> insert(const_iterator<T> pos, T && value);
					template <class T> iterator<T> insert(const_iterator<T> pos, std::vector<std::uint8_t>::size_type count, const T & value);
					template <class T, class InputIt> iterator<T> insert(const_iterator<T> pos, InputIt first, InputIt last);
					template <class T> iterator<T> insert(const_iterator<T> pos, std::initializer_list<T> ilist);
					template<class T, class... Args> iterator<T> emplace(const_iterator<T> pos, Args && ... args);
					template <class T> iterator<T> erase(const_iterator<T> pos);
					template <class T> iterator<T> erase(const_iterator<T> first, const_iterator<T> last);
					template <class T> void push_back(const T & value);
					template <class T> void push_back(T && value);
					template <class T, class... Args> T & emplace_back(Args && ... args);
					template <class T> void pop_back();
					template <class T> void resize(std::vector<std::uint8_t>::size_type count);
					template <class T> void resize(std::vector<std::uint8_t>::size_type count, const T & value);
					using std::vector<std::uint8_t>::swap;
				};

				template <class T>
				class ECE_UTILITY_API BitmapPixelData::iterator : protected std::vector<std::uint8_t>::iterator
				{
				public:
					iterator();
					iterator(T * pArg, std::vector<std::uint8_t> * pVector);

					iterator<T> & operator++();
					iterator<T> operator++(int);
					iterator<T> & operator--();
					iterator<T> operator--(int);

					iterator<T> operator+(int value) const;
					iterator<T> operator-(int value) const;

					iterator<T> & operator+=(int value);
					iterator<T> & operator-=(int value);

					std::vector<std::uint8_t>::iterator::difference_type operator-(const iterator<T> & rhs) const;

					using std::vector<std::uint8_t>::iterator::operator<;
					using std::vector<std::uint8_t>::iterator::operator>;
					using std::vector<std::uint8_t>::iterator::operator<=;
					using std::vector<std::uint8_t>::iterator::operator>=;
					using std::vector<std::uint8_t>::iterator::operator==;
					using std::vector<std::uint8_t>::iterator::operator!=;

					T & operator[](std::vector<std::uint8_t>::size_type index) const;
					T & operator*() const;
					T * operator->() const;
				};

				template <class T>
				class ECE_UTILITY_API BitmapPixelData::const_iterator : protected std::vector<std::uint8_t>::const_iterator
				{
				public:
					const_iterator();
					const_iterator(T * pArg, std::vector<std::uint8_t> * pVector);

					const_iterator<T> & operator++();
					const_iterator<T> operator++(int);
					const_iterator<T> & operator--();
					const_iterator<T> operator--(int);

					const_iterator<T> operator+(int value) const;
					const_iterator<T> operator-(int value) const;

					const_iterator<T> & operator+=(int value);
					const_iterator<T> & operator-=(int value);

					std::vector<std::uint8_t>::const_iterator::difference_type operator-(const const_iterator<T> & rhs) const;

					using std::vector<std::uint8_t>::const_iterator::operator<;
					using std::vector<std::uint8_t>::const_iterator::operator>;
					using std::vector<std::uint8_t>::const_iterator::operator<=;
					using std::vector<std::uint8_t>::const_iterator::operator>=;
					using std::vector<std::uint8_t>::const_iterator::operator==;
					using std::vector<std::uint8_t>::const_iterator::operator!=;

					T & operator[](std::vector<std::uint8_t>::size_type index) const;
					T & operator*() const;
					T * operator->() const;
				};
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#include "utility/formats/bitmap/bitmap_pixel_data.inl"

#endif // BITMAP_PIXEL_DATA_HPP