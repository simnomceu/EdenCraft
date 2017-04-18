#include "Scene\Scene.hpp"

#include "Type.hpp"
#include "Model\Object.hpp"
//#include "Renderable.hpp"

namespace ece
{
	Scene::Scene() : camera(), projection(), objects()
	{
		// TODO : change the resolution ratio to be adapted to window size
		this->projection.setProjection(20.0f, RATIO_4_3, 0.3f, 30.0f);
		this->camera.moveTo(FloatVertex3D(1.0f, 2.0f, 2.0f));
	}

	Object & Scene::addObject()
	{
		this->objects.push_back(Object());
		return this->objects.back();
	}
}