#include "Renderer\Renderer.hpp"

#include "Scene\Camera.hpp"
#include "Scene\Projection.hpp"
#include "Util\OpenGL\OpenGL.hpp"

#include <utility>

namespace ece
{
	void Renderer::addRenderQueue(const RenderQueueKey & key)
	{
		// NOTE: not final version. Required to implement an inheritance of RenderQueues.
		this->queues.insert(std::make_pair(key, nullptr));
		this->queues[key] = std::make_unique<RenderQueue>();
	}

	void Renderer::render(const Camera & cam, const Projection & projection, std::vector<Renderable &> & objects)
	{
		auto VP = projection.getProjection() * cam.getCamera();

		for (auto object : objects) {
			// NOTE: not final version. Required to implement a switch to dispense the right queue to render the object.
			this->queues.begin()->second->render(VP, object);
		}
	}
}