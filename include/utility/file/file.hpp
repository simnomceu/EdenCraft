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

/**
 * @file utility/file/file.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date November, 28th 2017
 * @copyright ----------
 * @brief Encapsulates the file resource in a class.
 *
 **/

#ifndef FILE_HPP
#define FILE_HPP

#include "utility/mathematics/vertex3u.hpp"
#include "utility/enum.hpp"

#include <string>
#include <vector>

namespace ece
{
	/**
	 * @class File
	 * @brief Handle file as a stream.
	 * @remark Because of Single Responsability Principle, the filename should be encapsulated in another class (like Path)
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
		inline ~File();

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

		std::string parseToString();
		template<class T> std::vector<T> parseToVector();

		/**
		 * @remark To move in the future class Path as a member method.
		 */
		static const bool exists(const std::string & filename);

		template <class T> File & operator>>(T & value);
		template <class T> File & operator<<(T & value);

	private:
		std::string filename;
		std::fstream stream;
	};

	template<> std::vector<FloatVertex3u> File::parseToVector<FloatVertex3u>();
}

#include "utility/file/file.inl"

#endif // FILE_HPP
