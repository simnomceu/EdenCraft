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

#ifndef ASSERTION_HPP
#define ASSERTION_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/debug/exception.hpp"
#include "utility/log.hpp"

namespace ece
{
    namespace utility
    {
        namespace debug
        {
            /**
             * @class AssertionException
             * @extends Exception
             * @brief An exception risen on assertion failure.
             * @see Exception
             */
            class ECE_UTILITY_API AssertionException : public Exception
            {
        	public:
                /**
                 * @fn AssertionException(const std::string & expression, const std::string file, const int line, const std::string & message)
                 * @param[in] expression The expression of the assertion that failed.
                 * @param[in] file The source file of the assertion.
                 * @param[in] line The line of the assertion in the file.
                 * @param[in] message A description message of the failure.
                 * @brief An exception used on assertion failure.
                  @throw
                 */
                AssertionException(const std::string & expression, const std::string file, const int line, const std::string & message);
        	};

#		define make_assert(EXPRESSION, MESSAGE) \
            if (!(EXPRESSION)) { \
                throw AssertionException(#EXPRESSION, __FILE__, __LINE__, MESSAGE); \
            }

#		define ece_assert(EXPRESSION, MESSAGE) \
			if (!(EXPRESSION)) { \
				ece::SYSTEM << "Assertion `" << #EXPRESSION << "` at " << __FILE__ << ":" << __LINE__ << " failed: \"" << MESSAGE << "\"" << ece::flushing; \
				abort(); \
			}

#		define assertExceptionThrown(EXPRESSION, EXCEPTION) \
			try { \
				EXPRESSION; \
				ece::SYSTEM << "Assertion `" << #EXPRESSION << "` at " << __FILE__ << ":" << __LINE__ << " doesn't throw any " << #EXCEPTION << "." << ece::flushing; \
				abort(); \
			} \
			catch (const EXCEPTION & e) { \
				ece::ERROR << e.what() << ece::flushing; \
			}

#		define assertAnyExceptionThrown(EXPRESSION) assertExceptionThrown(EXPRESSION, std::runtime_error)

#		define assertNoExceptionThrown(EXPRESSION) \
			try { \
				EXPRESSION; \
			} \
			catch (const std::runtime_error & e) { \
				ece::ERROR << e.what() << ece::flushing; \
				ece::SYSTEM << "Assertion `" << #EXPRESSION << "` at " << __FILE__ << ":" << __LINE__ << " throw an exception." << ece::flushing; \
				abort(); \
			}
        } // namespace debug
    } // namespace utility
} // namespace ece
#endif // ASSERTION_HPP
