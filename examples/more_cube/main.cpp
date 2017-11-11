#include "core/application/application.hpp"

#include "renderer/common/render_window.hpp"
#include "renderer/common/program.hpp"
#include "utility/log/service_logger.hpp"
#include "renderer/opengl/vao.hpp"

#include <iostream>

int main()
{
	try {
		ece::Application app;

		ece::RenderWindow window;

		ece::WindowSetting settings;
		settings.position = ece::IntVertex2u(200, 200);
		settings.title = "WFL window testing";

		window.open();
		window.getVideoMode().setSamples(0);
		window.updateVideoMode();
		window.setSettings(settings);


		const std::vector<float> points{ 0.0f, 0.5f, 0.0f,
									0.5f, -0.5f, 0.0f,
									-0.5f, -0.5f, 0.0f };

		const std::vector<float> colours{ 1.0f, 0.0f, 0.0f,
									0.0f, 1.0f, 0.0f,
									0.0f, 0.0f, 1.0f };

		ece::VAO vao;
		vao.addAttribute(0, 3, false, 0, ece::ARRAY_BUFFER, points, ece::STATIC_DRAW);
		vao.addAttribute(1, 3, false, 0, ece::ARRAY_BUFFER, colours, ece::STATIC_DRAW);

		ece::Shader fsSource, vsSource;
		fsSource.loadFromFile(ece::FRAGMENT_SHADER, "../examples/more_cube/shader.frag");
		vsSource.loadFromFile(ece::VERTEX_SHADER, "../examples/more_cube/shader.vert");
		ece::Program program;
		program.addShader(fsSource);
		program.addShader(vsSource);
		program.link();
		program.use();

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CW);

		ece::InputEvent event;
		while (1) {
			window.clear();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			while (window.pollEvent(event)) {
			}
			window.display();
		}
	}
	catch (std::runtime_error & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}

	return 0;
}