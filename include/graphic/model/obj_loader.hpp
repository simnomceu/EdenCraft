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

#ifndef OBJ_LOADER_HPP
#define OBJ_LOADER_HPP

#include "graphic/config.hpp"
#include "utility/file_system/loader.hpp"
#include "graphic/model/mesh.hpp"
#include "graphic/model/phong_material.hpp"
#include "utility/wavefront/parser_obj.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using utility::file_system::Loader;
			using utility::wavefront::ParserOBJ;

			/**
			 * @class OBJLoader
			 * @brief
			 */
			class ECE_GRAPHIC_API OBJLoader: public Loader
			{
			public:
				/**
				 * @fn OBJLoader() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				OBJLoader() noexcept = default;

				/**
				 * @fn OBJLoader(const OBJLoader & copy)
				 * @param[in] copy The OBJLoader to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				OBJLoader(const OBJLoader & copy) = default;

				/**
				 * @fn OBJLoader(OBJLoader && move) noexcept
				 * @param[in] move The OBJLoader to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				OBJLoader(OBJLoader && move) noexcept = default;

				/**
				 * @fn ~OBJLoader() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~OBJLoader() noexcept = default;

				/**
				 * @fn OBJLoader & operator=(const OBJLoader & copy)
				 * @param[in] copy The OBJLoader to copy from.
				 * @return The OBJLoader copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				OBJLoader & operator=(const OBJLoader & copy) = default;

				/**
				 * @fn OBJLoader & operator=(OBJLoader && move) noexcept
				 * @param[in] move The OBJLoader to move.
				 * @return The OBJLoader moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				OBJLoader & operator=(OBJLoader && move) noexcept = default;

				/**
				* @fn void loadFromFile(const std::string & filename)
				* @param[in] filename The name of the file to load data from.
				* @brief Load and parse data from a file.
				* @throw
				*/
				virtual void loadFromFile(const std::string & filename) override;

				/**
				* @fn void loadFromString(const std::string & content)
				* @param[in] content The string content to load data from.
				* @brief Load and parse data from a string.
				* @throw
				*/
				virtual void loadFromString(const std::string & content) override;

				/**
				* @fn void loadFromMemory(const void * content)
				* @param[in] content The memory buffer to load data from.
				* @brief Load and parse data from memory.
				* @throw
				*/
				virtual void loadFromMemory(const void * content) override;

				inline Mesh & getMesh();
				inline const Mesh & getMesh() const;

				inline PhongMaterial & getMaterial();
				inline const PhongMaterial & getMaterial() const;

			protected:
				void load(const std::string & filename, ParserOBJ & parser);

			private:
				Mesh _mesh;
				PhongMaterial _material;
			};
		} // namespace model
	} // namespace graphic
} // namespace ece

#include "graphic/model/obj_loader.inl"

#endif // OBJ_LOADER_HPP