/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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


#ifndef LOCALE_LOADER_HPP
#define LOCALE_LOADER_HPP

#include <string>
#include <utility>

#include "utility/locale/localization.hpp"
#include "utility/locale/resource_container.hpp"

namespace ece
{
	/**
	 * @class LocaleLoader
	 * @brief Loader for JSON files of string literals, regarding the localization.
	 * @remark This could be optimize, i guess.
	 */
	class LocaleLoader
	{
	public:
		/**
		 * @fn void setPath(const std::string & path)
		 * @param[in] path The root of the locale files.
		 * @brief Set the root of the locale files.
		 * @throw noexcept
		 */
		static void setPath(const std::string & path) noexcept;

		LocaleLoader() = delete;

		/**
		 * @fn LocaleLoader(const std::string & filename, const Localization & locale = Localization(ENGLISH, USA))
		 * @param[in] filename The filename to load.
		 * @param[in] locale The locale to use for the file.
		 * @brief Load a file regarding the locale defined.
		 * @throw
		 */
		LocaleLoader(const std::string & filename, const Localization & locale = Localization(ENGLISH, USA));

		/**
		 * @fn LocaleLoader(const LocaleLoader & copy)
		 * @param[in] copy The loader to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		LocaleLoader(const LocaleLoader & copy) = default;

		/**
		 * @fn LocaleLoader(LocaleLoader && move)
		 * @param[in] move The loader to move.
		 * @brief Default move constructor.
		 * @throw
		 */
		LocaleLoader(LocaleLoader && move) = default;

		/**
		 * @fn ~LocaleLoader()
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~LocaleLoader() noexcept = default;

		/**
		 * @fn LocaleLoader & operator=(const LocaleLoader & copy)
		 * @param[in] copy The loader to copy from.
		 * @return The loader copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		LocaleLoader & operator=(const LocaleLoader & copy) = default;

		/**
		 * @fn LocaleLoader & operator=(LocaleLoader && move)
		 * @param[in] move The loader to move.
		 * @return The loader moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept.
		 */
		LocaleLoader & operator=(LocaleLoader && move) noexcept = default;

		/**
		 * @fn LocaleResource & getResource()
		 * @return The locale resource loaded.
		 * @brief Get access to the locale resource loaded from the file.
		 * @throw
		 */
		inline LocaleResource & getResource();

		/**
		 * @fn void changeLocale(const Localization & locale)
		 * @param[in] locale The localization to set.
		 * @brief Change the localization.
		 * @throw
		 */
		void changeLocale(const Localization & locale);

	private:
		/**
		 * @property _path
		 * @brief The root of the locale resources.
		 */
		static std::string _path;

		/**
		 * @property _locale
		 * @brief The localization to use.
		 */
		Localization _locale;

		/**
		 * @property _resource
		 * @brief The resource loaded from the file.
		 */
		ResourceContainer _resource;

		/**
		 * @property _filename
		 * @brief The name of the resource file currently loaded.
		 */
		std::string _filename;

		/**
		 * @fn void generateResource(const std::string & file)
		 * @param[in] file The file to use to generate the resource.
		 * @brief Generate the resource from a file.
		 * @throw
		 */
		void generateResource(const std::string & file);
	};
}

#include "utility/locale/locale_loader.inl"

#endif // LOCALE_LOADER_HPP