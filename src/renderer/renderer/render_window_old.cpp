#include "render_window_old.hpp"

//#include "model/shader_effect.hpp"
//#include "model/shader.hpp"
//#include "model/mesh.hpp"
//#include "model/object.hpp"
#include "basic_renderer.hpp"

#include <memory>

namespace ece
{
	RenderWindowOld::RenderWindowOld(const ece::WindowSetting & settings): BaseWindow(settings), renderer(new BasicRenderer())/*, scene(), projection()*/
	{
//		auto mesh = std::make_shared<Mesh>();
//		mesh->loadFromFile("../resource/shader/cube.dat");

//		auto shaderEffect = std::make_shared<ShaderEffect>();
//		auto vertexShader = shaderEffect->addShader();

		//auto & object = this->scene.addObject();
		//object.setMesh(mesh);
		//object.setShaderEffect(shaderEffect);
	}

	void RenderWindowOld::onRefresh()
	{
		/*glViewport(0, 0, 800, 600); // TODO: why ?
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		this->renderer->render(this->scene.getCamera(), this->projection, this->scene.getObjects());*/
	}

	void RenderWindowOld::open(const ece::VideoMode & videoMode)
	{
		// TODO : fix that, the object cannot be added before the window is opened.
		BaseWindow::open(videoMode);

	//	std::static_pointer_cast<RendererGL>(this->renderer)->addRenderQueue("Classic");
	}
}