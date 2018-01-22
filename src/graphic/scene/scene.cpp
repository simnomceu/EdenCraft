#include "graphic/scene/scene.hpp"

#include "utility/mathematics/vector3u.hpp"
#include "graphic/model/object.hpp"

namespace ece
{
	Scene::Scene() : _camera(), _objects()
	{
		// TODO : change the resolution ratio to be adapted to window size
		this->_camera.moveTo(FloatVector3u{ 1.0f, 2.0f, 2.0f });
	}

	Object * Scene::addObject()
	{
		this->_objects.push_back(new Object());
		return static_cast<Object *>(this->_objects.back());
	}
}