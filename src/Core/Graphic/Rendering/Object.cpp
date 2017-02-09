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
		glBufferData(GL_ARRAY_BUFFER, this->mesh.getNumberOfVertices() * 3 * sizeof(GLfloat), this->mesh.getVertices().data(), GL_STATIC_DRAW);
		glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, 0, 0);


		if (this->vbos[COLOR] == 0) {
			glGenBuffers(1, &this->vbos[0] + COLOR);
		}
		glBindBuffer(GL_ARRAY_BUFFER, this->vbos[COLOR]);
		glBufferData(GL_ARRAY_BUFFER, this->mesh.getNumberOfVertices() * 3 * sizeof(GLfloat), this->mesh.getColors().data(), GL_STATIC_DRAW);
		glVertexAttribPointer(COLOR, 3, GL_FLOAT, GL_FALSE, 0, 0);

		// ===== Clear Binding =====
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	Point3D Object::getCenter() const
	{
		// TODO call from mesh
		return Point3D();
	}

	void Object::render(const glm::mat4 view, const glm::mat4 projection)
	{
		glBindVertexArray(this->vao);
		this->program.setUniform("MVP", projection * view * this->model);
		program.use();
		glDrawArrays(this->modeRender, 0, (GLsizei)(this->mesh.getNumberOfVertices() * 3));
		glBindVertexArray(0);
	}
}