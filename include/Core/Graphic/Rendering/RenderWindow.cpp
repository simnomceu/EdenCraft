#include "RenderWindow.hpp"

ece::RenderWindow::RenderWindow(const ece::WindowSetting & settings): BaseWindow(settings), scene()
{
}

void ece::RenderWindow::onRefresh()
{
}

void ece::RenderWindow::attachScene(const std::shared_ptr<Scene>& scene)
{
	this->scene = scene;
}
