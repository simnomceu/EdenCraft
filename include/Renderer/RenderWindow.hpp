#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include "Window\BaseWindow.hpp"
#include "Renderer.hpp"
#include "Scene\Scene.hpp"

namespace ece
{
	class RenderWindow: public BaseWindow
	{
	public:
		RenderWindow() = default;
		RenderWindow(const ece::WindowSetting & settings);
		RenderWindow(const RenderWindow & copy) = default;
		RenderWindow(RenderWindow && move) = default;

		~RenderWindow() = default;

		RenderWindow & operator=(const RenderWindow & copy) = default;
		RenderWindow & operator=(RenderWindow && move) = default;

		virtual void onRefresh() override;
		virtual void open(const ece::VideoMode & videoMode) override;

	private:
		Renderer renderer;
		Scene scene;
	};
}

#endif // RENDERWINDOW_HPP