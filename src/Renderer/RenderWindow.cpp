#include "Renderer\RenderWindow.hpp"

#include "Model\ShaderEffect.hpp"
#include "Renderer\Shader.hpp"
#include "Model\Mesh.hpp"
#include "Model\Object.hpp"

#include <memory>

namespace ece
{
	RenderWindow::RenderWindow(const ece::WindowSetting & settings): BaseWindow(settings), renderer(), scene()
	{
		auto mesh = std::make_shared<Mesh>();
		mesh->loadFromFile("../resource/shader/cube.dat");

		auto shaderEffect = std::make_shared<ShaderEffect>();
		auto vertexShader = shaderEffect->addShader();

		//auto & object = this->scene.addObject();
		//object.setMesh(mesh);
		//object.setShaderEffect(shaderEffect);
	}

	void RenderWindow::onRefresh()
	{
		glViewport(0, 0, 800, 600); // TODO: why ?
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		this->renderer.render(this->scene.getCamera(), this->scene.getProjection(), this->scene.getObjects());
	}

	void RenderWindow::open(const ece::VideoMode & videoMode)
	{
		// TODO : fix that, the object cannot be added before the window is opened.
		BaseWindow::open(videoMode);

		this->renderer.addRenderQueue("Classic");
	}
}