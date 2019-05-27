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
#include "gui/imgui/window_adapter.hpp"

#include "imgui.h"
#include "window/common.hpp"
#include "renderer/opengl.hpp"

namespace ece
{
	namespace gui
	{
		namespace imgui
		{
			WindowAdapter::WindowAdapter() noexcept: _window(), _mouseJustPressed({false, false, false, false, false})
			{
			}

			void WindowAdapter::init(std::shared_ptr<Window> window)
			{
				this->_window = window;

				ImGuiIO & io = ImGui::GetIO();
				io.BackendPlatformName = "imgui_impl_edencraft";
				io.ImeWindowHandle = this->getWindowHandle();

				io.KeyMap[ImGuiKey_A] = static_cast<int>(ece::Keyboard::Key::A);
				io.KeyMap[ImGuiKey_C] = static_cast<int>(ece::Keyboard::Key::C);
				io.KeyMap[ImGuiKey_V] = static_cast<int>(ece::Keyboard::Key::V);
				io.KeyMap[ImGuiKey_X] = static_cast<int>(ece::Keyboard::Key::X);
				io.KeyMap[ImGuiKey_Y] = static_cast<int>(ece::Keyboard::Key::Y);
				io.KeyMap[ImGuiKey_Z] = static_cast<int>(ece::Keyboard::Key::Z);
				io.KeyMap[ImGuiKey_Backspace] = static_cast<int>(ece::Keyboard::Key::BACKSPACE);
				io.KeyMap[ImGuiKey_Delete] = static_cast<int>(ece::Keyboard::Key::DEL);
				io.KeyMap[ImGuiKey_DownArrow] = static_cast<int>(ece::Keyboard::Key::DOWN);
				io.KeyMap[ImGuiKey_End] = static_cast<int>(ece::Keyboard::Key::END);
				io.KeyMap[ImGuiKey_Enter] = static_cast<int>(ece::Keyboard::Key::RETURN);
				io.KeyMap[ImGuiKey_Escape] = static_cast<int>(ece::Keyboard::Key::ESCAPE);
				io.KeyMap[ImGuiKey_Home] = static_cast<int>(ece::Keyboard::Key::HOME);
				io.KeyMap[ImGuiKey_Insert] = static_cast<int>(ece::Keyboard::Key::INS);
				io.KeyMap[ImGuiKey_LeftArrow] = static_cast<int>(ece::Keyboard::Key::LEFT);
				io.KeyMap[ImGuiKey_PageDown] = static_cast<int>(ece::Keyboard::Key::PAGE_DOWN);
				io.KeyMap[ImGuiKey_PageUp] = static_cast<int>(ece::Keyboard::Key::PAGE_UP);
				io.KeyMap[ImGuiKey_RightArrow] = static_cast<int>(ece::Keyboard::Key::RIGHT);
				io.KeyMap[ImGuiKey_Space] = static_cast<int>(ece::Keyboard::Key::SPACEBAR);
				io.KeyMap[ImGuiKey_Tab] = static_cast<int>(ece::Keyboard::Key::TAB);
				io.KeyMap[ImGuiKey_UpArrow] = static_cast<int>(ece::Keyboard::Key::UP);

				auto & eventHandler = this->_window->getEventHandler();
				eventHandler.onKeyPressed.connect([](const ece::InputEvent & event, [[maybe_unused]] ece::Window & /*window*/) {
					ImGuiIO & io = ImGui::GetIO();

					io.KeysDown[static_cast<int>(event.key)] = true;

					io.KeyCtrl = io.KeysDown[static_cast<int>(Keyboard::Key::CTRL)];
					io.KeyShift = io.KeysDown[static_cast<int>(Keyboard::Key::SHIFT)];
					io.KeyAlt = io.KeysDown[static_cast<int>(Keyboard::Key::ALTGR)];
					io.KeySuper = io.KeysDown[static_cast<int>(Keyboard::Key::LEFT_COMMAND)] || io.KeysDown[static_cast<int>(Keyboard::Key::RIGHT_COMMAND)];
				});
				eventHandler.onKeyReleased.connect([](const ece::InputEvent & event, [[maybe_unused]] ece::Window & /*window*/) {
					ImGuiIO & io = ImGui::GetIO();

					io.KeysDown[static_cast<int>(event.key)] = false;

					io.KeyCtrl = io.KeysDown[static_cast<int>(Keyboard::Key::CTRL)];
					io.KeyShift = io.KeysDown[static_cast<int>(Keyboard::Key::SHIFT)];
					io.KeyAlt = io.KeysDown[static_cast<int>(Keyboard::Key::ALTGR)];
					io.KeySuper = io.KeysDown[static_cast<int>(Keyboard::Key::LEFT_COMMAND)] || io.KeysDown[static_cast<int>(Keyboard::Key::RIGHT_COMMAND)];
				});
				eventHandler.onMouseButtonPressed.connect([this](const ece::InputEvent & event, [[maybe_unused]] ece::Window & /*window*/) {
					this->_mouseJustPressed[static_cast<int>(event.mouseButton)] = true;
				});
			}

			void WindowAdapter::newFrame()
			{
				auto size = this->_window->getSize();

				ImGuiIO & io = ImGui::GetIO();
				io.DisplaySize = ImVec2(static_cast<float>(size[0]), static_cast<float>(size[1]));
				io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
				io.DeltaTime = 1.0f / 60.0f;

				auto i = 0;
				for (i = 0; i < IM_ARRAYSIZE(io.MouseDown); ++i) {
					io.MouseDown[i] = this->_mouseJustPressed[i] || ece::Mouse::isKeyPressed(static_cast<Mouse::Button>(i));
					this->_mouseJustPressed[i] = false;
				}

				auto mousePos = ece::Mouse::getPosition();
				io.MousePos = ImVec2(static_cast<float>(mousePos[0]), static_cast<float>(mousePos[1]));
			}

			void WindowAdapter::shutdown()
			{
			}

			void WindowAdapter::render()
			{
				auto size = this->_window->getSize();
				glViewport(0, 0, size[0], size[1]);
			}
		} // namespace imgui
	} // namespace gui
} // namespace ece
