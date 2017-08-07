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
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

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

#include <stdexcept>
#include <string>

#include "Type.hpp"

namespace ece
{
	/**
	 * @class Exception
	 * @extends std::runtime_error
	 * @tparam T The child class which extends Exception
	 * @brief Base class to build an exception with arguments binding.
	 * @see http://en.cppreference.com/w/cpp/error/runtime_error
	 */
	template <class T>
	class Exception : protected std::runtime_error
	{
	public:
		/**
		 * @see std::runtime_error::what
		 */
		using std::runtime_error::what;

		~Exception() = default;

		/**
		 * @fn T makeException(const std::string & message, Args... args)
		 * @tparam Args A list of types for the arguments of the exception message.
		 * @param[in] message The exception message to set to.
		 * @param[in] args The list of arguments to bind to the exception message.
		 * @return An child exception of the class template parameter.
		 * @brief Create an Exception with the arguments binded in the message.
		 *
		 * Returns an Exception with a personalized message. All the arguments are binded into the message,
		 * according to the pattern provided. A '%' indicates the position of an argument. Arguments are processed
		 * in the reading direction, from left to right.
		 * The next argument is binded only if there is still a '%' tag available in the pattern. Else, the pattern
		 * is considered as completed, and is returned.
		 */
		template<class... Args>
		static T makeException(const std::string & message, Args... args);

	protected:
		Exception() = delete;
		/**
		* @fn Exception(const std::string & whatArg)
		* @param[in] whatArg The exception message to set to.
		* @brief Constructor for an Exception.
		*/
		inline Exception(const std::string & whatArg);
		Exception(const Exception & copy) = default;
		Exception(Exception && move) = default;

		Exception & operator=(const Exception & copy) = default;
		Exception & operator=(Exception && move) = default;

	private:
		/**
		 * @fn std::string mapString(const std::string & content)
		 * @param[in] content The pattern of string to return.
		 * @return the content.
	   	 * @brief The end step of the recursive mapping throw template binding.
		 */
		inline static std::string mapString(const std::string & content);

		/**
		 * @fn std::string mapString(const std::string & content, V value, Args... args)
		 * @tparam V The type of the first argument of the exception message.
		 * @tparam Args A list of types for the arguments of the exception message.
		 * @param[in] content The pattern of string to return.
		 * @param[in] value The first argument to bind into the content.
		 * @param[in] args The other arguments to bind into the content.
		 * @return the content with all the arguments binded.
		 * @brief The recursive method to bind all the arguments inside the content.
		 */
		template <class V, class... Args>
		static std::string mapString(const std::string & content, V value, Args... args);
	};

	/**
	 * @class FileException
	 * @extends Exception<FileException>
	 * @brief An exception used for error while handling files.
	 * @see Exception
	 */
	class FileException : public Exception<FileException>
	{
	public:
		/**
		 * @fn FileException makeException(const FileCodeError codeError, const std::string & filename)
		 * @param[in] codeError The type of error which has been raised.
		 * @param[in] filename the filename where the error raised form.
		 * @return The FileException built.
		 * @brief A factory to build a FileException.
		 * @see FileCodeError
		 */
		static FileException makeException(const FileCodeError codeError, const std::string & filename);
	};

	/**
	 * @class BadInputException
	 * @extends Exception<BadInputException>
	 * @brief An exception used to indicate an error of input.
	 * @see Exception
	 */
	class BadInputException : public Exception<BadInputException>
	{
	public:
		/**
		 * @fn BadInputException makeException(const std::string & details)
		 * @param[in] details Give some details about the origin of the error.
		 * @return The BadInputException built.
		 * @brief A factory to build a BadInputException.
		 */
		static BadInputException makeException(const std::string & details);
	};

	/**
	 * @class InitilizationException
	 * @extends Exception<InitilizationException>
	 * @brief An exception used to indicate an error of initialization of a system or a service.
	 * @see Exception
	 */
	class InitializationException : public Exception<InitializationException>
	{
	public:
		/**
		 * @fn InitializationException makeException(const std::string & target)
		 * @param[in] target The target which has been initialized badly.
		 * @return The InitializationException built.
		 * @brief A factory to build an InitializationException.
		 */
		static InitializationException makeException(const std::string & target);
	};

	/**
	 * @class MemoryAccessException
	 * @extends Exception<MemoryAccessException>
	 * @brief An exception used to indicates a wrong access to the memory.
	 * @see Exception
	 */
	class MemoryAccessException : public Exception<MemoryAccessException>
	{
	public:
		/**
		 * @fn MemoryAccessException makeException(const std::string & target)
		 * @param[in] target The target location to try to access to.
		 * @return A MemoryAccessException built.
		 * @brief A factory to build a MemoryAccessException.
		 * @see MemoryAccessException::makeException(const std::string & target, const std::string & origin) 
		 */
		static MemoryAccessException makeException(const std::string & target);

		/**
		 * @fn MemoryAccessException makeException(const std::string & target, const std::string & origin)
		 * @param[in] target The target location to try to access to.
		 * @param[in] origin The origin location  try to access to.
		 * @return A MemoryAccessException built.
		 * @brief A factory to build a MemoryAccessException.
		 * @see MemoryAccessException::makeException(const std::string & target) 
		 */
		static MemoryAccessException makeException(const std::string & target, const std::string & origin);
	};

	/**
	 * @class OutOfRangeException
	 * @class Exception<OutOfRangeException>
	 * @brief An exception used to indicates an access to a location out of the range of the owner container.
	 * @see Exception
	 */
	class OutOfRangeException : public Exception<OutOfRangeException>
	{
	public:
		/**
		 * @fn OutOfRangeException makeException(const std::string & type)
		 * @param[in] type The type of container which generate the error.
		 * @return The OutOfRangeException built.
		 * @brief A factory to build an OutOfRangeException.
		 * @see OutOfRangeException::makeException(const std::string & type, const int id)
		 */
		static OutOfRangeException makeException(const std::string & type);

		/**
		 * @fn OutOfRangeException OutOfRangeException::makeException(const std::string & type, const int id)
		 * @param[in] type The type of container which generate the error.
		 * @param[in] id The id which is out of range.
		 * @return The OutOfRangeException built.
		 * @brief A factory to build an OutOfRangeException.
		 * @see OutOfRangeException::makeException(const std::string & type)
		 */
		static OutOfRangeException makeException(const std::string & type, const int id);
	};

	/**
	 * @class ResourceException
	 * @extends Exception<ResourceException>
	 * @brief An exception used to indicates an error while handling a resource.
	 * @see Exception
	 */
	class ResourceException : public Exception<ResourceException>
	{
	public:
		/**
		 * @fn ResourceException makeException(const std::string & target, const unsigned short int id)
		 * @param[in] target The target resource which has generated an error while being handled.
		 * @param[in] id The id of the target resource handled.
		 * @return The ResourceException built.
		 * @brief A factory to build a ResourceException.
		 */
		static ResourceException makeException(const std::string & target, const unsigned short int id);
	};

	/**
	 * @class DivideByZeroException
	 * @extends Exception<DivideByZeroException>
	 * @brief An exception to indicate a division by zero which is not possible.
	 * @see Exception
	 */
	class DivideByZeroException : public Exception<DivideByZeroException>
	{
	public:
		/**
		 * @fn DivideByZeroException makeException(const std::string & origin)
		 * @param[in] origin The origin of the division by zero.
		 * @return The DivideByZeroException built.
		 * @brief A factory to build a DivideByZeroException.
		 */
		static DivideByZeroException makeException(const std::string & origin);
	};
}

#include "Debug\Exception.inl"

#endif // EXCEPTION_HPP