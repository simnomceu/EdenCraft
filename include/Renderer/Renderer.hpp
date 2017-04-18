#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "RenderQueue.hpp"
#include "Renderable.hpp"

namespace ece
{
	class Camera;
	class Projection;

	using RenderQueueKey = std::string;

	class Renderer
	{
	public:
		Renderer() = default;
		Renderer(const Renderer & copy) = default;
		Renderer(Renderer && move) = default;

		~Renderer() = default;
		
		Renderer & operator=(const Renderer & copy) = default;
		Renderer & operator=(Renderer && move) = default;

		void addRenderQueue(const RenderQueueKey & key);

		void render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects);

	private:
		std::unordered_map<RenderQueueKey, std::unique_ptr<RenderQueue>> queues;
	};
}

#endif // RENDERER_HPP