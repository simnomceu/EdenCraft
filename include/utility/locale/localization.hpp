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

#ifndef LOCALIZATION_HPP
#define LOCALIZATION_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/locale/language.hpp"
#include "utility/locale/country.hpp"

namespace ece
{
    namespace utility
    {
        namespace locale
        {
        	/**
        	 * @class Localization
        	 * @brief Localization is a combination of a country and a language.
        	 * Some recent language (esperanto, lojban) are not country dependent.
        	 * @remark The country should be optional as a language like lojban is not country dependent.
        	 */
        	class ECE_UTILITY_API Localization
        	{
        	public:
        		/**
        		 * @fn Localization()
        		 * @brief Default empty constructor. It is initialized empty.
        		 * @throw noexcept
        		 */
        		Localization() noexcept = default;

        		/**
        		 * @fn Localization(const Language & language, const Country & country)
        		 * @param[in] language The language to set.
        		 * @param[in] country The country to set.
        		 * @brief Default constructor. It is initialized as language_COUNTRY.
        		 * @throw
        		 */
        		inline Localization(const Language & language, const Country & country);

        		/**
        		 * @fn Localization(const Localization & copy)
        		 * @param[in] copy The localization to copy from.
        		 * @brief Default copy constructor.
        		 * @throw
        		 */
        		Localization(const Localization & copy) = default;

        		/**
        		 * @fn Localization(Localization && move)
        		 * @param[in] move The localization to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Localization(Localization && move) noexcept = default;

        		/**
        		 * @fn ~Localization()
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Localization() noexcept = default;

        		/**
        		 * @fn Localization & operator=(const Localization & copy)
        		 * @param[in] copy The localization to copy from.
        		 * @return The localization copied.
        		 * @brief Default copy assignment operator.
        		 * @throw
        		 */
        		Localization & operator=(const Localization & copy) = default;

        		/**
        		 * @fn Localization & operator=(Localization && move)
        		 * @param[in] move The localization to move.
        		 * @return The localization moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept;
        		 */
        		Localization & operator=(Localization && move) noexcept = default;

        		/**
        		 * @fn const Language & getLanguage() const
        		 * @return The localization language.
        		 * @brief Get the localization language.
        		 */
        		inline auto getLanguage() const noexcept;

        		/**
        		 * @fn const Country & getCountry() const
        		 * @return The localization country.
        		 * @brief Get the localization country.
        		 */
        		inline auto getCountry() const noexcept;

        		/**
        		 * @fn void setLanguage(const Language & language)
        		 * @param[in] language The language to set.
        		 * @brief Set the localization language.
        		 */
        		inline void setLanguage(const Language & language);

        		/**
        		 * @fn void setCountry(const Country & country)
        		 * @param[in] country The country to set.
        		 * @brief Set the country language.
        		 */
        		inline void setCountry(const Country & country) noexcept;

        	private:
        		/**
        		 * @property _language
        		 * @brief The localization language.
        		 */
        		Language _language;

        		/**
        		 * @property _country
        		 * @brief The country language.
        		 */
        		Country _country;
        	};
        } // namespace locale
    } // namespace utility
} // namespace ece

#include "utility/locale/localization.inl"

#endif // LOCALIZATION_HPP
