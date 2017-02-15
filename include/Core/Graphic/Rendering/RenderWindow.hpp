#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include <memory>

#include "Core\Window\Window\BaseWindow.hpp"
#include "Core\Graphic\Rendering\Scene.hpp"

namespace ece
{
	class RenderWindow : public BaseWindow
	{
	public:
		RenderWindow(const ece::WindowSetting & settings);

		virtual void onRefresh();

		void attachScene(const std::shared_ptr<Scene> & scene);

		virtual void open(const ece::VideoMode & videoMode);

	private:
		std::shared_ptr<Scene> scene;
	};
}

#endif // RENDERWINDOW_HPP