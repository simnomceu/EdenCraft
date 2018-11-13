/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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
	namespace renderer
	{
		namespace shader
		{
			inline ShaderStage::ShaderStage() noexcept: _filename(), _source(), _type(Type::FRAGMENT), _handle(), _compilationRequired(false) {}

			inline ShaderStage::ShaderStage(const ShaderStage & copy) noexcept :
				_filename(copy._filename), _source(copy._source), _type(copy._type), _handle(copy._handle),
				_compilationRequired(copy._compilationRequired) {}

			inline ShaderStage::ShaderStage(ShaderStage && move) noexcept :
				_filename(std::move(move._filename)), _source(std::move(move._source)), _type(move._type), _handle(move._handle),
				_compilationRequired(move._compilationRequired)
			{
				move._filename.clear();
				move._handle = 0;
				move._compilationRequired = false;
			}

			inline ShaderStage::~ShaderStage() noexcept { this->terminate(); }

			inline const std::string & ShaderStage::getFilename() const { return this->_filename; }

			inline const std::string & ShaderStage::getSource() const { return this->_source; }

			inline ShaderStage::Type ShaderStage::getType() const { return this->_type; }

			inline Handle ShaderStage::getHandle() const { return this->_handle; }

			inline bool ShaderStage::isCompilationRequired() const { return this->_compilationRequired; }
		} // namespace shader
	} // namespace renderer
} // namespace ece
