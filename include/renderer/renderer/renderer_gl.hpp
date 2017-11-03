#ifndef RENDERER_GL_HPP
#define RENDERER_GL_HPP

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "renderer/renderer/renderer.hpp"
#include "renderer/renderer/render_queue.hpp"
//#include "renderable/renderable.hpp"

namespace ece
{

	using RenderQueueKey = std::string;

	class RendererGL: public Renderer
	{
	public:
		RendererGL() = default;
		RendererGL(const RendererGL & copy) = default;
		RendererGL(RendererGL && move) = default;

		~RendererGL() = default;
		
		RendererGL & operator=(const RendererGL & copy) = default;
		RendererGL & operator=(RendererGL && move) = default;

		void addRenderQueue(const RenderQueueKey & key);

//		virtual void render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects) override;

	private:
		std::unordered_map<RenderQueueKey, std::unique_ptr<RenderQueue>> queues;
	};
}

#endif // RENDERER_GL_HPP