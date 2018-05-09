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

#ifndef BASE_CONTEXT_HPP
#define BASE_CONTEXT_HPP

#include <memory>

#include "utility/indexing/version.hpp"

namespace ece
{
	namespace renderer
	{
		namespace common
		{
			using utility::indexing::Version;

			class RenderWindow;

			/**
			 * @class BaseContext
			 * @brief Generic render context.
			 */
			class BaseContext : public std::enable_shared_from_this<BaseContext>
			{
			public:
				/**
				 * @fn BaseContext() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline BaseContext() noexcept;

				BaseContext(const BaseContext & copy) = delete;
				BaseContext(BaseContext && move) = delete;

				/**
				 * @fn ~BaseContext() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseContext() noexcept = default;

				BaseContext & operator=(const BaseContext & copy) noexcept = delete;
				BaseContext & operator=(BaseContext && move) = delete;

				/**
				 * @fn void capVersion(const Version<2> & minVersion, const Version<2> & maxVersion)
				 * @param[in] minVersion The mandatory minimum version to set.
				 * @param[in] maxVersion The mandatory maximum version to set.
				 * @brief Cap the minimum and the maximum versions for the render context.
				 * @throw
				 */
				inline void capVersion(const Version<2> & minVersion, const Version<2> & maxVersion);

				/**
				 * @fn void setMinVersion(const Version<2> & minVersion) noexcept
				 * @param[in] minVersion The mandatory minimum version to set.
				 * @brief Set a mandatory minimum version for the render context.
				 * @throw noexcept
				 */
				inline void setMinVersion(const Version<2> & minVersion) noexcept;

				/**
				 * @fn void setMaxVersion(const Version<2> & maxVersion) noexcept
				 * @param[in] maxVersion The mandatory maximum version to set.
				 * @brief Set a mandatory maximum version for the render context.
				 * @throw noexcept
				 */
				inline void setMaxVersion(const Version<2> & maxVersion) noexcept;

				/**
				 * @fn void targetVersion(const Version<2> & target)
				 * @param[in] target The version to target.
				 * @brief Target a version, as close as possible.
				 * @throw
				 */
				inline void targetVersion(const Version<2> & target);

				/**
				 * @fn Version<2> getCurrentVersion() const;
				 * @return The current version of the render context.
				 * @brief Get the version used of the render context.
				 * @throw
				 */
				virtual Version<2> getCurrentVersion() const = 0;

				/**
				 * @fn void create(const RenderWindow & window)
				 * @param[in] window The window to linked to.
				 * @brief Create the context for a window.
				 * @throw
				 */
				virtual void create(const RenderWindow & window) = 0;

				/**
				 * @fn void terminate()
				 * @brief Delete the render context.
				 * @throw
				 */
				virtual void terminate() = 0;

				/**
				 * @fn bool isCreated() const noexcept
				 * @return True if the context is created, false else.
				 * @brief Checks if the context is created or not.
				 * @throw noexcept
				 */
				inline bool isCreated() const noexcept;

				/**
				 * @fn void swapBuffers()
				 * @brief If multi-buffering is enable, it swap between buffers to display the new frame.
				 * @throw
				 */
				virtual void swapBuffers() = 0;

				/**
				 * @fn void setCurrent()
				 * @brief Define this content as the current one.
				 * @throw
				 */
				virtual void setCurrent() = 0;

				/**
				 * @fn void logInfos()
				 * @brief Log the informations related to the render context and the device used.
				 * @throw
				 */
				virtual void logInfos() const = 0;

			protected:
				/**
				 * @property _minVersion
				 * @brief The minimum version for the render context.
				 */
				Version<2> _minVersion;

				/**
				 * @property _maxVersion
				 * @brief The maximum version for the render context.
				 */
				Version<2> _maxVersion;

				/**
				 * @property _created
				 * @brief A flag to check if the context exists or not.
				 */
				bool _created;
			};
		} // namespace common
	} // namespace renderer
} // namespace ece

#include "renderer/common/base_context.inl"

#endif // BASE_CONTEXT_HPP
