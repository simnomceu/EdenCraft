/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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
	namespace renderer
	{
		namespace buffer
		{
			template <template <class> class Storage, class Data, typename enabled>
			Buffer<Storage, Data, enabled>::Buffer(const BufferFrequency frequency) noexcept : BaseBuffer(), _frequency(frequency), _storage()
			{
				this->_storage = std::make_unique<Storage<Data>>(*this);
			}

			template <template <class> class Storage, class Data, typename enabled>
			Buffer<Storage, Data, enabled>::Buffer(const Buffer<Storage, Data, enabled> & copy) noexcept: BaseBuffer(copy), _frequency(copy._frequency), _storage()
			{
				this->_storage = std::make_unique<Storage<Data>>(*this);
				this->_storage->copy(copy);
			}

			template <template <class> class Storage, class Data, typename enabled>
			Buffer<Storage, Data, enabled>::Buffer(Buffer<Storage, Data, enabled> && move) noexcept : BaseBuffer(move), _frequency(std::move(move._frequency)), _storage()
			{
				this->_storage = std::make_unique<Storage<Data>>(*this);
				this->_storage->copy(move);
			}

			template <template <class> class Storage, class Data, typename enabled>
			Buffer<Storage, Data, enabled> & Buffer<Storage, Data, enabled>::operator=(const Buffer<Storage, Data, enabled> & copy) noexcept
			{
				BaseBuffer::operator=(copy);
				this->_frequency = copy._frequency;
				this->copy(copy);

				return *this;
			}

			template <template <class> class Storage, class Data, typename enabled>
			Buffer<Storage, Data, enabled> & Buffer<Storage, Data, enabled>::operator=(Buffer<Storage, Data, enabled> && move) noexcept
			{
				BaseBuffer::operator=(move);
				this->_frequency = std::move(move._frequency);
				this->copy(move);

				return *this;
			}

			template <template <class> class Storage, class Data, typename enabled>
			Data Buffer<Storage, Data, enabled>::read() const
			{
				return this->_storage->read();
			}

			template <template <class> class Storage, class Data, typename enabled>
			void Buffer<Storage, Data, enabled>::write(const Data & data)
			{
				this->_storage->write(data);
			}

			template <template <class> class Storage, class Data, typename enabled>
			void Buffer<Storage, Data, enabled>::copy(const Buffer<Storage, Data, enabled> & rhs)
			{
				this->_storage->copy(rhs);
			}

			template <template <class> class Storage, class Data, typename enabled>
			void Buffer<Storage, Data, enabled>::update()
			{
				this->_storage->update();
			}

			template <template <class> class Storage, class Data, typename enabled>
			inline std::size_t Buffer<Storage, Data, enabled>::size() const noexcept { return this->_storage->data().size(); }

			template <template <class> class Storage, class Data, typename enabled>
			inline BufferFrequency Buffer<Storage, Data, enabled>::getFrequency() const { return this->_frequency; }

			template <template <class> class Storage, class Data, typename enabled>
			inline Data & Buffer<Storage, Data, enabled>::data() { return this->_storage->data(); }

			template <template <class> class Storage, class Data, typename enabled>
			inline const Data & Buffer<Storage, Data, enabled>::data() const { return this->_storage->data(); }
		} // namespace buffer
	} // namespace renderer
} // namespace ece