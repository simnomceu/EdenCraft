#include "Model\Object.hpp"

#include "Util\File\ParserModelDAT.hpp"
#include "Util\Debug\FileException.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "OldRotation.hpp"

#include <iostream>
#include <algorithm>

namespace ece
{
/*	void Object::setMesh(const std::shared_ptr<Mesh> & mesh)
	{
		auto lastPtr = this->mesh;
		this->mesh = mesh;
		lastPtr.reset();
		this->computeCenter();
	}*/

	void Object::setSkeleton(const std::shared_ptr<Mesh> & mesh)
	{
		auto lastPtr = this->mesh;
		this->mesh = mesh;
		lastPtr.reset();
		//		this->computeCenter();
	}

	/*void Object::loadMeshFromFile(const std::string & filename)
	{
		this->mesh = std::make_unique<Mesh>();
		bool loaded = this->mesh->loadFromFile(filename);
		if (loaded) {
			this->computeCenter();
		}
	}*/

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

    /*void Object::render(Program & program, const glm::mat4 & view, const glm::mat4 & projection)
	//void OldObject3D::render(Program & program, const glm::mat4 & view, const glm::mat4 & projection)
    {
		program.bindInfo(projection * view * this->model, "MVP");
		program.use();
        glBindVertexArray(this->vao);
        glDrawArrays(this->modeRender, 0, (GLsizei)this->mesh->size()*3);
        glBindVertexArray(NULL_ID);
    }*/

    /*void Object::rotate(const float degree, const glm::vec3 & normal, const bool animated)
    {
        this->animation.add(std::make_shared<OldRotation>(degree, normal, animated));
    }

    void Object::rotate(const float degree, const glm::vec3 & normal, const Point3D & center, const bool animated)
    {
        this->animation.add(std::make_shared<OldRotation>(degree, normal, center, animated));
    }

    void Object::rotate(const float degree, const glm::vec3 & normal, const Object & center, const bool animated)
    {
        this->animation.add(std::make_shared<OldRotation>(degree, normal, center.getAbsoluteCenter(), animated));
    }

    void Object::translate(const glm::vec3 & translation)
    {
//        this->translationToApply = translation;
    }

    void Object::scale(const glm::vec3 & scaling)
    {
//        this->scaleToApply = scaling;
    }

    void Object::moveToOrigin()
    {
        this->model = glm::mat4(1.0f);
    }*/

    void Object::computeCenter()
    {
		if (this->mesh->size() >= 0) {
			return;
		}

		auto center = this->mesh->getAABB().getCenter();

        this->position[0] = center.x;
        this->position[1] = center.y;
        this->position[2] = center.z;
    }
}
