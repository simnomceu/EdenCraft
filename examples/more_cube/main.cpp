#include "core/application/application.hpp"

#include "renderer/common/render_window.hpp"
#include "renderer/common/program.hpp"
#include "utility/log/service_logger.hpp"

#include <iostream>

int main()
{
	ece::Application app;

	ece::RenderWindow window;

	ece::WindowSetting settings;
	settings.position = ece::IntVertex2u(200, 200);
	settings.title = "WFL window testing";
		
	window.open();
	window.getVideoMode().setSamples(0);
	window.updateVideoMode();
	window.setSettings(settings);

	ece::Shader fsSource, vsSource;
	fsSource.loadFromFile(ece::ECE_FRAGMENT_SHADER, "../examples/more_cube/shader.frag");
	vsSource.loadFromFile(ece::ECE_VERTEX_SHADER, "../examples/more_cube/shader.vert");
		
	std::array<float, 9> points{ 0.0f, 0.5f, 0.0f,
							  0.5f, -0.5f, 0.0f,
							  -0.5f, -0.5f, 0.0f };
	
	std::array<float, 9> colours{ 1.0f, 0.0f, 0.0f,
							   0.0f, 1.0f, 0.0f,
							   0.0f, 0.0f, 1.0f };

	try {
		GLuint points_vbo;
		glGenBuffers(1, &points_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
		glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points.data(), GL_STATIC_DRAW);
		GLuint colours_vbo;
		glGenBuffers(1, &colours_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
		glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), colours.data(), GL_STATIC_DRAW);
		GLuint vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		
		ece::Program program;
		program.addShader(fsSource);
		program.addShader(vsSource);
		program.link();

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CW);

		ece::InputEvent event;
		while (1) {
			window.clear();
			program.use();
			glBindVertexArray(vao);
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