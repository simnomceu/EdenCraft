#include "Core\Graphic\Rendering\RenderWindow.hpp"

#include <iostream>

namespace ece
{
	RenderWindow::RenderWindow(const ece::WindowSetting & settings): BaseWindow(settings), scene(nullptr)
	{
	}

	void RenderWindow::onRefresh()
	{
		glViewport(0, 0, 800, 600);
		this->scene->render();
	}

	void RenderWindow::attachScene(const std::shared_ptr<Scene>& scene)
	{
		this->scene = scene;
	}

	void RenderWindow::open(const ece::VideoMode & videoMode)
	{
		// TODO : fix that, the object cannot be added before the window is opened.
		BaseWindow::open(videoMode);

		this->scene->addObject("../resource/mesh/cube.obj");
	}
}