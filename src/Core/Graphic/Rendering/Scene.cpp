#include "Core\Graphic\Rendering\Scene.hpp"

#include "glm\gtc\matrix_transform.hpp"

namespace ece
{
	Scene::Scene(): cam(), objects(), projection(1.0f)
	{
		this->projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 100.0f);
	}

	void Scene::render()
	{
		auto view = this->cam.getCamera();

		for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
			it->render(view, this->projection);
		}
	}
}