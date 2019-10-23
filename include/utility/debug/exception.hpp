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

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/enumeration.hpp"

namespace ece
{
    namespace utility
    {
        namespace debug
        {
        	/**
        	 * @class Exception
        	 * @extends std::runtime_error
        	 * @brief Base class to build an exception with arguments binding.
        	 * @see http://en.cppreference.com/w/cpp/error/runtime_error
        	 * @remark Another pattern should be used to implements the set of exceptions. Indeed, the scalability is not take into account.
        	 */
        	class ECE_UTILITY_API Exception : public std::runtime_error
        	{
        	public:
        		/**
        		 * @fn Exception()
        		 * @brief Main constructor for the base class exception.
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		inline Exception();

        		/**
        		 * @fn void setMessage(const std::string & message, Args... args)
        		 * @tparam Args A list of types for the arguments of the exception message.
        		 * @param[in] message The exception message to set to.
        		 * @param[in] args The list of arguments to bind to the exception message.
        		 * @brief Set the exception message, and bind the parameters into.
        		 * @throw noexcept
        		 *
        		 * All the arguments are binded into the message, according to the pattern provided.
        		 * A '%' indicates the position of an argument. Arguments are processed in the reading direction, from left to right.
        		 * The next argument is binded only if there is still a '%' tag available in the pattern. Else, the pattern
        		 * is considered as completed, and is returned.
        		 */
        		template <class ...Args>
        		inline void setMessage(const std::string & message, Args... args) noexcept;

        		/**
        		 * @fn const char * what() const noexcept
        		 * @return The exception message if it exists or an empty if not.
        		 * @brief A getter to the exception message.
        		 * @throw noexcept
        		 *
        		 * Get the exception message with all the parameters binded.
        		 */
        		inline virtual auto what() const noexcept -> const char * override;

        	private:
        		/**
        		 * @property _message
        		 * @brief The exception message with parameters already binded.
        		 */
        		std::string _message;

        		/**
        		 * @fn std::string mapString(const std::string & content)
        		 * @param[in] content The pattern of string to return.
        		 * @return the content.
        	   	 * @brief The end step of the recursive mapping throw template binding.
        		 * @throw noexcept
        		 */
        		inline auto mapString(const std::string & content) noexcept;

        		/**
        		 * @fn std::string mapString(const std::string & content, V value, Args... args)
        		 * @tparam V The type of the first argument of the exception message.
        		 * @tparam Args A list of types for the arguments of the exception message.
        		 * @param[in] content The pattern of string to return.
        		 * @param[in] value The first argument to bind into the content.
        		 * @param[in] args The other arguments to bind into the content.
        		 * @return the content with all the arguments binded.
        		 * @brief The recursive method to bind all the arguments inside the content.
        		 * @throw noexcept
        		 */
        		template <class V, class... Args>
        		auto mapString(const std::string & content, V value, Args... args) noexcept;
        	};

			enum FileCodeError : unsigned short int
			{
				BAD_PATH = 0,
				PARSE_ERROR = 1
			};

        	/**
        	 * @class FileException
        	 * @extends Exception
        	 * @brief An exception used for error while handling files.
        	 * @see Exception
        	 */
        	class ECE_UTILITY_API FileException : public Exception
        	{
        	public:
        		/**
        		 * @fn FileException(const FileCodeError codeError, const std::string & filename)
        		 * @param[in] codeError The type of error which has been raised.
        		 * @param[in] filename the filename where the error raised form.
        		 * @brief A constructor to build a FileException.
        		 * @see FileCodeError
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		FileException(const FileCodeError codeError, const std::filesystem::path & filename);

				/**
				 * @fn FileException(const FileCodeError codeError, const std::string & filename)
				 * @param[in] codeError The type of error which has been raised.
				 * @param[in] filename the filename where the error raised form.
				 * @param[in] details Details provided by the system about the file error.
				 * @brief A constructor to build a FileException.
				 * @see FileCodeError
				 * @throw std::bad_alloc May throw std:bad_alloc
				 * @see std::runtime_error::runtime_error(const std::string & what_arg)
				 */
				FileException(const FileCodeError codeError, const std::filesystem::path & filename, const std::string & details);
        	};

