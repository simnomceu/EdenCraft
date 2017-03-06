#include "Rendering\Model\Object.hpp"

#include "Util\File\ParserModelDAT.hpp"
#include "Util\Debug\FileException.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "Rendering\Model\OldGLSLProgram.hpp"
#include "Rendering\Model\OldRotation.hpp"

#include <iostream>
#include <algorithm>

namespace ece
{
    void Object::buildFromFile(const std::string filename)
    {
		ParserModelDAT parser;
        try {
            parser.open(filename);
			this->vertices = parser.getVertices();
			this->colors = parser.getColors();

			this->computeCenter();
        }
        catch(FileException & e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Object::prepare()
    {
        // ===== VAO =====
        if(this->vao == 0) {
            glGenVertexArrays(1, &this->vao);
            glBindVertexArray(this->vao);
            glEnableVertexAttribArray(POSITION);
            glEnableVertexAttribArray(COLOR);
        } else {
            glBindVertexArray(this->vao);
        }

        // ===== VBOs =====
        if (this->vboPosition == 0) {
            glGenBuffers(1, &this->vboPosition);
        }
        glBindBuffer(GL_ARRAY_BUFFER, this->vboPosition);
        glBufferData(GL_ARRAY_BUFFER, 3 * this->vertices.size() * sizeof(GLfloat), this->vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, 0, 0);

        if (this->vboColor == 0) {
            glGenBuffers(1, &this->vboColor);
        }
        glBindBuffer(GL_ARRAY_BUFFER, this->vboColor);
        glBufferData(GL_ARRAY_BUFFER, 3 * this->colors.size() * sizeof(GLfloat), this->colors.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(COLOR, 3, GL_FLOAT, GL_FALSE, 0, 0);

        // ===== Clear Binding =====
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void Object::render(OldGLSLProgram & program, const glm::mat4 & view, const glm::mat4 & projection)
	//void OldObject3D::render(Program & program, const glm::mat4 & view, const glm::mat4 & projection)
    {
		//program.bindInfo(projection * view * this->model, "MVP");
		program.setUniform("MVP", projection * view * this->model);
		program.use();
        glBindVertexArray(this->vao);
        glDrawArrays(this->modeRender, 0, (GLsizei)this->vertices.size()*3);
        glBindVertexArray(0);
    }

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

    /*void Object::updateVertices(const std::vector<Point3D> & vertices)
    {
        if(vertices.size() * 3 == this->vertices.size()) {
            this->vertices.clear();
            for(auto it = vertices.begin(); it != vertices.end(); ++it) {
                this->vertices.push_back((*it)[0]);
                this->vertices.push_back((*it)[1]);
                this->vertices.push_back((*it)[2]);
            }
        }
        this->prepare();
    }*/

    void Object::computeCenter()
    {
		if (this->vertices.size() >= 0) {
			return;
		}

		float xMin = this->vertices[0].x, xMax = this->vertices[0].x,
			yMin = this->vertices[0].y, yMax = this->vertices[0].y,
			zMin = this->vertices[0].z, zMax = this->vertices[0].z;

        int size = (int)this->vertices.size();

		for (int i = 1; i < size; ++i) {
			if (this->vertices[i].x < xMin) {
				xMin = this->vertices[i].x;
			}
			if (this->vertices[i].x > xMax) {
				xMax = this->vertices[i].x;
			}

			if (this->vertices[i].y < yMin) {
				yMin = this->vertices[i].y;
			}
			if (this->vertices[i].y > yMax) {
				yMax = this->vertices[i].y;
			}
			
			if (this->vertices[i].z < zMin) {
				zMin = this->vertices[i].z;
			}
			if (this->vertices[i].z > zMax) {
				zMax = this->vertices[i].z;
			}
		}

        this->position[0] = (xMin + xMax) / 2;
        this->position[1] = (yMin + yMax) / 2;
        this->position[2] = (zMin + zMax) / 2;
    }
}
