#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "Renderer.hpp"
#include "RenderQueue.hpp"
#include "Renderable\Renderable.hpp"

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

		virtual void render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects) override;

	private:
		std::unordered_map<RenderQueueKey, std::unique_ptr<RenderQueue>> queues;
	};
}

#endif // RENDERERGL_HPP