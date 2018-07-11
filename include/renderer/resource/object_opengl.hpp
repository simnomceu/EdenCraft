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

#ifndef OBJECT_OPENGL_HPP
#define OBJECT_OPENGL_HPP

#include "renderer/config.hpp"
#include "renderer/opengl/opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			using opengl::Handle;

			/**
			 * @class ObjectOpenGL
			 * @brief Base class for any object of the OpenGL API.
			 */
			class ECE_RENDERER_API ObjectOpenGL
			{
			public:
				/**
				 * @fn constexpr ObjectOpenGL() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline constexpr ObjectOpenGL() noexcept;

				/**
				 * @fn ObjectOpenGL(const ObjectOpenGL & copy) noexcept
				 * @param[in] copy The object to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ObjectOpenGL(const ObjectOpenGL & copy) noexcept = default;

				/**
				 * @fn ObjectOpenGL(ObjectOpenGL && move) noexcept
				 * @param[in] move The object to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ObjectOpenGL(ObjectOpenGL && move) noexcept = default;

				/**
				 * @fn ~ObjectOpenGL() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ObjectOpenGL() noexcept = default;
				
				/**
				 * @fn ObjectOpenGL & operator=(const ObjectOpenGL & copy) noexcept
				 * @param[in] copy The object to copy from.
				 * @return The object copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ObjectOpenGL & operator=(const ObjectOpenGL & copy) noexcept = default;

				/**
				 * @fn ObjectOpenGL & operator=(ObjectOpenGL && move) noexcept
				 * @param[in] move The object to move.
				 * @return The object moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ObjectOpenGL & operator=(ObjectOpenGL && move) noexcept = default;

				virtual void bind() const = 0;

				virtual void terminate() = 0;
				

				/**
				 * @fn Handle getHandle() const
				 * @return The id of the object.
				 * @brief Get the id of the object.
				 * @throw
				 */
				inline Handle getHandle() const;

			protected:
				/**
				 * @property _handle
				 * @brief The id of the object.
				 */
				Handle _handle;
			};
		} // namespace resource
	} // namespace renderer
} // namespace ece

#include "renderer/resource/object_opengl.inl"

#endif // OBJECT_OPENGL_HPP