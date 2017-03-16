#include "Renderer\RenderQueue.hpp"

namespace ece
{
	void RenderQueue::render(const Matrix4x4 & VP, Renderable & object)
	{
		// TODO: add tag to remember the last object displayed
		auto locations = object.getLocations();
		int index = 0;
		for (auto location : locations) {
			this->program.bindLocation(index, location);
			++index;
		}

		auto shaders = object.getShaders();
		for (auto shader : shaders) {
			this->program.apply(shader);
		}
		this->program.link();

		this->program.bindInfo(VP * object.getModel(), "MVP");
		this->program.use();
		object.draw();
	}
}