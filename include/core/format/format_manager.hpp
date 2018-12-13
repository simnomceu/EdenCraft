/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.
															 d8P'  `Y8b
															888           .ooooo.  oooo d8b  .ooooo.
															888          d88' `88b `888""8P d88' `88b
															888          888   888  888     888ooo888
															`88b    ooo  888   888  888     888    .o
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P'



				This file is part of EdenCraft Engine - Core module.
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

#ifndef FORMAT_MANAGER_HPP
#define FORMAT_MANAGER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "utility/file_system.hpp"

namespace ece
{
	namespace core
	{
		namespace format
		{
			/**
			 * @class FormatManager
			 * @brief
			 */
			class ECE_CORE_API FormatManager
			{
			public:
				/**
				 * @fn FormatManager()
				 * @brief Default constructor.
				 * @throw
				 */
				FormatManager() = default;

				/**
				 * @fn FormatManager(const FormatManager & copy) noexcept
				 * @param[in] copy The FormatManager to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				FormatManager(const FormatManager & copy) noexcept = default;

				/**
				 * @fn FormatManager(FormatManager && move) noexcept
				 * @param[in] move The FormatManager to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				FormatManager(FormatManager && move) noexcept = default;

				/**
				 * @fn ~FormatManager() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~FormatManager() noexcept = default;

				/**
				 * @fn FormatManager & operator=(const FormatManager & copy) noexcept
				 * @param[in] copy The FormatManager to copy from.
				 * @return The FormatManager copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				FormatManager & operator=(const FormatManager & copy) noexcept = default;

				/**
				 * @fn FormatManager & operator=(FormatManager && move) noexcept
				 * @param[in] move The FormatManager to move.
				 * @return The FormatManager moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				FormatManager & operator=(FormatManager && move) noexcept = default;

				template <class T, typename enabled = std::enable_if_t<std::is_base_of_v<Loader, T>>>
				void registerLoader(const std::string & extension);

				template <class T, typename enabled = std::enable_if_t<std::is_base_of_v<Saver, T>>>
				void registerSaver(const std::string & extension);

				template <class T>
				inline auto getLoader(const std::string & filename);

				template <class T>
				inline auto getSaver(const std::string & filename);

				inline auto hasLoaderFor(const std::string & extension) const;
				inline auto hasSaverFor(const std::string & extension) const;

			private:
				std::unordered_map<std::string, std::shared_ptr<Loader>> _loaders;
				std::unordered_map<std::string, std::shared_ptr<Saver>> _savers;
			};
		} // namespace format
	} // namespace core
} // namespace ece

#include "core/format/format_manager.inl"

#endif // FORMAT_MANAGER_HPP