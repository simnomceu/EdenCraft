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

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "renderer/common/renderable.hpp"
#include "renderer/common/texture2d.hpp"
#include "utility/mathematics/rectangle.hpp"

namespace ece
{
    /**
     * @class Sprite
     * @brief
     */
    class Sprite: public Renderable
    {
    public:
        constexpr Sprite() noexcept = delete;

        Sprite(const Texture2D & texture, const Rectangle<float> & bounds = Rectangle<float>(), const Rectangle<float> & textureClip = Rectangle<float>());

        /**
         * @fn Sprite(const Sprite & copy)
         * @param[in] copy The Sprite to copy from.
         * @brief Default copy constructor.
         * @throw
         */
        Sprite(const Sprite & copy) = default;

        /**
         * @fn Sprite(Sprite && move) noexcept
         * @param[in] move The Sprite to move.
         * @brief Default move constructor.
         * @throw noexcept
         */
        Sprite(Sprite && move) noexcept = default;

        /**
         * @fn ~Sprite() noexcept
         * @brief Default destructor.
         * @throw noexcept
         */
        ~Sprite() noexcept = default;

        /**
         * @fn Sprite & operator=(const Sprite & copy)
         * @param[in] The Sprite to copy from.
         * @return The Sprite copied.
         * @brief Default copy assignment operator.
         * @throw
         */
        Sprite & operator=(const Sprite & copy) = default;
		
        /**
         * @fn Sprite & operator=(Sprite && move) noexcept
         * @param[in] The Sprite to move.
         * @return The Sprite moved.
         * @brief Default move assignment operator.
         * @throw noexcept
         */
        Sprite & operator=(Sprite && move) noexcept = default;

    private:
        Texture2D _texture;
		Rectangle<float> _textureClip;

        Rectangle<float> _bounds;
    };
}

#endif // SPRITE_HPP