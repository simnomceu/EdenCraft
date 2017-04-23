#include "Scene\Scene.hpp"

#include "Mathematics\Vertex3D.hpp"
#include "Model\Object.hpp"

namespace ece
{
	Scene::Scene() : camera(), objects()
	{
		// TODO : change the resolution ratio to be adapted to window size
		this->camera.moveTo(FloatVertex3D(1.0f, 2.0f, 2.0f));
	}

	Object * Scene::addObject()
	{
		this->objects.push_back(new Object());
		return static_cast<Object *>(this->objects.back());
	}
}