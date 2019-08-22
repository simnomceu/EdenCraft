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
		namespace formats
		{
			namespace bitmap
			{
				inline BitmapPixelData::BitmapPixelData() noexcept: std::vector<std::uint8_t>()
				{
				}

				template <class T>
				BitmapPixelData::BitmapPixelData(std::vector<std::uint8_t>::size_type count, const T & value): std::vector<std::uint8_t>(count * sizeof(T), 0)
				{
					for (auto i = std::size_t{ 0 }; i < count; ++i) {
						this->operator[](i) = value;
					}
				}

				template <class T>
				BitmapPixelData::BitmapPixelData(std::vector<std::uint8_t>::size_type count) : std::vector<std::uint8_t>(count * sizeof(T), 0)
				{
				}

				template <class T, class InputIt>
				BitmapPixelData::BitmapPixelData(InputIt first, InputIt last) : std::vector<std::uint8_t>((last - first) * sizeof(T), 0)
				{
					auto i = std::size_t{ 0 };
					for (auto it = first; i != last; ++it) {
						this->operator[](i) = *it;
						++i;
					}
				}

				inline BitmapPixelData::BitmapPixelData(const BitmapPixelData & other) : std::vector<std::uint8_t>(other)
				{
				}

				inline BitmapPixelData::BitmapPixelData(BitmapPixelData && other) noexcept : std::vector<std::uint8_t>(std::move(other))
				{
				}

				template <class T>
				BitmapPixelData::BitmapPixelData(std::initializer_list<T> init) : std::vector<std::uint8_t>(init.size() * sizeof(T), 0)
				{
					for (auto i = std::size_t{ 0 }; i < init.size(); ++i) {
						this->operator[](i) = init.begin() + i;
					}
				}

				inline BitmapPixelData::~BitmapPixelData()
				{
				}

				inline BitmapPixelData & BitmapPixelData::operator=(const BitmapPixelData & other)
				{
					std::vector<std::uint8_t>::operator=(other);
					return *this;
				}

				inline BitmapPixelData & BitmapPixelData::operator=(BitmapPixelData && other) noexcept
				{
					std::vector<std::uint8_t>::operator=(std::move(other));
					return *this;
				}

				template <class T>
				BitmapPixelData & BitmapPixelData::operator=(std::initializer_list<T> ilist)
				{
					this->clear();
					for (auto it : ilist) {
						this->push_back(*it);
					}
					return *this;
				}

				template <class T>
				void BitmapPixelData::assign(size_type count, const T& value)
				{
					std::vector<std::uint8_t>::assign(count * sizeof(T), 0);
					for (auto i = std::size_t{ 0 }; i < count; ++i) {
						this->operator[](i) = value;
					}
				}

				template <class T, class InputIt>
				void BitmapPixelData::assign(InputIt first, InputIt last)
				{
					std::vector<std::uint8_t>::assign((last - first) * sizeof(T), 0);
					auto i = std::size_t{ 0 };
					for (auto it = first; i != last; ++it) {
						this->operator[](i) = *it;
						++i;
					}
				}

				template <class T>
				void BitmapPixelData::assign(std::initializer_list<T> ilist)
				{
					this->clear();
					for (auto it : ilist) {
						this->push_back(*it);
					}
					return *this;
				}

				template <class T>
				T & BitmapPixelData::at(std::vector<std::uint8_t>::size_type index)
				{
					return *reinterpret_cast<T *>(&std::vector<std::uint8_t>::at(index * sizeof(T)));
				}

				template <class T>
				const T & BitmapPixelData::at(std::vector<std::uint8_t>::size_type index) const
				{
					return *reinterpret_cast<T *>(&std::vector<std::uint8_t>::at(index * sizeof(T)));
				}

				template <class T>
				T & BitmapPixelData::operator[](std::vector<std::uint8_t>::size_type index)
				{
					return *reinterpret_cast<T *>(&std::vector<std::uint8_t>::operator[](index * sizeof(T)));
				}

				template <class T>
				const T & BitmapPixelData::operator[](std::vector<std::uint8_t>::size_type index) const
				{
					return *reinterpret_cast<T *>(&std::vector<std::uint8_t>::operator[](index * sizeof(T)));
				}

				template <class T>
				T & BitmapPixelData::front()
				{
					return this->operator[](0);
				}

				template <class T>
				const T & BitmapPixelData::front() const
				{
					return this->operator[](0);
				}

				template <class T>
				T & BitmapPixelData::back()
				{
					return this->operator[](this->size() - 1);
				}

				template <class T>
				const T & BitmapPixelData::back() const
				{
					return this->operator[](this->size() - 1);
				}

				template <class T>
				T * BitmapPixelData::data() noexcept
				{
					return reinterpret_cast<T *>(std::vector<std::uint8_t>::data());
				}

				template <class T>
				const T * BitmapPixelData::data() const noexcept
				{
					return reinterpret_cast<T *>(std::vector<std::uint8_t>::data());
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::begin() noexcept
				{
					return BitmapPixelData::iterator<T>(&this->front(), this->data());
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::begin() const noexcept
				{
					return BitmapPixelData::const_iterator<T>(&this->front(), this->data());
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::cbegin() const noexcept
				{
					return BitmapPixelData::const_iterator<T>(&this->front(), this->data());
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::end() noexcept
				{
					return this->begin() + this->size();
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::end() const noexcept
				{
					return this->begin() + this->size();
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::cend() const noexcept
				{
					return this->cbegin() + this->size();
				}

				template <class T>
				std::vector<std::uint8_t>::size_type BitmapPixelData::size() const noexcept
				{
					return std::vector<std::uint8_t>::size() / sizeof(T);
				}

				template <class T>
				std::vector<std::uint8_t>::size_type BitmapPixelData::max_size() const noexcept
				{
					return std::vector<std::uint8_t>::max_size() / sizeof(T);
				}

				template <class T>
				void BitmapPixelData::reserve(std::vector<std::uint8_t>::size_type new_cap)
				{
					std::vector<std::uint8_t>::reserve(new_cap * sizeof(T));
				}

				template <class T>
				std::vector<std::uint8_t>::size_type BitmapPixelData::capacity() const noexcept
				{
					return std::vector<std::uint8_t>::capacity() / sizeof(T);
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::insert(BitmapPixelData::const_iterator<T> pos, const T & value)
				{
					auto shift = pos - this->begin();
					std::vector<std::uint8_t>::insert(this->begin() + shift * sizeof(T), sizeof(T), 0);
					this->operator[](shift) = value;
					return this->begin() + shift;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::insert(BitmapPixelData::const_iterator<T> pos, T && value)
				{
					auto shift = pos - this->begin();
					std::vector<std::uint8_t>::insert(this->begin() + shift * sizeof(T), sizeof(T), 0);
					this->operator[](shift) = std::move(value);
					return this->begin() + shift;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::insert(BitmapPixelData::const_iterator<T> pos, std::vector<std::uint8_t>::size_type count, const T & value)
				{
					auto shift = pos - this->begin();
					std::vector<std::uint8_t>::insert(this->begin() + shift * sizeof(T), sizeof(T) * count, 0);
					for (auto i = std::size_t{ 0 }; i < count; ++i) {
						this->operator[](shift + i) = value;
					}
					return this->begin() + shift;
				}

				template <class T, class InputIt>
				BitmapPixelData::iterator<T> BitmapPixelData::insert(BitmapPixelData::const_iterator<T> pos, InputIt first, InputIt last)
				{
					auto count = last - first;
					auto shift = pos - this->begin();
					std::vector<std::uint8_t>::insert(this->begin() + shift * sizeof(T), sizeof(T) * count, 0);
					auto i = std::size_t{ 0 };
					for (auto it = first; it != last; ++it) {
						this->operator[](shift + i) = *it;
						++i;
					}
					return this->begin() + shift;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::insert(const_iterator<T> pos, std::initializer_list<T> ilist)
				{
					return this->insert(pos, std::begin(ilist), std::end(ilist));
				}

				template<class T, class... Args>
				BitmapPixelData::iterator<T> BitmapPixelData::emplace(BitmapPixelData::const_iterator<T> pos, Args && ... args)
				{
					auto shift = pos - this->begin();
					std::vector<std::uint8_t>::insert(this->begin() + shift * sizeof(T), sizeof(T), 0);
					this->operator[](shift) = T(args...);
					return this->begin() + shift;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::erase(BitmapPixelData::const_iterator<T> pos)
				{
					return std::vector<std::uint8_t>::erase(pos, pos + sizeof(T));
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::erase(BitmapPixelData::const_iterator<T> first, BitmapPixelData::const_iterator<T> last)
				{
					auto count = last - first;
					return std::vector<std::uint8_t>::erase(pos, pos + count * sizeof(T));
					
				}

				template <class T>
				void BitmapPixelData::push_back(const T & value)
				{
					for (auto i = std::size_t{ 0 }; i < sizeof(T); ++i) {
						std::vector<std::uint8_t>::push_back(0);
					}
					this->operator[](this->size() - 1) = value;
				}

				template <class T>
				void BitmapPixelData::push_back(T && value)
				{
					for (auto i = std::size_t{ 0 }; i < sizeof(T); ++i) {
						std::vector<std::uint8_t>::push_back(0);
					}
					this->operator[](this->size() - 1) = std::move(value);
				}

				template <class T, class... Args>
				T & BitmapPixelData::emplace_back(Args && ... args)
				{
					for (auto i = std::size_t{ 0 }; i < sizeof(T); ++i) {
						std::vector<std::uint8_t>::push_back(0);
					}
					this->operator[](this->size() - 1) = T(args...);
				}
				
				template <class T>
				void BitmapPixelData::pop_back()
				{
					for (auto i = std::size_t{ 0 }; i < sizeof(T); ++i) {
						std::vector<std::uint8_t>::pop_back();
					}
				}

				template <class T>
				void BitmapPixelData::resize(std::vector<std::uint8_t>::size_type count)
				{
					std::vector<std::uint8_t>::resize(count * sizeof(T));
				}

				template <class T>
				void BitmapPixelData::resize(std::vector<std::uint8_t>::size_type count, const T & value)
				{
					std::vector<std::uint8_t>::resize(count * sizeof(T));
					for (auto i = this->size() - 1; i >= this->size() - count; --i) {
						this->operator[](i) = value;
					}
				}

				template <class T>
				BitmapPixelData::iterator<T>::iterator(): std::vector<std::uint8_t>::iterator()
				{
				}

				template <class T>
				BitmapPixelData::iterator<T>::iterator(T * pArg, std::vector<std::uint8_t> * pVector) : std::vector<std::uint8_t>::iterator(pArg, pVector)
				{
				}

				template <class T>
				BitmapPixelData::iterator<T> & BitmapPixelData::iterator<T>::operator++()
				{
					std::vector<std::uint8_t>::iterator::operator+=(sizeof(T));
					return *this;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::iterator<T>::operator++(int)
				{
					auto tmp = *this;
					std::vector<std::uint8_t>::iterator::operator+=(sizeof(T));
					return tmp;
				}

				template <class T>
				BitmapPixelData::iterator<T> & BitmapPixelData::iterator<T>::operator--()
				{
					std::vector<std::uint8_t>::iterator::operator-=(sizeof(T));
					return *this;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::iterator<T>::operator--(int)
				{
					auto tmp = *this;
					std::vector<std::uint8_t>::iterator::operator-=(sizeof(T));
					return tmp;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::iterator<T>::operator+(int value) const
				{
					auto tmp = *this;
					tmp += value;
					return tmp;
				}

				template <class T>
				BitmapPixelData::iterator<T> BitmapPixelData::iterator<T>::operator-(int value) const
				{
					auto tmp = *this;
					tmp -= value;
					return tmp;
				}

				template <class T>
				BitmapPixelData::iterator<T> & BitmapPixelData::iterator<T>::operator+=(int value)
				{
					std::vector<std::uint8_t>::iterator::operator+=(sizeof(T) * value);
					return *this;
				}

				template <class T>
				BitmapPixelData::iterator<T> & BitmapPixelData::iterator<T>::operator-=(int value)
				{
					std::vector<std::uint8_t>::iterator::operator-=(sizeof(T) * value);
					return *this;
				}

				template <class T>
				std::vector<std::uint8_t>::iterator::difference_type BitmapPixelData::iterator<T>::operator-(const iterator<T> & rhs) const
				{
					return std::vector<std::uint8_t>::iterator::operator-(rhs) / sizeof(T);
				}

				template <class T>
				T & BitmapPixelData::iterator<T>::operator[](std::vector<std::uint8_t>::size_type index) const
				{
					return std::vector<std::uint8_t>::iterator::operator[](index * sizeof(T));
				}

				template <class T>
				T & BitmapPixelData::iterator<T>::operator*() const
				{
					return const_cast<T &>(this->operator->());
				}

				template <class T>
				T * BitmapPixelData::iterator<T>::operator->() const
				{
					return reinterpret_cast<T *>(std::vector<std::uint8_t>::iterator::operator->());
				}

				template <class T>
				BitmapPixelData::const_iterator<T>::const_iterator() : std::vector<std::uint8_t>::const_iterator()
				{
				}

				template <class T>
				BitmapPixelData::const_iterator<T>::const_iterator(T * pArg, std::vector<std::uint8_t> * pVector) : std::vector<std::uint8_t>::const_iterator(pArg, pVector)
				{
				}

				template <class T>
				BitmapPixelData::const_iterator<T> & BitmapPixelData::const_iterator<T>::operator++()
				{
					std::vector<std::uint8_t>::const_iterator::operator+=(sizeof(T));
					return *this;
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::const_iterator<T>::operator++(int)
				{
					auto tmp = *this;
					std::vector<std::uint8_t>::const_iterator::operator+=(sizeof(T));
					return tmp;
				}

				template <class T>
				BitmapPixelData::const_iterator<T> & BitmapPixelData::const_iterator<T>::operator--()
				{
					std::vector<std::uint8_t>::const_iterator::operator-=(sizeof(T));
					return *this;
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::const_iterator<T>::operator--(int)
				{
					auto tmp = *this;
					std::vector<std::uint8_t>::const_iterator::operator-=(sizeof(T));
					return tmp;
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::const_iterator<T>::operator+(int value) const
				{
					auto tmp = *this;
					tmp += value;
					return tmp;
				}

				template <class T>
				BitmapPixelData::const_iterator<T> BitmapPixelData::const_iterator<T>::operator-(int value) const
				{
					auto tmp = *this;
					tmp -= value;
					return tmp;
				}

				template <class T>
				BitmapPixelData::const_iterator<T> & BitmapPixelData::const_iterator<T>::operator+=(int value)
				{
					std::vector<std::uint8_t>::const_iterator::operator+=(sizeof(T) * value);
					return *this;
				}

				template <class T>
				BitmapPixelData::const_iterator<T> & BitmapPixelData::const_iterator<T>::operator-=(int value)
				{
					std::vector<std::uint8_t>::const_iterator::operator-=(sizeof(T) * value);
					return *this;
				}

				template <class T>
				std::vector<std::uint8_t>::const_iterator::difference_type BitmapPixelData::const_iterator<T>::operator-(const const_iterator<T> & rhs) const
				{
					return std::vector<std::uint8_t>::const_iterator::operator-(rhs) / sizeof(T);
				}

				template <class T>
				T & BitmapPixelData::const_iterator<T>::operator[](std::vector<std::uint8_t>::size_type index) const
				{
					return std::vector<std::uint8_t>::const_iterator::operator[](index * sizeof(T));
				}

				template <class T>
				T & BitmapPixelData::const_iterator<T>::operator*() const
				{
					return const_cast<T &>(this->operator->());
				}

				template <class T>
				T * BitmapPixelData::const_iterator<T>::operator->() const
				{
					return reinterpret_cast<T *>(std::vector<std::uint8_t>::const_iterator::operator->());
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece