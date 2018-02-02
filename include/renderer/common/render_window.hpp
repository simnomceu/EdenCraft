#ifndef RENDER_WINDOW_HPP
#define RENDER_WINDOW_HPP

#include <vector>
#include <memory>

#include "window/common/window.hpp"
#include "renderer/common/renderer.hpp"
#include "renderer/opengl/base_context_opengl.hpp"

namespace ece
{
	class RenderWindow: public Window
	{
	public:
		RenderWindow();
		RenderWindow(const RenderWindow & copy) = default;
		RenderWindow(RenderWindow && move) = default;

		~RenderWindow();

		RenderWindow & operator=(const RenderWindow & copy) = default;
		RenderWindow & operator=(RenderWindow && move) = default;

		inline void setContextMinimumVersion(const Version<2> & minVersion);
		inline void setContextMaximumVersion(const Version<2> & maxVersion);

		void open();
		void clear();
		void display();

		void enableMSAA(const unsigned short int samples);

		virtual void updateVideoMode() override;

	private:
		std::vector<std::shared_ptr<Renderer>> _renderers;
		std::shared_ptr<BaseContextOpenGL> _context;
	};
}

#include "renderer/common/render_window.inl"

#endif // RENDER_WINDOW_HPP
