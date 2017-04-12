#include "Scene\Scene.hpp"

#include "Util\Type.hpp"
#include "Model\Object.hpp"
#include "Renderer\Renderable.hpp"

namespace ece
{
	Scene::Scene() : camera(), projection(), objects()
	{
		// TODO : change the resolution ratio to be adapted to window size
		this->projection.setProjection(20.0f, RATIO_4_3, 0.3f, 30.0f);
		this->camera.moveTo(GL::Point3D(1.0f, 2.0f, 2.0f));
	}

	Object & Scene::addObject()
	{
		auto object = new Object();
		this->objects.push_back(object);
		return *object;
	}
}