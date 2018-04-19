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

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>

#include "utility/indexing/dynamic_2d_array.hpp"

namespace
{
	/**
	 * @class Image
	 * @tparam E The color format to use.
	 * @brief
	 */
	template <class E>
	class Image
	{
	public:
		constexpr Image() noexcept = delete;

		/**
		 * @fn Image(const Image<E> & copy) noexcept
		 * @param[in] copy The Image to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		Image(const Image<E> & copy) noexcept = default;

		/**
		 * @fn Image(Image<E> && move) noexcept
		 * @param[in] move The Image to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Image(Image<E> && move) noexcept = default;

		/**
		 * @fn ~Image() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Image() noexcept = default;

		/**
		 * @fn Image<E> & operator=(const Image<E> & copy) noexcept
		 * @param[in] copy The Image to copy from.
		 * @return The Image copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Image<E> & operator=(const Image<E> & copy) noexcept = default;

		/**
		 * @fn Image<E> & operator=(Image<E> && move) noexcept
		 * @param[in] move The Image to move.
		 * @return The Image moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Image<E> & operator=(Image<E> && move) noexcept = default;

		/**
		* @fn E * operator[](const size_t index)
		* @param[in] index The index of the line of pixel to access.
		* @return A pointer to the line of pixel in the image.
		* @brief Get a line of the image.
		* @throw
		*/
		inline E * operator[](const size_t index);

		/**
		* @fn const E * operator[](const size_t index) const
		* @param[in] index The index of the line of pixel to access.
		* @return A pointer to the line of pixel in the image.
		* @brief Get a line of the image.
		* @throw
		*/
		inline const E * operator[](const size_t index) const;

		/**
		* @fn size_t getWidth() const noexcept
		* @return The width of the image.
		* @brief Get the width of the image.
		* @throw noexcept
		*/
		inline size_t getWidth() const noexcept;

		/**
		* @fn size_t getHeight() const noexcept
		* @return The height of the image.
		* @brief Get the height of the image.
		* @throw noexcept
		*/
		inline size_t getHeight() const noexcept;

		/**
		* @fn void resize(const size_t width, const size_t height)
		* @param[in] width The new width of the image.
		* @param[in] height The new height of the image.
		* @brief Resize the image.
		* If it is smaller, some pixels are lose, if it is bigger, new pixels are initialized to the default value.
		* @throw
		*/
		void resize(const size_t width, const size_t height);

		/**
		 * @fn void flipHorizontally()
		 * @brief Flip the image horizontally (from left to right).
		 * @throw
		 */
		void flipHorizontally();
		
		/**
		 * @fn void flipVertically()
		 * @brief Flip the image horizontally (from left to right).
		 * @throw
		 */
		void flipVertically();

		/**
		 * @fn void rotateOnRight()
		 * @brief Rotate the image of 90° on the right.
		 * @throw
		 */
		void rotateOnRight();
		
		/**
		 * @fn void rotateOnLeft()
		 * @brief Rotate the image of 90° on the left.
		 * @throw
		 */
		void rotateOnLeft();

	protected:
		Dynamic2DArray<E> _buffer;
		size_t width;
		size_t height;
	};
}

#include "renderer/image/image.inl"

#endif // IMAGE_HPP