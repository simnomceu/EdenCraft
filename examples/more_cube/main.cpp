#include "core/application/application.hpp"

#include "renderer/common_renderer/render_window.hpp"
#include "utility/file/file.hpp"
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

	ece::File file;
	std::string fsSource, vsSource;

	try {
		file.open("../examples/more_cube/shader.frag");
		fsSource = file.parseToString();

		file.open("../examples/more_cube/shader.vert");
		vsSource = file.parseToString();
	}
	catch (ece::FileException & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}
		
	GLfloat points[] = { 0.0f, 0.5f, 0.0f, 
						 0.5f, -0.5f, 0.0f, 
						-0.5f, -0.5f, 0.0f };

	GLfloat colours[] = { 1.0f, 0.0f, 0.0f, 
						  0.0f, 1.0f, 0.0f, 
						  0.0f, 0.0f, 1.0f };

	GLuint points_vbo;
	glGenBuffers(1, &points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points, GL_STATIC_DRAW);
	GLuint colours_vbo;
	glGenBuffers(1, &colours_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), colours, GL_STATIC_DRAW);
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	const GLchar *p = (const GLchar *)vsSource.data();
	glShaderSource(vs, 1, &p, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	p = (const GLchar *)fsSource.data();
	glShaderSource(fs, 1, &p, NULL);
	glCompileShader(fs);
	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	ece::InputEvent event;
	while (1) {
		window.clear();
		glUseProgram(shader_programme);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		while (window.pollEvent(event)) {
		}
		window.display();
	}

	return 0;
}