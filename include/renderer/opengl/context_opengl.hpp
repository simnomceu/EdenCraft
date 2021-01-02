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

#ifndef CONTEXT_OPENGL_HPP
#define CONTEXT_OPENGL_HPP

#include "renderer/rendering.hpp"
#include "utility/pattern.hpp"
#include "utility/indexing.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			struct DataContextOpenGL;

			/**
			 * @class ContextOpenGL
			 * @extends std::enable_shared_from_this<ContextOpenGL>
			 * @extends RenderContext
			 * @brief An OpenGL context with an implementation depending of the platform.
			 */
			class ContextOpenGL : public RenderContext
			{
			public:
				static auto DummyContext() -> std::shared_ptr<RenderContext>;

				/**
				 * @fn ContextOpenGL() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				ContextOpenGL() noexcept;

				/**
				 * @fn ContextOpenGL(const ContextOpenGL & copy) noexcept
				 * @param[in] copy The ContextOpenGL to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ContextOpenGL(const ContextOpenGL & copy) noexcept = default;

				/**
				 * @fn ContextOpenGL(ContextOpenGL && move) noexcept
				 * @param[in] move The ContextOpenGL to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ContextOpenGL(ContextOpenGL && move) noexcept = default;

				/**
				 * @fn ~ContextOpenGL() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ContextOpenGL() noexcept;

				/**
				 * @fn ContextOpenGL & operator=(const ContextOpenGL & copy) noexcept
				 * @param[in] copy The ContextOpenGL to copy from.
				 * @return The ContextOpenGL copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ContextOpenGL & operator=(const ContextOpenGL & copy) noexcept = default;

				/**
				 * @fn ContextOpenGL & operator=(ContextOpenGL && move) noexcept
				 * @param[in] move The ContextOpenGL to move from.
				 * @return The ContextOpenGL moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ContextOpenGL & operator=(ContextOpenGL && move) noexcept = default;

				/**
				 * @fn Version<2> getCurrentVersion() const;
				 * @return The current version of the render context.
				 * @brief Get the version used of the render context.
				 * @throw
				 * @see Version<2> RenderContext::getCurrentVersion() const
				 */
				virtual auto getCurrentVersion() const -> Version<2> override;

				/**
				 * @fn void create(const RenderWindow & window)
				 * @param[in] window The window to linked to.
				 * @brief Create the OpenGL context for a window.
				 * @throw
				 * @see void RenderContext::create(const RenderWindow & window)
				 */
				virtual void create(const ContextSettings & settings) override;

				/**
				 * @fn void terminate()
				 * @brief Delete the render context.
				 * @throw
				 * @see void RenderContext::terminate()
				 */
				virtual void terminate() override;

				/**
				 * @fn void swapBuffers()
				 * @brief If multi buffering is enable, it swap between buffers to display the new frame.
				 * @throw
				 * @see void RenderContext::swapBuffers()
				 */
				virtual void swapBuffers() override;

				/**
				 * @fn void setCurrent()
				 * @brief Define this content as the current one.
				 * @throw
				 * @see void BaseContext::setCurrent()
				 */
				virtual void setCurrent() override;

				/**
				 * @fn void logInfos()
				 * @brief Log the informations related to OpenGL and the device used.
				 * @throw
				 * @see void RenderContext::logInfos()
				 */
				virtual void logInfos() const override;

				inline static auto getMaxVersionAvailable() noexcept -> const Version<2> &;

				inline static auto isOpenGL33Available() -> bool;
				inline static auto isOpenGL40Available() -> bool;
				inline static auto isOpenGL41Available() -> bool;
				inline static auto isOpenGL42Available() -> bool;
				inline static auto isOpenGL43Available() -> bool;
				inline static auto isOpenGL44Available() -> bool;
				inline static auto isOpenGL45Available() -> bool;
				inline static auto isOpenGL46Available() -> bool;

				void setDebugContext();

			protected:
				void createOldContext();
				void createModernContext(const ContextSettings & settings);

			private:
				/**
				 * @property _data
				 * @brief The platform implentation for the OpenGL context.
				 */
				Pimpl<DataContextOpenGL> _data;

				Version<2> _currentVersion;

				static Version<2> _maxVersionAvailable;
			};
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#include "renderer/opengl/context_opengl.inl"

#endif // CONTEXT_OPENGL_HPP
