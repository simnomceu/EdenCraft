#include "Rendering\Model\OldObject3D.hpp"

#include "Rendering\Model\OldFile.hpp"
#include "Rendering\Model\OldFileException.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "Rendering\Model\OldGLSLProgram.hpp"
//#include "Rendering\Program.hpp"
#include "Rendering\Model\OldRotation.hpp"

#include <iostream>
#include <algorithm>

namespace ece
{
	OldObject3D::OldObject3D(): modeRender(GL_TRIANGLES), vao(0), vbo{0, 0}, vertices(), colors(),
        center(0.0f, 0.0f, 0.0f), model(1.0f)
    {
    }

	OldObject3D::OldObject3D(const GLenum mode): modeRender(mode), vao(0), vbo{0, 0}, vertices(),
        colors(), center(0.0f, 0.0f, 0.0f), model(1.0f)
    {
    }

	OldObject3D::~OldObject3D()
    {
    }

    void OldObject3D::buildFromFile(const std::string filename)
    {
		OldFile file;
        try {
            file.openFile(filename, std::ios_base::in);
        }
        catch(OldFileException & e) {
            std::cerr << e.what() << std::endl;
        }

        std::vector<float> tmp(file.copyToVector<float>());
        int size = (int)tmp.size() / 2;
        this->vertices.insert(this->vertices.begin(), tmp.begin(), tmp.begin() + size);
        this->colors.insert(this->colors.begin(), tmp.begin() + size, tmp.end());

        this->computeCenter();
    }

    const unsigned int OldObject3D::getNbVertices() const
    {
        return (int)this->vertices.size() / 3;
    }

    void OldObject3D::prepare()
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
        if (this->vbo[POSITION] == 0) {
            glGenBuffers(1, this->vbo + POSITION);
        }
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo[POSITION]);
        glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(GLfloat), this->vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, 0, 0);

        if (this->vbo[COLOR] == 0) {
            glGenBuffers(1, this->vbo + COLOR);
        }
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo[COLOR]);
        glBufferData(GL_ARRAY_BUFFER, this->colors.size() * sizeof(GLfloat), this->colors.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(COLOR, 3, GL_FLOAT, GL_FALSE, 0, 0);

        // ===== Clear Binding =====
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void OldObject3D::update(const float elapsedTime)
    {
        this->animation.animate(elapsedTime, this->model);
    }

    void OldObject3D::render(OldGLSLProgram & program, const glm::mat4 & view, const glm::mat4 & projection)
	//void OldObject3D::render(Program & program, const glm::mat4 & view, const glm::mat4 & projection)
    {
		//program.bindInfo(projection * view * this->model, "MVP");
		program.setUniform("MVP", projection * view * this->model);
		program.use();
        glBindVertexArray(this->vao);
        glDrawArrays(this->modeRender, 0, (GLsizei)this->vertices.size());
        glBindVertexArray(0);
    }

    const Point3D OldObject3D::getAbsoluteCenter() const
    {
        return this->center;
    }

    const Point3D OldObject3D::getRelativeCenter() const
    {
        return glm::vec3(this->model * glm::vec4((glm::vec3)this->center, 1));
    }

    const glm::mat4 & OldObject3D::getModel() const
    {
        return this->model;
    }

    void OldObject3D::rotate(const float degree, const glm::vec3 & normal, const bool animated)
    {
        this->animation.add(std::make_shared<OldRotation>(degree, normal, animated));
    }

    void OldObject3D::rotate(const float degree, const glm::vec3 & normal, const Point3D & center, const bool animated)
    {
        this->animation.add(std::make_shared<OldRotation>(degree, normal, center, animated));
    }

    void OldObject3D::rotate(const float degree, const glm::vec3 & normal, const OldObject3D & center, const bool animated)
    {
        this->animation.add(std::make_shared<OldRotation>(degree, normal, center.getAbsoluteCenter(), animated));
    }

    void OldObject3D::translate(const glm::vec3 & translation)
    {
//        this->translationToApply = translation;
    }

    void OldObject3D::scale(const glm::vec3 & scaling)
    {
//        this->scaleToApply = scaling;
    }

    void OldObject3D::moveToOrigin()
    {
        this->model = glm::mat4(1.0f);
    }

    void OldObject3D::updateVertices(const std::vector<Point3D> & vertices)
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
    }

    void OldObject3D::computeCenter()
    {
        float xMin = this->vertices[0], xMax = this->vertices[0],
                yMin = this->vertices[1], yMax = this->vertices[1],
                zMin = this->vertices[2], zMax = this->vertices[2];

        int size = (int)this->vertices.size();
        for(int i = 3; i < size; ++i) {
            if (i%3 == 0) {
                if(this->vertices[i] < xMin) {
                    xMin = this->vertices[i];
                }
                if(this->vertices[i] > xMax) {
                    xMax = this->vertices[i];
                }
            } else if (i%3 == 1) {
                if(this->vertices[i] < yMin) {
                    yMin = this->vertices[i];
                }
                if(this->vertices[i] > yMax) {
                    yMax = this->vertices[i];
                }
            } else if (i%3 == 2){
                if(this->vertices[i] < zMin) {
                    zMin = this->vertices[i];
                }
                if(this->vertices[i] > zMax) {
                    zMax = this->vertices[i];
                }
            }
        }

        this->center[0] = (xMin + xMax) / 2;
        this->center[1] = (yMin + yMax) / 2;
        this->center[2] = (zMin + zMax) / 2;
    }
}
