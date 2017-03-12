#include "Rendering\Scene.hpp"

#include "glm\gtc\matrix_transform.hpp"
//#include "Util\File\ParserOBJ.hpp"
#include "Util\Log\ServiceLogger.hpp"
//#include "Rendering\RenderingService.hpp"
//#include "Rendering\Program.hpp"

#include <iostream>

namespace ece
{
	Scene::Scene(): cam(), objects(1), projection(1.0f), program()
	{
		// TODO : cange the resolution ratio to be adapted to window size
		this->projection = glm::perspective(20.0f, 800.0f/600.0f, 0.3f, 30.0f);
		this->cam.moveTo(Point3D(1.0f, 2.0f, 2.0f));
	}

	void Scene::init()
	{
		auto mesh = std::make_shared<Mesh>();
		mesh->loadFromFile("../resource/shader/cube.dat");

		this->objects[0] = std::shared_ptr<Object>(new Object());
		this->objects[0]->addMesh(mesh);

		/*this->program = std::shared_ptr<Program>(RenderingServiceLocator::getService().createProgram());

		auto fragment = RenderingServiceLocator::getService().createShader(Shader::FRAGMENT_SHADER);
		fragment->loadFromFile("../resource/shader/basic.frag");
		this->program->attachShader(*fragment);

		auto vertex = RenderingServiceLocator::getService().createShader(Shader::VERTEX_SHADER);
		vertex->loadFromFile("../resource/shader/basic.vert");
		this->program->attachShader(*vertex);*/

		this->program.init();
		this->program.loadShaderFromFile(FRAGMENT_SHADER, "../resource/shader/basic.frag");
		this->program.loadShaderFromFile(VERTEX_SHADER, "../resource/shader/basic.vert");
		this->program.link();

		for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
			(*it)->prepare();
		}

		this->program.displayActiveUniforms();
		this->program.displayActiveAttribs();

		//this->cam.lookAt(*this->objects[0]);
		this->cam.lookAt(this->objects[0]->getRelativeCenter());
	}

	void Scene::render()
	{
		//auto view = this->cam.getView();
		
		auto view = this->cam.getCamera();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
			//it->render(view, this->projection);
			(*it)->render(this->program, view, this->projection);
		}
	}

	void Scene::addObject(const std::string pathname)
	{
		//ParserOBJ parser;

		/*try {
			parser.open(pathname);

			Mesh mesh(GL_TRIANGLES);
			mesh.addVertices(parser.getVertices(), parser.getFaces());
			mesh.addColors(parser.getTextures());

			this->objects.push_back(Object(mesh));
			this->objects.front().prepare();
		}
		catch (std::exception & e) {
			ServiceLoggerLocator::getService().logError("Error while loading object " + pathname + ": " + std::string(e.what()));
		}*/
	}
}