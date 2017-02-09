#include "Core\Graphic\Rendering\RenderWindow.hpp"

namespace ece
{
	RenderWindow::RenderWindow(const ece::WindowSetting & settings): BaseWindow(settings), scene(nullptr)
	{
	}

	void RenderWindow::onRefresh()
	{
	}

	void RenderWindow::attachScene(const std::shared_ptr<Scene>& scene)
	{
		this->scene = scene;
	}
}