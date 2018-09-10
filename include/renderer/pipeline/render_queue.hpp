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

#ifndef RENDER_QUEUE_HPP
#define RENDER_QUEUE_HPP

#include "graphic/config.hpp"
#include "renderer/pipeline/drawable.hpp"

#include <memory>
#include <set>
#include <functional>

namespace ece
{
	namespace renderer
	{
		namespace pipeline
		{
			/**
			 * @class RenderQueue
			 * @brief
			 */
			class ECE_GRAPHIC_API RenderQueue
			{
			public:
				using SortAlgorithm = std::function<bool(const std::shared_ptr<Drawable> &, const std::shared_ptr<Drawable> &)>;
				using Iterator = std::vector<std::shared_ptr<Drawable>>::iterator;
				using ConstIterator = std::vector<std::shared_ptr<Drawable>>::const_iterator;

				/**
				 * @fn constexpr RenderQueue() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				RenderQueue() noexcept = default;

				/**
				 * @fn RenderQueue(const RenderQueue & copy) noexcept
				 * @param[in] copy The RenderQueue to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				RenderQueue(const RenderQueue & copy) noexcept = default;

				/**
				 * @fn RenderQueue(RenderQueue && move) noexcept
				 * @param[in] move The RenderQueue to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				RenderQueue(RenderQueue && move) noexcept = default;

				/**
				 * @fn ~RenderQueue() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~RenderQueue() noexcept = default;

				/**
				 * @fn RenderQueue & operator=(const RenderQueue & copy) noexcept
				 * @param[in] copy The RenderQueue to copy from.
				 * @return The RenderQueue copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				RenderQueue & operator=(const RenderQueue & copy) noexcept = default;

				/**
				 * @fn RenderQueue & operator=(RenderQueue && move) noexcept
				 * @param[in] move The RenderQueue to move.
				 * @return The RenderQueue moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				RenderQueue & operator=(RenderQueue && move) noexcept = default;

				void add(const std::shared_ptr<Drawable> & drawable);
				void remove(const std::shared_ptr<Drawable> & drawable);
				void clear();

				void sort(const SortAlgorithm & algorithm);

				inline Iterator begin() noexcept;
				inline ConstIterator begin() const noexcept;
				inline Iterator end() noexcept;
				inline ConstIterator end() const noexcept;

			private:
				std::vector<std::shared_ptr<Drawable>> _drawables;
			};
		} // namespace pipeline
	} // namespace renderer
} // namespcace ece

#include "renderer/pipeline/render_queue.inl"

#endif // RENDER_QUEUE_HPP