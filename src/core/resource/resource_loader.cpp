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

#include "core/pch.hpp"
#include "core/resource/resource_loader.hpp"
#include "utility/file_system.hpp"
#include "core/format/service_format.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			using format::ServiceFormatLocator;

			std::vector<ResourceHandler> ResourceLoader::loadFromFile(const std::filesystem::path & filename)
			{
				auto extension = filename.extension().generic_string().substr(1);
				auto loader = ServiceFormatLocator::getService().getLoader(extension);

				auto openmode = ece::OpenMode::in;
				if (loader->isBinary()) {
					openmode = openmode | ece::OpenMode::binary;
				}

				auto file = ece::File{};
				if (!file.open(filename, openmode)) {
					throw std::runtime_error(filename.generic_string() + " has not been opened.");
				}

				return loader->load({ file.getStream(), filename.generic_string(), filename.generic_string() });
			}

			std::vector<ResourceHandler> ResourceLoader::loadFromString(const std::string & identifier, const std::string & extension, const std::string & content)
			{
				auto stream = std::istringstream(content);

				auto loader = ServiceFormatLocator::getService().getLoader(extension);
				return loader->load({ stream, identifier, "" });
			}

			std::vector<ResourceHandler> ResourceLoader::loadFromStream(const std::string & identifier, const std::string & extension, std::istream & stream)
			{
				auto loader = ServiceFormatLocator::getService().getLoader(extension);
				return loader->load({ stream, identifier, "" });
			}

			void ResourceLoader::saveToFile(const std::filesystem::path & filename, const std::vector<ResourceHandler> & resources)
			{
				auto extension = filename.extension().generic_string().substr(1);
				auto saver = ServiceFormatLocator::getService().getSaver(extension);

				auto openmode = ece::OpenMode::out;
				if (saver->isBinary()) {
					openmode = openmode | ece::OpenMode::binary;
				}
				if (std::filesystem::exists(filename)) {
					openmode = openmode | ece::OpenMode::trunc;
				}

				auto file = ece::File{};
				if (!file.open(filename, openmode)) {
					throw std::runtime_error(filename.generic_string() + " has not been opened.");
				}

				saver->save({ file.getStream(), filename.stem().generic_string(), filename.generic_string(), std::move(resources) });
			}

			void ResourceLoader::saveToString(std::string & content, const std::vector<ResourceHandler> & resources, const std::string & extension)
			{
				auto stream = std::ostringstream(content);

				auto saver = ServiceFormatLocator::getService().getSaver(extension);
				saver->save({ stream, resources[0].getPath(), "", std::move(resources) });
			}

			void ResourceLoader::saveToStream(std::ostream & stream, const std::vector<ResourceHandler> & resources, const std::string & extension)
			{
				auto saver = ServiceFormatLocator::getService().getSaver(extension);
				saver->save({ stream, resources[0].getPath(), "", std::move(resources) });
			}
		} // namespace resource
	} // namespace core
} // namespace ece