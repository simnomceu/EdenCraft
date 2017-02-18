namespace ece
{
	inline RenderWindow::RenderWindow(const ece::WindowSetting & settings) : BaseWindow(settings), scene(nullptr) {}

	inline void RenderWindow::attachScene(const std::shared_ptr<Scene>& scene) { this->scene = scene; }
}