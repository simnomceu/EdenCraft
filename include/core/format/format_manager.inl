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

namespace ece
{
	namespace core
	{
		namespace format
		{
			template <class T, typename enabled>
			void FormatManager::registerLoader(const std::string & extension)
			{
				this->_loaders[extension] = std::make_shared<T>();
			}

			template <class T, typename enabled>
			void FormatManager::registerSaver(const std::string & extension)
			{
				this->_savers[extension] = std::make_shared<T>();
			}

			inline std::weak_ptr<Loader> FormatManager::getLoader(const std::string & filename)
			{
				std::string extension = filename.substr(filename.find_last_of('.') + 1);
				if (extension.empty()) {
					extension = filename;
				}

				return this->_loaders[extension];
			}

			inline std::weak_ptr<Saver> FormatManager::getSaver(const std::string & filename)
			{
				std::string extension = filename.substr(filename.find_last_of('.') + 1);
				if (extension.empty()) {
					extension = filename;
				}

				return this->_savers[extension];
			}

			inline bool FormatManager::hasLoaderFor(const std::string & extension) const
			{
				return this->_loaders.find(extension) != this->_loaders.end();
			}

			inline bool FormatManager::hasSaverFor(const std::string & extension) const
			{
				return this->_savers.find(extension) != this->_savers.end();
			}
		}
	}
}