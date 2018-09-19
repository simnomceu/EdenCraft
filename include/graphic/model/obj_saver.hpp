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

#ifndef OBJ_SAVER_HPP
#define OBJ_SAVER_HPP

#include "graphic/config.hpp"
#include "utility/file_system/saver.hpp"
#include "graphic/model/mesh.hpp"
#include "utility/formats/wavefront/parser_obj.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using utility::file_system::Saver;
			using utility::formats::wavefront::ParserOBJ;

			/**
			 * @class OBJSaver
			 * @brief
			 */
			class ECE_GRAPHIC_API OBJSaver: public Saver
			{
			public:
				/**
				 * @fn constexpr OBJSaver() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr OBJSaver() noexcept = default;

				/**
				 * @fn OBJSaver(const OBJSaver & copy) noexcept
				 * @param[in] copy The OBJSaver to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				OBJSaver(const OBJSaver & copy) noexcept = default;

				/**
				 * @fn OBJSaver(OBJSaver && move) noexcept
				 * @param[in] move The OBJSaver to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				OBJSaver(OBJSaver && move) noexcept = default;

				/**
				 * @fn ~OBJSaver() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~OBJSaver() noexcept = default;

				/**
				 * @fn OBJSaver & operator=(const OBJSaver & copy) noexcept
				 * @param[in] copy The OBJSaver to copy from.
				 * @return The OBJSaver copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				OBJSaver & operator=(const OBJSaver & copy) noexcept = default;

				/**
				 * @fn OBJSaver & operator=(OBJSaver && move) noexcept
				 * @param[in] move The OBJSaver to move.
				 * @return The OBJSaver moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				OBJSaver & operator=(OBJSaver && move) noexcept = default;

				/**
				 * @fn void saveToFile(const std::string & filename)
				 * @param[out] filename The name of the file to save into.
				 * @brief Formate and save data into a file.
				 * @throw
				 */
				virtual void saveToFile(const std::string & filename) override;

				/**
				 * @fn void saveToString(std::string & content)
				 * @param[out] content The string buffer to save into.
				 * @brief Formate and save data into a string buffer.
				 * @throw
				 */
				virtual void saveToString(std::string & content) override;

				/**
				 * @fn void saveToMemory(void * content)
				 * @param[out] content The memory to save into.
				 * @brief Formate and save data into memory.
				 * @throw
				 */
				virtual void saveToMemory(void * content) override;

				inline void setMesh(Mesh::Reference && mesh);

			protected:
				void save(const std::string & filename, ParserOBJ & parser);

			private:
				Mesh::Reference _mesh;
			};
		} // namespace model
	} // namespace graphic
} // namespace ece

#include "graphic/model/obj_saver.inl"

#endif // OBJ_SAVER_HPP