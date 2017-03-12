#include "Rendering\Object.hpp"

#include <iostream>

#include "Rendering\RenderingService.hpp"
#include "GL\glew.h"

namespace ece
{
	Object::Object(const Mesh & mesh): mesh(mesh), program(nullptr), texture(), transformations(), vao(0), vbos(3, 0), model(1.0f)
	{
		program = RenderingServiceLocator::getService().createProgram();

		Shader* frag = RenderingServiceLocator::getService().createShader(FRAGMENT_SHADER);
		frag->loadFromFile("../resource/shader/basic.frag");
		this->program->attachShader(*frag);
		delete frag;

		Shader* vert = RenderingServiceLocator::getService().createShader(VERTEX_SHADER);
		frag->loadFromFile("../resource/shader/basic.vert");
		this->program->attachShader(*vert);
		delete vert;
	}

	void Object::prepare()
	{
		// ===== VAO =====
		if (this->vao == 0) {
			glGenVertexArrays(1, &this->vao);
			glBindVertexArray(this->vao);
			glEnableVertexAttribArray(POSITION);
			glEnableVertexAttribArray(COLOR);
		}
		else {
			glBindVertexArray(this->vao);
		}

		// ===== VBOs =====
		if (this->vbos[POSITION] == 0) {
			glGenBuffers(1, &this->vbos[0] + POSITION);
		}
		glBindBuffer(GL_ARRAY_BUFFER, this->vbos[POSITION]);
		glBufferData(GL_ARRAY_BUFFER, this->mesh.size() * 3 * sizeof(GLfloat), this->mesh.getVertices().data(), GL_STATIC_DRAW);
		glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, 0, 0);

		/*if (this->vbos[INDEX] == 0) {
			glGenBuffers(1, &this->vbos[0] + INDEX);
		}
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->vbos[INDEX]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->mesh.size() * sizeof(GLint), this->mesh.getVerticesIndex().data(), GL_STATIC_DRAW);*/

		if (this->vbos[COLOR] == 0) {
			glGenBuffers(1, &this->vbos[0] + COLOR);
		}
		glBindBuffer(GL_ARRAY_BUFFER, this->vbos[COLOR]);
		glBufferData(GL_ARRAY_BUFFER, this->mesh.size() * 3 * sizeof(GLfloat), this->mesh.getColors().data(), GL_STATIC_DRAW);
		glVertexAttribPointer(COLOR, 3, GL_FLOAT, GL_FALSE, 0, 0);

		// ===== Clear Binding =====
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		this->program->link();
	}

	Point3D Object::getCenter() const
	{
		// TODO call from mesh
		return Point3D();
	}

	void Object::render(const glm::mat4 & view, const glm::mat4 & projection)
	{
		glBindVertexArray(this->vao);
		this->program->bindInfo(projection * view * this->model, "MVP");
		this->program->use();
		glBindBuffer(GL_ARRAY_BUFFER, POSITION);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, INDEX);
		//glDrawElements(this->mesh.getModeRender(), this->mesh.size(), GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
