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

#ifndef IS_BUFFER_STORAGE_HPP
#define IS_BUFFER_STORAGE_HPP

#include "renderer/config.hpp"
#include "renderer/buffer/buffer_operation.hpp"

#include <type_traits>

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			template <class T, typename = void>
			struct ECE_RENDERER_API has_buffer_read : public std::false_type
			{
			};

			template <class T>
			struct ECE_RENDERER_API has_buffer_read<T, std::void_t<decltype(read<T>(std::declval<T>()))>> : public std::true_type
			{
			};

			template <class T>
			inline constexpr bool has_buffer_read_v = has_buffer_read<T>::value;

			template <class B, class D, typename = void>
			struct has_buffer_write : public std::false_type
			{
			};

			template <class B, class D>
			struct ECE_RENDERER_API has_buffer_write<B, D, std::void_t<decltype(write<B, D>(std::declval<B>(), std::declval<D>()))>> : public std::true_type
			{
			};

			template <class B, class D>
			inline constexpr bool has_buffer_write_v = has_buffer_write<B, D>::value;

			template <class T, typename = void>
			struct ECE_RENDERER_API has_buffer_copy : public std::false_type
			{
			};

			template <class T>
			struct ECE_RENDERER_API has_buffer_copy<T, std::void_t<decltype(copy<T>(std::declval<T>(), std::declval<BaseBuffer>()))>> : public std::true_type
			{
			};

			template <class T>
			inline constexpr bool has_buffer_copy_v = has_buffer_copy<T>::value;

			template <template <class> class B, class D>
			struct ECE_RENDERER_API is_buffer_storage: std::integral_constant<bool, has_buffer_read<B<D>>::value && has_buffer_write<B<D>, D>::value && has_buffer_copy<B<D>>::value>
			{
			};

			template <template <class> class B, class D>
			inline constexpr bool is_buffer_storage_v = is_buffer_storage<B, D>::value;
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#endif // IS_BUFFER_STORAGE_HPP