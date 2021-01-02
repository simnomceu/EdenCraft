/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

#ifndef BUFFER_LAYOUT_HPP
#define BUFFER_LAYOUT_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "renderer/buffer/data_type.hpp"

namespace ece
{
    namespace renderer
    {
        namespace buffer
        {
            /**
             * @class BufferLayout
             * @brief
             */
            class ECE_RENDERER_API BufferLayout
            {
            public:
                struct ElementLayout
                {
                    DataType type;
                    ece::size_t unitSize;
                    ece::size_t count;
					ece::offset_t offset;
                    bool normalized;
					bool ignored;
					bool instanced;
                };

				enum class Strategy : unsigned char
				{
					STRUCTURED,
					CONCATENATED
				};

                /**
                 * @fn BufferLayout() noexcept
                 * @brief Default constructor.
                 * @throw noexcept
                 */
                inline BufferLayout(const Strategy strategy = DEFAULT_STRATEGY) noexcept;

                /**
                 * @fn BufferLayout(const BufferLayout & copy)
                 * @param[in] copy The BufferLayout to copy from.
                 * @brief Default copy constructor.
                 * @throw
                 */
                BufferLayout(const BufferLayout & copy) = default;

                /**
                 * @fn BufferLayout(BufferLayout && move) noexcept
                 * @param[in] move The BufferLayout to move.
                 * @brief Default move constructor.
                 * @throw noexcept
                 */
                BufferLayout(BufferLayout && move) noexcept = default;

                /**
                 * @fn ~BufferLayout() noexcept
                 * @brief Default destructor.
                 * @throw noexcept
                 */
                ~BufferLayout() noexcept = default;

                /**
                 * @fn BufferLayout & operator=(const BufferLayout & copy)
                 * @param[in] The BufferLayout to copy from.
                 * @return The BufferLayout copied.
                 * @brief Default copy assignment operator.
                 * @throw
                 */
                BufferLayout & operator=(const BufferLayout & copy) = default;

                /**
                 * @fn BufferLayout & operator=(BufferLayout && move) noexcept
                 * @param[in] The BufferLayout to move.
                 * @return The BufferLayout moved.
                 * @brief Default move assignment operator.
                 * @throw noexcept
                 */
                BufferLayout & operator=(BufferLayout && move) noexcept = default;

                template <class T> void add(const ece::size_t size, const bool normalized, const bool ignored, const bool instanced);

				auto getStride() const;

                inline auto & getElement(const std::size_t index);
                inline const auto & getElement(const std::size_t index) const;
                inline auto size() const;

				inline void setInstanceBlockSize(const ece::size_t size) noexcept;
				inline auto getInstanceBlockSize() const noexcept;

				inline auto getStrategy() const noexcept;

            private:
                std::vector<ElementLayout> _elements;

				ece::size_t _instanceBlockSize;
				
				Strategy _strategy;

				static constexpr auto DEFAULT_INSTANCE_BLOCK_SIZE = std::size_t{ 0 };
				static constexpr auto DEFAULT_STRATEGY = Strategy::STRUCTURED;
            };
        } // namespace buffer
    } // namespace renderer
} // namespace ece

#include "renderer/buffer/buffer_layout.inl"

#endif // BUFFER_LAYOUT_HPP
