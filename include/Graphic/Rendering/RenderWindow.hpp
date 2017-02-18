#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include <memory>

#include "Window\BaseWindow.hpp"
#include "Rendering\Scene.hpp"

namespace ece
{
	class RenderWindow : public BaseWindow
	{
	public:
		inline RenderWindow(const ece::WindowSetting & settings);

		virtual void onRefresh() override;

		inline void attachScene(const std::shared_ptr<Scene> & scene);

		virtual void open(const ece::VideoMode & videoMode) override;

	private:
		std::shared_ptr<Scene> scene;
	};
}

#include "Rendering\RenderWindow.inl"

#endif // RENDERWINDOW_HPP