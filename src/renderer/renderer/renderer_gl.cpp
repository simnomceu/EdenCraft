#include "renderer_gl.hpp"

//#include "scene/camera.hpp"
//#include "scene/projection.hpp"
#include "opengl/open_gl_util.hpp"

#include <utility>

namespace ece
{
	void RendererGL::addRenderQueue(const RenderQueueKey & key)
	{
		// NOTE: not final version. Required to implement an inheritance of RenderQueues.
		this->queues.insert(std::make_pair(key, nullptr));
		this->queues[key] = std::make_unique<RenderQueue>();
	}

	/*void RendererGL::render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects)
	{
		auto VP = projection.getProjection() * cam.getCamera();

		for (auto object : objects) {
			// NOTE: not final version. Required to implement a switch to dispense the right queue to render the object.
			this->queues.begin()->second->render(VP, *object);
		}
	}*/
}