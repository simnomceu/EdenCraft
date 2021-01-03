/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooo        ooooo                                .oooooo.                .o8
															`88.       .888'                               d8P'  `Y8b              "888
															 888b     d'888   .ooooo.  oooo d8b  .ooooo.  888          oooo  oooo   888oooo.   .ooooo.
															 8 Y88. .P  888  d88' `88b `888""8P d88' `88b 888          `888  `888   d88' `88b d88' `88b
															 8  `888'   888  888   888  888     888ooo888 888           888   888   888   888 888ooo888
															 8    Y     888  888   888  888     888    .o `88b    ooo   888   888   888   888 888    .o
															o8o        o888o `Y8bod8P' d888b    `Y8bod8P'  `Y8bood8P'   `V88V"V8P'  `Y8bod8P' `Y8bod8P'



				This file is part of EdenCraft Engine - MoreCube sample.
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

#ifndef CUBE_HPP
#define CUBE_HPP

#include "core/ecs.hpp"

/**
 * @class Cube
 * @brief
 */
class Cube
{
public:
	constexpr Cube() noexcept = delete;

	Cube(ece::World & world, const std::size_t chunkSize);

	/**
	 * @fn Cube(const Cube & copy) noexcept
	 * @param[in] copy The Cube to copy from.
	 * @brief Default copy constructor.
	 * @throw noexcept
	 */
	Cube(const Cube & copy) noexcept = default;

	/**
	 * @fn Cube(Cube && move) noexcept
	 * @param[in] move The Cube to move.
	 * @brief Default move constructor.
	 * @throw noexcept
	 */
	Cube(Cube && move) noexcept = default;

	/**
	 * @fn ~Cube() noexcept
	 * @brief Default destructor.
	 * @throw noexcept
	 */
	~Cube() noexcept = default;

	/**
	 * @fn Cube & operator=(const Cube & copy) noexcept
	 * @param[in] copy The Cube to copy from.
	 * @return The Cube copied.
	 * @brief Default copy assignment operator.
	 * @throw noexcept
	 */
	Cube & operator=(const Cube & copy) noexcept = default;

	/**
	 * @fn Cube & operator=(Cube && move) noexcept
	 * @param[in] move The Cube to move.
	 * @return The Cube moved.
	 * @brief Default move assignment operator.
	 * @throw noexcept
	 */
	Cube & operator=(Cube && move) noexcept = default;

	void update();

private:
	ece::EntityHandler _handle;
};

#endif // CUBE_HPP