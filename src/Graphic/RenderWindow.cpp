#include "RenderWindow.hpp"

namespace ece
{
	void RenderWindow::onRefresh()
	{
		glViewport(0, 0, 800, 600);
		this->scene->render();
	}

	void RenderWindow::open(const ece::VideoMode & videoMode)
	{
		// TODO : fix that, the object cannot be added before the window is opened.
		BaseWindow::open(videoMode);

		this->scene->addObject("../resource/mesh/cube.obj");
		this->scene->init(); // TODO : crash !!!
	}
}