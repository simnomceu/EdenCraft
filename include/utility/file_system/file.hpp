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

#ifndef FILE_HPP
#define FILE_HPP

#include "utility/mathematics/vector3u.hpp"
#include "utility/enum.hpp"

#include <string>
#include <vector>

namespace ece
{
	/**
	 * @class File
	 * @brief Handle file as a stream.
	 * @remark Because of Single Responsability Principle, the filename should be encapsulated in another class (like Path)
	 * @remark Something like Memory mapping could be implemented for big file: 
	 *          http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2044.html
	 */
	class File
	{
	public:
		/**
		 * @fn File()
		 * @brief Main constructor. The file is not defined, and no stream is opened.
		 * @see File::File(const std::string & filename, const OpenMode & mode = File::in | File::out)
		 * @see File::File(File && move)
		 */
		inline File();

		/**
		 * @fn File(const std::string & filename, const OpenMode & mode = File::in | File::out)
		 * @param[in] filename The name of the file to open.
		 * @param[in] mode The open mode to apply to the stream.
		 * @brief Constructor. Open a stream to the given file.
		 * @see File::File()
		 * @see File::File(File && move)
		 */
		explicit File(const std::string & filename, const OpenMode & mode = OpenMode::in | OpenMode::out);

		/**
		 * @fn File(const File & copy)
		 * @brief This constructor is deleted. The class is not copyable.
		 * @see File::File()
		 * @see File::File(const std::string & filename, const OpenMode & mode = File::in | File::out)
		 * @see File::File(File && move)
		 */
		File(const File & copy);

		/**
		 * @fn File(File && move)
		 * @param[in] move The stream to move from.
		 * @brief Move constructor. The stream is also moved.
		 * @see File::File()
		 * @see File::File(const std::string & filename, const OpenMode & mode = File::in | File::out)
		 */
		inline File(File && move);
		
		/**
		 * @fn ~File()
		 * @brief Destructor. If the stream is still opened, it will be closed.
		 */
		inline ~File() noexcept;

		/**
		 * @fn File & operator=(const File & copy)
		 * @brief This assigment operator is deleted. The class is not copyable.
		 * @see File & operator=(File && move)
		 */
		File & operator=(const File & copy);

		/**
		 * @fn File & operator=(File && move)
		 * @param[in] move The stream to move from.
		 * @return The stream moved.
		 * @brief Move assigment operator. The stream is also moved.
		 */
		File & operator=(File && move);

		/**
		 * @fn const bool open(const std::string & filename, const OpenMode & mode)
		 * @param[in] filename The name of the file to open.
		 * @param[out] mode The open mode to apply to the stream.
		 * @return True if the file is opened, false else.
		 * @brief Open a stream to the given file.
		 */
		const bool open(const std::string & filename, const OpenMode & mode = OpenMode::in | OpenMode::out);
		
		/**
		 * @fn const bool isOpen() const
		 * @return True, if the current file is opened, false else.
		 * @brief Indicates if the current file is opened or not. If no file is set, it returns FALSE.
		 */
		inline const bool isOpen() const;

		/** 
		 * @fn void close()
		 * @brief Close the current file and terminate the stream. If no file is opened, nothing happens.
		 */
		void close();
		
		/**
		 * @fn std::string parseToString()
		 * @return The file content as a string.
		 * @brief Get the entire content of the file as a string.
		 */
		std::string parseToString();

		/**
		 * @fn std::vector<T> parseToVector()
		 * @tparam T Type of the vector to return.
		 * @return A vector of element extracted from the file. 
		 * @brief Extracts a vector of element from the file. If the format doesn't match, an exception is hired.
		 * If the file is not opened, an empty vector is returned.
		 */
		template<class T> std::vector<T> parseToVector();

		/**
		 * @fn const bool exists(const std::string & filename)
		 * @param[in] filename The file to check for existence.
		 * @return True, if the file exists, or false else.
		 * @remark To move in the future class Path as a member method.
		 * @brief Check if the file is existing or not.
		 */
		static const bool exists(const std::string & filename);

		/**
		 * @fn File & operator>>(T & value)
		 * @tparam T The type of the value to read from the file.
		 * @param value To put the reading to.
		 * @return The current file stream.
		 * @brief Read the value from the file. If the type doesn't match, an exception is hired.
		 * The file cursor goes after the element read. If the file is not opened an exception is hired.
		 */
		template <class T> File & operator>>(T & value);

		/**
		 * @fn File & operator<<(T & value)
		 * @tparam T The type of the value to write in the file.
		 * @param value The value to write in the file.
		 * @return The current file stream.
		 * @brief Write the value in the file. If the type doesn't match, an exception is hired.
		 * The file cursor goes after the element writen. If the file is not opened an exception is hired.
		 */
		template <class T> File & operator<<(T & value);

	protected:
		/**
		 * @property _filename
		 * @brief The filename opened in the file stream.
		 */
		std::string _filename;

		/**
		 * @property _stream
		 * @brief The file stream associated.
		 */
		std::fstream _stream;
	};

	/**
	 * @remark That template specialization could be moved as a friend method of FloatVertex3u.
	 * @see std::vector<T> File::parseToVector();
	 */
	template<> std::vector<FloatVertex3u> File::parseToVector<FloatVertex3u>();
}

#include "utility/file_system/file.inl"

#endif // FILE_HPP
