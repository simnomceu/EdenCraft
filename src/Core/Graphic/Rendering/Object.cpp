#include "Core\Graphic\Rendering\Object.hpp"

namespace ece
{
	Object::Object(const Mesh & mesh, const ProgramGLSL program): mesh(mesh), program(program), texture(), transformations()
	{
	}

	void Object::prepare()
	{
		// ===== VAO =====
		if (this->vao == 0) {
			glGenVertexArrays(1, &this->vao);
			glBindVertexArray(this->vao);
			glEnableVertexAttribArray(POSITION);
		}
		else {
			glBindVertexArray(this->vao);
		}

		// ===== VBOs =====
		if (this->vbos[POSITION] == 0) {
			glGenBuffers(1, &this->vbos[0] + POSITION);
		}
		glBindBuffer(GL_ARRAY_BUFFER, this->vbos[POSITION]);
		glBufferData(GL_ARRAY_BUFFER, this->mesh.getNumberOfVertices() * 3 * sizeof(GLfloat), this->mesh.getVertices().data(), GL_STATIC_DRAW);
		glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, 0, 0);

		// ===== Clear Binding =====
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}