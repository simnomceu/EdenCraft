#ifndef RENDER_WINDOW_OLD_HPP
#define RENDER_WINDOW_OLD_HPP

#include "window/window/base_window.hpp"
#include "renderer/renderer/renderer.hpp"
//#include "scene/scene.hpp"

#include <memory>

namespace ece
{
	class RenderWindowOld: public BaseWindow
	{
	public:
		RenderWindowOld() = default;
		RenderWindowOld(const ece::WindowSetting & settings);
		RenderWindowOld(const RenderWindowOld & copy) = default;
		RenderWindowOld(RenderWindowOld && move) = default;

		~RenderWindowOld() = default;

		RenderWindowOld & operator=(const RenderWindowOld & copy) = default;
		RenderWindowOld & operator=(RenderWindowOld && move) = default;

		virtual void onRefresh() override;
		virtual void open(const ece::VideoMode & videoMode) override;

//		inline Scene & getScene();

	private:
		std::shared_ptr<Renderer> renderer;
//		Scene scene;
//		Projection projection;
	};
}

#include "render_window_old.inl"

#endif // RENDER_WINDOW_OLD_HPP