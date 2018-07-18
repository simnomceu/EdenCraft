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

#ifndef PATH_HPP
#define PATH_HPP

#include "utility/config.hpp"

#include <string>
#include <vector>

namespace ece
{
    namespace utility
    {
        namespace file_system
        {
        	/**
        	 * @class Path
        	 * @brief Defines a path, which could be a folder or a file.
        	 * @remark Maybe adding an iterator to navigate in the file system.
        	 * @remark Should define a non-member operation make_path to create a Path object and throw an exception if it is not valid.
        	 * @remark Look at the Filesystem standard library from C++17. Be careful with backward compatibility.
        	 */
        	class ECE_UTILITY_API Path
        	{
        	public:
        		/**
        		 * @fn Path currentPath()
        		 * @return The current path during runtime.
        		 * @brief Get the current location during runtime.
        		 * @throw
        		 */
        		static Path currentPath();

        		/**
        		 * @fn Path() noexcept
        		 * @brief Initialize an empty location. It is not a valid path.
        		 * @remark If make_path is implemented, this constructor should not exist.
        		 * @throw noexcept
        		 */
        		inline Path() noexcept;

        		/**
        		 * @fn Path(const std::string & pathname)
        		 * @param[in] pathname The location to set.
        		 * @brief Initialize a path to a specific location. It doesn't mean the path is valid.
        		 * @throw
        		 */
        		explicit Path(const std::string & pathname);

        		/**
        		 * @fn Path(const Path & copy)
        		 * @param[in] copy The path to copy.
        		 * @brief Default copy constructor.
        		 * @throw
        		 */
        		Path(const Path & copy) = default;

        		/**
        		 * @fn Path(Path && move)
        		 * @param[in] move The path to move.
        		 * @brief Default move constructor.
        		 * @throw
        		 */
        		Path(Path && move) = default;

        		/**
        		 * @fn ~Path() noexcept
        		 * @brief Default destructor
        		 * @throw noexcept
        		 */
        		~Path() noexcept = default;

        		/**
        		 * @fn Path & operator=(const Path & copy)
        		 * @param[in] copy The path to copy from.
        		 * @return The path copied
        		 * @brief Default copy assigment operator
        		 * @throw
        		 */
        		Path & operator=(const Path & copy) = default;

        		/**
        		 * @fn Path & operator=(Path && move)
        		 * @param[in] move The path to move.
        		 * @return The path moved.
        		 * @brief Default move assigment operator.
        		 * @throw
        		 */
        		Path & operator=(Path && move) = default;

        		/**
        		 * @fn int getDepth() const
        		 * @return The path depth
        		 * @brief Access the depth of the current path. It is equivalent to number of segment level in the path.
        		 * @throw
        		 */
        		inline int getDepth() const;

        		/**
        		 * @fn std::string getPathname() const
        		 * @return The current pathname.
        		 * @brief Access to the current pathname.
        		 * It returns the complete current path, whatever it is, folder or file. It doesn't mean the path is valid.
        		 * @throw
        		 */
        		std::string getPathname() const;

        		/**
        		 * @fn std::string getPath() const
        		 * @return The current path.
        		 * @brief Access to the current path.
        		 * If it defines a file, it returns the path to this file. It doesn't mean the path is valid.
        		 * @throw
        		 */
        		std::string getPath() const;

        		/**
        		 * @fn std::string getFilename() const
        		 * @return The filename defined by the path.
        		 * @brief Access to the filename defined by the path, or nothing if it defines a folder. It doesn't mean the path is valid.
        		 * @throw
        		 */
        		inline std::string getFilename() const;

        		/**
        		 * @fn std::string & operator[](const int index)
        		 * @param[in] index The segment level of the path.
        		 * @return A specific segment level of the path.
        		 * @brief Access to a part of the path.
        		 * @see const std::string & operator[](const int index) const
        		 * @throw
        		 */
        		inline std::string & operator[](const int index);

        		/**
        		 * @fn const std::string & operator[](const int index) const
        		 * @param[in] index The segment level of the path.
        		 * @return A specific segment level of the path.
        		 * @brief Access to a part of the path.
        		 * @see std::string & operator[](const int index)
        		 * @throw
        		 */
        		inline const std::string & operator[](const int index) const;

        		/**
        		 * @fn bool exists() const
        		 * @return True, if it is a valid path, false else.
        		 * @brief Indicates if the path is valid, or not.
        		 * A valid path could defines a file, or a folder.
        		 * @throw
        		 */
        		inline bool exists() const;

        		/**
        		 * @fn bool isFile() const
        		 * @return True if the current path defines a file, false else.
        		 * @brief Indicates if the current path is a file, or not.
        		 * @throw
        		 */
        		inline bool isFile() const;

        		/**
        		 * @fn bool isFolder()
        		 * @return True if the current path defines a folder, false else.
        		 * @brief Indicates if the current path is a folder, or not.
        		 * @throw
        		 */
        		inline bool isFolder() const;

        	private:
        		/**
        		 * @property _path
        		 * @brief Current path splitted to each segment level.
        		 * @throw
        		 */
        		std::vector<std::string> _path;
        	};
        } // namespace file_system
    } // namespace utility
} // namespace ece

#include "utility/file_system/path.inl"

#endif // PATH_HPP
