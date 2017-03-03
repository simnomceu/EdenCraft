#ifndef OLDOBJECT3D_HPP
#define OLDOBJECT3D_HPP

#include "glm\glm.hpp"
#include "GL\glew.h"
#include "Rendering\Model\OldAnimation.hpp"

#include <vector>

namespace ece
{
    class OldGLSLProgram;
	//class Program;

    using Point3D = glm::vec3;

    class OldObject3D
    {
    public:
        OldObject3D();
        OldObject3D(const GLenum mode);
        OldObject3D(const OldObject3D & copy) = default;
        OldObject3D(OldObject3D && move) = default;
        ~OldObject3D();

        OldObject3D & operator=(const OldObject3D & copy) = default;
        OldObject3D & operator=(OldObject3D && move) = default;

        void buildFromFile(const std::string filename);

        const unsigned int getNbVertices() const;
        void prepare();
        void update(const float elaspedTime);
        void render(OldGLSLProgram & program, const glm::mat4 & view, const glm::mat4 & projection);
		//void render(Program & program, const glm::mat4 & view, const glm::mat4 & projection);

        const Point3D getAbsoluteCenter() const;
        const Point3D getRelativeCenter() const;
        const glm::mat4 & getModel() const;

        void rotate(const float degree, const glm::vec3 & normal, const bool animated = true);
        void rotate(const float degree, const glm::vec3 & normal, const Point3D & center, const bool animated = true);
        void rotate(const float degree, const glm::vec3 & normal, const OldObject3D & center, const bool animated = true);
        void translate(const glm::vec3 & translation);
        void scale(const glm::vec3 & scaling);
        void moveToOrigin();

        void updateVertices(const std::vector<Point3D> & vertices);

    protected:
        GLenum modeRender;

        GLuint vao;
        GLuint vbo[2];

        std::vector<float> vertices;
        std::vector<float> colors;

        Point3D center;

        OldAnimation animation;
        glm::mat4 model;

        enum VBOindex : unsigned short int {
            POSITION = 0,
            COLOR = 1
        };

        void computeCenter();
    };
}

#endif // OLDOBJECT3D_HPP
