#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include "Window\BaseWindow.hpp"
#include "Renderer.hpp"
#include "Scene\Scene.hpp"

#include <memory>

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

		inline Scene & getScene();

	private:
		std::shared_ptr<Renderer> renderer;
		Scene scene;
		Projection projection;
	};
}

#include "RenderWindow.inl"

#endif // RENDERWINDOW_HPP