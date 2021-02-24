/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.    ooooo     ooo ooooo
															 d8P'  `Y8b   `888'     `8' `888'
															888            888       8   888
															888            888       8   888
															888     ooooo  888       8   888
															`88.    .88'   `88.    .8'   888
															 `Y8bood8P'      `YbodP'    o888o


				This file is part of EdenCraft Engine - GUI module.
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

#include "gui/pch.hpp"
#include "gui/imgui/font.hpp"
#include "imgui.h"

namespace ece
{
	namespace gui
	{
		namespace imgui
		{
			void Font::load()
			{
				int currentTexture = OpenGL::getInteger(ece::Parameter::TEXTURE_BINDING_2D)[0];

				// Build texture atlas
				ImGuiIO& io = ImGui::GetIO();
				int width = 0, height = 0;
				unsigned char* pixels;
				auto fontImage = ece::makeResource<ece::Image<ece::RGBA32>>("ImGuiFontImage");
				auto imagePtr = reinterpret_cast<unsigned char *>(fontImage->data());
				io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height); // Load as RGBA 32-bits (75% of the memory is wasted, but default font is so small) because it is more likely to be compatible with user's existing shaders. If your ImTextureId represent a higher-level concept than just a GL texture id, consider calling GetTexDataAsAlpha8() instead to save on GPU memory.
				fontImage->resize(width, height);
				imagePtr = pixels;

				this->_fontTexture = ece::makeResource<ece::Texture>("ImGuiFont");
				this->_fontTexture->setParameter<int>(ece::TextureParameter::TEXTURE_MIN_FILTER, GL_LINEAR);
				this->_fontTexture->setParameter<int>(ece::TextureParameter::TEXTURE_MAG_FILTER, GL_LINEAR);
				this->_fontTexture->loadFromImage(ece::TextureTypeTarget::TEXTURE_2D, fontImage);
#ifdef GL_UNPACK_ROW_LENGTH
				OpenGL::pixelStore(PixelParameter::UNPACK_ROW_LENGTH, 0);
#endif

				// Store our identifier
				io.Fonts->TexID = reinterpret_cast<ImTextureID>((unsigned long long)this->_fontTexture->getHandle());

				OpenGL::bindTexture(ece::TextureTarget::TEXTURE_2D, currentTexture);
			}

			void Font::terminate()
			{
				if (this->_fontTexture) {
					this->_fontTexture->terminate();

					ImGuiIO& io = ImGui::GetIO();
					io.Fonts->TexID = 0;
				}
			}
		} // namespace imgui
	} // namespace gui
} // namespace ece