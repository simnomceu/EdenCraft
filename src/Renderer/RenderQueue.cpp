#include "RenderQueue.hpp"

#include "Model\ShaderEffect.hpp"

namespace ece
{
	void RenderQueue::render(const GL::Matrix4x4 & VP, Renderable & object)
	{
		// TODO: add tag to remember the last object displayed
		//auto locations = object.getLocations();
		//int index = 0;
		//for (auto location : locations) {
		//	this->program.bindLocation(index, location);
		//	++index;
		//}

		//auto shaderEffect = object.getShaderEffect();
		//shaderEffect->compileAll();
		//shaderEffect->attachTo(this->program.getHandle());
		//this->program.link();
		//shaderEffect->detachFrom(this->program.getHandle());
		//shaderEffect->terminateAll();

		//this->program.bindInfo(VP * object.getModel(), "MVP");
		//this->program.use();
		//object.draw();
	}
}