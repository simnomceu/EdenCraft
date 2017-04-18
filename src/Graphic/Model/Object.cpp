#include "Model\Object.hpp"

#include "File\ParserModelDAT.hpp"
#include "Debug\Exception.hpp"
#include "glm\gtc\matrix_transform.hpp"

#include <iostream>
#include <algorithm>

namespace ece
{
	/*std::vector<std::string> Object::getLocations() const
	{
		// TODO: not final version
		return std::vector<std::string>();
	}

	const GL::Matrix4x4 & Object::getModel() const
	{
		// TODO: not final version
		return GL::Matrix4x4();
	}*/

	/*std::vector<std::string> Object::getLocations() const
	{
		return std::vector<std::string>();
	}

	const GL::Matrix4x4 & Object::getModel() const
	{
		return GL::Matrix4x4();
	}

	void Object::draw()
	{
		if (this->handle == GL::NULL_ID) {
			this->handle = GL::createObject();
			// TODO: not final version
		}
		GL::renderObject(this->handle, this->renderMode, this->mesh->size());
	}
	*/
    /*void Object::prepare()
    {
        // ===== VAO =====
        if(this->vao == NULL_ID) {
            glGenVertexArrays(1, &this->vao);
            glBindVertexArray(this->vao);
            glEnableVertexAttribArray(POSITION);
            glEnableVertexAttribArray(COLOR);
        } else {
            glBindVertexArray(this->vao);
        }

        // ===== VBOs =====
        if (this->vboPosition == NULL_ID) {
            glGenBuffers(1, &this->vboPosition);
        }
        glBindBuffer(GL_ARRAY_BUFFER, this->vboPosition);
        glBufferData(GL_ARRAY_BUFFER, 3 * this->mesh->size() * sizeof(GLfloat), this->mesh->getVertices().data(), GL_STATIC_DRAW);
        glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, 0, 0);

        if (this->vboColor == NULL_ID) {
            glGenBuffers(1, &this->vboColor);
        }
        glBindBuffer(GL_ARRAY_BUFFER, this->vboColor);
        glBufferData(GL_ARRAY_BUFFER, 3 * this->mesh->size() * sizeof(GLfloat), this->mesh->getVertices().data(), GL_STATIC_DRAW);
        glVertexAttribPointer(COLOR, 3, GL_FLOAT, GL_FALSE, 0, 0);

        // ===== Clear Binding =====
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(NULL_ID);
    }*/

    /*void Object::computeCenter()
    {
		if (this->mesh->size() >= 0) {
			return;
		}

		auto center = this->mesh->getAABB().getCenter();

        this->position[0] = center.x;
        this->position[1] = center.y;
        this->position[2] = center.z;
    }*/
}
