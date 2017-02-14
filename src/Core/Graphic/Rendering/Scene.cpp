#include "Core\Graphic\Rendering\Scene.hpp"

#include "glm\gtc\matrix_transform.hpp"
#include "Core\Util\File\ParserOBJ.hpp"
#include "Core\Util\LogService.hpp"

namespace ece
{
	Scene::Scene(): cam(), objects(), projection(1.0f)
	{
		// TODO : cange the resolution ratio to be adapted to window size
		this->projection = glm::perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);
		this->cam.moveTo(Point3D(1.0f, 2.0f, 1.0f));
	}

	void Scene::render()
	{
		auto view = this->cam.getCamera();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
			it->render(view, this->projection);
		}
	}

	void Scene::addObject(const std::string pathname)
	{
		ParserOBJ parser;

		try {
			parser.open(pathname);

			Mesh mesh(GL_TRIANGLES);
			mesh.addVertices(parser.getVertices(), parser.getFaces());
			mesh.addColors(parser.getTextures());

			this->objects.push_back(Object(mesh));
			this->objects.front().prepare();
		}
		catch (std::exception & e) {
			LogServiceLocator::getService().logError("Error while loading object " + pathname + ": " + std::string(e.what()));
		}
	}
}