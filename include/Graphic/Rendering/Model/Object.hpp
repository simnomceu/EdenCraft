#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Rendering\Model\OldAnimation.hpp"
#include "Util\Type.hpp"
#include "Rendering\Model\Movable.hpp"
#include "Rendering\Model\Mesh.hpp"

#include <vector>
#include <memory>

namespace ece
{
    class OldGLSLProgram;

    class Object: public Movable
    {
    public:
        inline Object();
        inline Object(const RenderMode mode);
        Object(const Object & copy) = default; // TODO correct it to be sure the clone is a new object (different id)
        Object(Object && move) = default;
        inline ~Object();

        Object & operator=(const Object & copy) = default; // TODO correct it to be sure the clone is a new object (different id)
		Object & operator=(Object && move) = default;

		void loadMeshFromFile(const std::string & filename);

        void prepare();
        inline void update(const float elaspedTime);
        void render(OldGLSLProgram & program, const glm::mat4 & view, const glm::mat4 & projection);
		//void render(Program & program, const glm::mat4 & view, const glm::mat4 & projection);

        inline const Point3D getAbsoluteCenter() const;
        inline const Point3D getRelativeCenter() const;
        inline const Matrix4x4 & getModel() const;

        /*void rotate(const float degree, const glm::vec3 & normal, const bool animated = true);
        void rotate(const float degree, const glm::vec3 & normal, const Point3D & center, const bool animated = true);
        void rotate(const float degree, const glm::vec3 & normal, const Object & center, const bool animated = true);
        void translate(const glm::vec3 & translation);
        void scale(const glm::vec3 & scaling);
        void moveToOrigin();*/

    protected:
		RenderMode modeRender;

		VertexArrayID vao;
		VertexBufferID vboPosition;
		VertexBufferID vboColor;

		std::unique_ptr<Mesh> mesh;

        OldAnimation animation;
        Matrix4x4 model;

        virtual void computeCenter() override;
    };
}

#include "Rendering\Model\Object.inl"

#endif // OBJECT_HPP
