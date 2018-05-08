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


#ifndef IBO_HPP
#define IBO_HPP

#include "renderer/resource/object_opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			/**
			 * @class IBO
			 * @brief Index buffer object as defined in OpenGL.
			 */
			class IBO: public ObjectOpenGL
			{
			public:
				/**
				 * @fn IBO()
				 * @brief Default constructor.
				 * @throw
				 */
				inline IBO();

				/**
				 * @fn IBO(const IBO & copy) noexcept
				 * @param[in] copy The index buffer object to copy from.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				IBO(const IBO & copy) noexcept = default;

				/**
				 * @fn IBO(IBO && move) noexcept
				 * @param[in] move The index buffer object to move.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				IBO(IBO && move) noexcept = default;

				/**
				 * @fn ~IBO() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~IBO() noexcept = default;

				/**
				 * @fn IBO & operator=(const IBO & copy) noexcept
				 * @param[in] copy The index buffer object to copy from.
				 * @return The index buffer object copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				IBO & operator=(const IBO & copy) noexcept = default;

				/**
				 * @fn IBO & operator=(IBO && move) noexcept
				 * @param[in] move The index buffer object to copy.
				 * @return The index buffer object moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				IBO & operator=(IBO && move) noexcept = default;

				/**
				 * @fn void bind() const
				 * @brief Put the IBO in a buffer to be used.
				 * @throw
				 */
				inline virtual void bind() const override;

				/**
				 * @fn void bufferData(const std::vector<unsigned int> & data, const BufferUsage usage)
				 * @param[in] data The indices to set.
				 * @param[in] usage The usage of the buffer.
				 * @brief Set the buffer data.
				 * @throw
				 */
				inline void bufferData(const std::vector<unsigned int> & data, const BufferUsage usage);

				inline virtual void terminate() override;
			};
		} // namespace resource
	} // namespace renderer
} // namespace ece

#include "renderer/resource/ibo.inl"

#endif // IBO_HPP