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

#ifndef BASE_UNIFORM_HPP
#define BASE_UNIFORM_HPP

#include <string>

#include "renderer/config.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			/**
			 * @class BaseUniform
			 * @brief
			 */
			class ECE_RENDERER_API BaseUniform
			{
			public:

				enum class DataType : unsigned short int
				{
					FLOAT										= 0x000,
					FLOAT_VEC2									= 0x001,
					FLOAT_VEC3									= 0x002,
					FLOAT_VEC4									= 0x003,
					DOUBLE										= 0x004,
					DOUBLE_VEC2									= 0x005,
					DOUBLE_VEC3									= 0x006,
					DOUBLE_VEC4									= 0x007,
					INT											= 0x008,
					INT_VEC2									= 0x009,
					INT_VEC3									= 0x010,
					INT_VEC4									= 0x011,
					UNSIGNED_INT								= 0x012,
					UNSIGNED_INT_VEC2							= 0x013,
					UNSIGNED_INT_VEC3							= 0x014,
					UNSIGNED_INT_VEC4							= 0x015,
					BOOL										= 0x016,
					BOOL_VEC2									= 0x017,
					BOOL_VEC3									= 0x018,
					BOOL_VEC4									= 0x019,
					FLOAT_MAT2									= 0x020,
					FLOAT_MAT3									= 0x021,
					FLOAT_MAT4									= 0x022,
					FLOAT_MAT2x3								= 0x023,
					FLOAT_MAT2x4								= 0x024,
					FLOAT_MAT3x2								= 0x025,
					FLOAT_MAT3x4								= 0x026,
					FLOAT_MAT4x2								= 0x027,
					FLOAT_MAT4x3								= 0x028,
					DOUBLE_MAT2									= 0x029,
					DOUBLE_MAT3									= 0x030,
					DOUBLE_MAT4									= 0x031,
					DOUBLE_MAT2x3								= 0x032,
					DOUBLE_MAT2x4								= 0x033,
					DOUBLE_MAT3x2								= 0x034,
					DOUBLE_MAT3x4								= 0x035,
					DOUBLE_MAT4x2								= 0x036,
					DOUBLE_MAT4x3								= 0x037,
					SAMPLER_1D									= 0x038,
					SAMPLER_2D									= 0x039,
					SAMPLER_3D									= 0x040,
					SAMPLER_CUBE								= 0x041,
					SAMPLER_1D_SHADOW							= 0x042,
					SAMPLER_2D_SHADOW							= 0x043,
					SAMPLER_1D_ARRAY							= 0x044,
					SAMPLER_2D_ARRAY							= 0x045,
					SAMPLER_1D_ARRAY_SHADOW						= 0x046,
					SAMPLER_2D_ARRAY_SHADOW						= 0x047,
					SAMPLER_2D_MULTISAMPLE						= 0x048,
					SAMPLER_2D_MULTISAMPLE_ARRAY				= 0x049,
					SAMPLER_CUBE_SHADOW							= 0x050,
					SAMPLER_BUFFER								= 0x051,
					SAMPLER_2D_RECT								= 0x052,
					SAMPLER_2D_RECT_SHADOW						= 0x053,
					INT_SAMPLER_1D								= 0x054,
					INT_SAMPLER_2D								= 0x055,
					INT_SAMPLER_3D								= 0x056,
					INT_SAMPLER_CUBE							= 0x057,
					INT_SAMPLER_1D_ARRAY						= 0x058,
					INT_SAMPLER_2D_ARRAY						= 0x059,
					INT_SAMPLER_2D_MULTISAMPLE					= 0x060,
					INT_SAMPLER_2D_MULTISAMPLE_ARRAY			= 0x061,
					INT_SAMPLER_BUFFER							= 0x062,
					INT_SAMPLER_2D_RECT							= 0x063,
					UNSIGNED_INT_SAMPLER_1D						= 0x064,
					UNSIGNED_INT_SAMPLER_2D						= 0x065,
					UNSIGNED_INT_SAMPLER_3D						= 0x066,
					UNSIGNED_INT_SAMPLER_CUBE					= 0x067,
					UNSIGNED_INT_SAMPLER_1D_ARRAY				= 0x068,
					UNSIGNED_INT_SAMPLER_2D_ARRAY				= 0x069,
					UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE			= 0x070,
					UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY	= 0x071,
					UNSIGNED_INT_SAMPLER_BUFFER					= 0x072,
					UNSIGNED_INT_SAMPLER_2D_RECT				= 0x073,
					IMAGE_1D									= 0x074,
					IMAGE_2D									= 0x075,
					IMAGE_3D									= 0x076,
					IMAGE_2D_RECT								= 0x077,
					IMAGE_CUBE									= 0x078,
					IMAGE_BUFFER								= 0x079,
					IMAGE_1D_ARRAY								= 0x080,
					IMAGE_2D_ARRAY								= 0x081,
					IMAGE_2D_MULTISAMPLE						= 0x082,
					IMAGE_2D_MULTISAMPLE_ARRAY					= 0x083,
					INT_IMAGE_1D								= 0x084,
					INT_IMAGE_2D								= 0x085,
					INT_IMAGE_3D								= 0x086,
					INT_IMAGE_2D_RECT							= 0x087,
					INT_IMAGE_CUBE								= 0x088,
					INT_IMAGE_BUFFER							= 0x089,
					INT_IMAGE_1D_ARRAY							= 0x090,
					INT_IMAGE_2D_ARRAY							= 0x091,
					INT_IMAGE_2D_MULTISAMPLE					= 0x092,
					INT_IMAGE_2D_MULTISAMPLE_ARRAY				= 0x093,
					UNSIGNED_INT_IMAGE_1D						= 0x094,
					UNSIGNED_INT_IMAGE_2D						= 0x095,
					UNSIGNED_INT_IMAGE_3D						= 0x096,
					UNSIGNED_INT_IMAGE_2D_RECT					= 0x097,
					UNSIGNED_INT_IMAGE_CUBE						= 0x098,
					UNSIGNED_INT_IMAGE_BUFFER					= 0x099,
					UNSIGNED_INT_IMAGE_1D_ARRAY					= 0x100,
					UNSIGNED_INT_IMAGE_2D_ARRAY					= 0x101,
					UNSIGNED_INT_IMAGE_2D_MULTISAMPLE			= 0x102,
					UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY		= 0x103,
					UNSIGNED_INT_ATOMIC_COUNTER					= 0x104
				};

				struct Info
				{
					std::string name;
					DataType type;
					std::size_t size;
				};

				/**
				 * @fn BaseUniform() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				BaseUniform() noexcept = default;

				/**
				 * @fn BaseUniform(const BaseUniform & copy)
				 * @param[in] copy The BaseUniform to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseUniform(const BaseUniform & copy) = default;

				/**
				 * @fn BaseUniform(BaseUniform && move) noexcept
				 * @param[in] move The BaseUniform to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BaseUniform(BaseUniform && move) noexcept = default;

				/**
				 * @fn ~BaseUniform() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseUniform() noexcept = default;

				/**
				 * @fn BaseUniform & operator=(const BaseUniform & copy)
				 * @param[in] copy The BaseUniform to copy from.
				 * @return The BaseUniform copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseUniform & operator=(const BaseUniform & copy) = default;

				/**
				 * @fn BaseUniform & operator=(BaseUniform && move) noexcept
				 * @param[in] move The BaseUniform to move from.
				 * @return The BaseUniform moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseUniform & operator=(BaseUniform && move) noexcept = default;

				/**
				 * @fn const std::string & getName() const noexcept
				 * @return The string location.
				 * @brief Get the string name of the uniform.
				 * @throw noexcept
				 */
				inline const std::string & getName() const noexcept;

				inline void setName(const std::string & name);

				virtual void bind(const Handle & location) = 0;

			protected:
				std::string _name;
			};
		} // namespace shader
	} // namespace renderer
} // namespace ece

#include "renderer/shader/base_uniform.inl"

#endif // BASE_UNIFORM_HPP