        	/**
        	 * @class BadInputException
        	 * @extends Exception
        	 * @brief An exception used to indicate an error of input.
        	 * @see Exception
        	 */
        	class ECE_UTILITY_API BadInputException : public Exception
        	{
        	public:
        		/**
        		 * @fn BadInputException(const std::string & details)
        		 * @param[in] details Give some details about the origin of the error.
        		 * @brief A constructor to build a BadInputException.
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		BadInputException(const std::string & details);
        	};

        	/**
        	 * @class InitilizationException
        	 * @extends Exception
        	 * @brief An exception used to indicate an error of initialization of a system or a service.
        	 * @see Exception
        	 */
        	class ECE_UTILITY_API InitializationException : public Exception
        	{
        	public:
        		/**
        		 * @fn InitializationException(const std::string & target)
        		 * @param[in] target The target which has been initialized badly.
        		 * @brief A constructor to build an InitializationException.
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		InitializationException(const std::string & target);
        	};

        	/**
        	 * @class MemoryAccessException
        	 * @extends Exception
        	 * @brief An exception used to indicates a wrong access to the memory.
        	 * @see Exception
        	 */
        	class ECE_UTILITY_API MemoryAccessException : public Exception
        	{
        	public:
        		/**
        		 * @fn MemoryAccessException(const std::string & target)
        		 * @param[in] target The target location to try to access to.
        		 * @brief A constructor to build a MemoryAccessException.
        		 * @see MemoryAccessException(const std::string & target, const std::string & origin)
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		MemoryAccessException(const std::string & target);


        		/**
        		 * @fn MemoryAccessException(const std::string & target, const std::string & origin)
        		 * @param[in] target The target location to try to access to.
        		 * @param[in] origin The origin location  try to access to.
        		 * @brief A constructor to build a MemoryAccessException.
        		 * @see MemoryAccessException(const std::string & target)
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		MemoryAccessException(const std::string & target, const std::string & origin);
        	};

        	/**
        	 * @class OutOfRangeException
        	 * @extends Exception
        	 * @brief An exception used to indicates an access to a location out of the range of the owner container.
        	 * @see Exception
        	 */
        	class ECE_UTILITY_API OutOfRangeException : public Exception
        	{
        	public:
        		/**
        		 * @fn OutOfRangeException(const std::string & type)
        		 * @param[in] type The type of container which generate the error.
        		 * @brief A constructor to build an OutOfRangeException.
        		 * @see OutOfRangeException(const std::string & type, const int id)
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		OutOfRangeException(const std::string & type);

        		/**
        		 * @fn OutOfRangeException(const std::string & type, const int id)
        		 * @param[in] type The type of container which generate the error.
        		 * @param[in] id The id which is out of range.
        		 * @brief A constructor to build an OutOfRangeException.
        		 * @see makeException(const std::string & type)
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		OutOfRangeException(const std::string & type, const int id);
        	};

        	/**
        	 * @class ResourceException
        	 * @extends Exception
        	 * @brief An exception used to indicates an error while handling a resource.
        	 * @see Exception
        	 */
        	class ECE_UTILITY_API ResourceException : public Exception
        	{
        	public:
        		/**
        		 * @fn ResourceException(const std::string & target, const unsigned short int id)
        		 * @param[in] target The target resource which has generated an error while being handled.
        		 * @param[in] id The id of the target resource handled.
        		 * @brief A constructor to build a ResourceException.
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		ResourceException(const std::string & target, const unsigned short int id);
        	};

        	/**
        	 * @class DivideByZeroException
        	 * @extends Exception
        	 * @brief An exception to indicate a division by zero which is not possible.
        	 * @see Exception
        	 */
        	class ECE_UTILITY_API DivideByZeroException : public Exception
        	{
        	public:
        		/**
        		 * @fn DivideByZeroException(const std::string & origin)
        		 * @param[in] origin The origin of the division by zero.
        		 * @brief A constructor to build a DivideByZeroException.
        		 * @throw std::bad_alloc May throw std:bad_alloc
        		 * @see std::runtime_error::runtime_error(const std::string & what_arg)
        		 */
        		DivideByZeroException(const std::string & origin);
        	};
        } // namespace debug
    } // namespace utility
} // namespace ece

#include "utility/debug/exception.inl"

#endif // EXCEPTION_HPP
