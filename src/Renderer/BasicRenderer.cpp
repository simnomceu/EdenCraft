#include "BasicRenderer.hpp"

#include "Scene\Camera.hpp"
#include "Scene\Projection.hpp"
#include "Renderable\Renderable.hpp"

#include "OpenGL\OpenGL.hpp"

#include <iostream>

namespace ece
{
	void BasicRenderer::render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects)
	{
		for (auto & object : objects) {
			auto vertices = object->getVertices();
			auto uniforms = object->getUniforms();
			auto shaders = object->getShaderSources();

			auto vertex_shader = shaders[0]->getSource().data();
			auto fragment_shader = shaders[1]->getSource().data();

			
			// create the object here
			GLuint vbo = -1;
			GLuint vao = -1;

			// Set the mesh here

			// bind the uniforms here

			// load the shaders here
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, vertices->getPositions().size() * sizeof(GLfloat), &vertices->getPositions()[0], GL_STATIC_DRAW);

			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
			GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vert_shader, 1, &vertex_shader, NULL);
			glCompileShader(vert_shader);
			GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(frag_shader, 1, &fragment_shader, NULL);
			glCompileShader(frag_shader);
			GLuint shader_programme = glCreateProgram();
			glAttachShader(shader_programme, frag_shader);
			glAttachShader(shader_programme, vert_shader);
			glLinkProgram(shader_programme);

			glUseProgram(shader_programme);
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLES, 0, vertices->getPositions().size() / 3);
		}
	}
}