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

#ifndef IMGUI_COMPONENT
#define IMGUI_COMPONENT

#include "gui/pch.hpp"
#include "gui/config.hpp"
#include "core/ecs.hpp"
#include "gui/imgui/adapter.hpp"

namespace ece
{
	namespace gui
	{
		namespace imgui
		{
			class ECE_GUI_API ImguiComponent : public Component<ImguiComponent>
			{
			public:
				using Factory = std::function<void()>;

				inline ImguiComponent(Factory fact) noexcept;
				ImguiComponent(const ImguiComponent& copy) noexcept = default;
				ImguiComponent(ImguiComponent&& copy) noexcept = default;

				~ImguiComponent() noexcept = default;

				ImguiComponent& operator=(const ImguiComponent& copy) noexcept = default;
				ImguiComponent& operator=(ImguiComponent&& copy) noexcept = default;

				inline void draw();

			private:
				Factory _factory;
			};
		} // namespace imgui
	} // namespace gui
} // namespace ece

#include "gui/imgui/imgui_component.inl"

#endif // IMGUI_COMPONENT