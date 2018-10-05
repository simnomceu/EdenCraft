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
			template <class Storage, class Data, typename enabled>
			inline Buffer<Storage, Data, enabled>::Buffer(const BufferFrequency frequency) noexcept : BaseBuffer(), ObjectOpenGL(), std::enable_shared_from_this<Buffer>(), _descriptor{0, BufferLayout()}, _type(), _frequency(frequency), _storage()
			{
				this->_storage = std::make_unique<Storage>(this->weak_from_this());
			}

			template <class Storage, class Data, typename enabled>
			void Buffer<Storage, Data, enabled>::bind() const
			{
				OpenGL::bindBuffer(this->_type, this->_handle);
			}

			template <class Storage, class Data, typename enabled>
			void Buffer<Storage, Data, enabled>::terminate()
			{
				OpenGL::deleteBuffer(this->_handle);
				this->_handle = NullHandle;
			}

			template <class Storage, class Data, typename enabled>
			template<template <class...> class T, class... TT, typename enabledBis>
			T<TT...> Buffer<Storage, Data, enabled>::read() const
			{
				return this->_storage->read();
			}

			template <class Storage, class Data, typename enabled>
			template<template <class...> class T, class... TT, typename enabledBis>
			void Buffer<Storage, Data, enabled>::write(const T<TT...> & data)
			{
				this->_storage.write(data);
			}

			template <class Storage, class Data, typename enabled>
			void Buffer<Storage, Data, enabled>::copy(const Buffer<Storage, Data, enabled> & rhs)
			{
				this->_storage.copy(rhs);
			}

			template <class Storage, class Data, typename enabled>
			inline void Buffer<Storage, Data, enabled>::setDataDescriptor(const BufferDataDescriptor & descriptor) noexcept { this->_descriptor = descriptor; }

			template <class Storage, class Data, typename enabled>
			inline const BufferDataDescriptor & Buffer<Storage, Data, enabled>::getDataDescriptor() const noexcept { return this->_descriptor; }


			template <class Storage, class Data, typename enabled>
			inline std::size_t Buffer<Storage, Data, enabled>::size() const noexcept { return this->_storage.data().size(); }


			template <class Storage, class Data, typename enabled>
			inline BufferType & Buffer<Storage, Data, enabled>::getType() const { return this->_type; }

			template <class Storage, class Data, typename enabled>
			inline BufferFrequency Buffer<Storage, Data, enabled>::getFrequency() const { return this->_frequency; }
		} // namespace buffer
	} // namespace renderer
} // namespace ece