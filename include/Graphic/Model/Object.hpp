#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Model\Movable.hpp"
//#include "Renderer\Renderable.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class Mesh;
	class Skeleton;
	class Texture;
	class ShaderEffect;
	class Animation;

    class Object//: public Renderable// ,public Movable
    {
    public:
        inline Object();
        //inline Object(const RenderMode mode);
        Object(const Object & copy) = default; // TODO correct it to be sure the clone is a new object (different id)
        Object(Object && move) = default;

        inline ~Object();

        Object & operator=(const Object & copy) = default; // TODO correct it to be sure the clone is a new object (different id)
		Object & operator=(Object && move) = default;

		// NOTE: each element should be build externally from this class, and just "linked" to it when required.
		inline void setMesh(const std::shared_ptr<Mesh> & mesh);
		inline void setSkeleton(const std::shared_ptr<Skeleton> & skeleton);
		inline void setTexture(const std::shared_ptr<Texture> & texture);
		inline void setShaderEffect(const std::shared_ptr<ShaderEffect> & shaderEffect);
		inline void setAnimation(const std::shared_ptr<Animation> & animation);

		// NOTE: accessing one of the elements linked to this object should not modify the object itself
		// but it should also not forbidding modification on the elements.
		inline std::shared_ptr<Mesh> getMesh() const;
		inline std::shared_ptr<Skeleton> getSkeleton() const;
		inline std::shared_ptr<Texture> getTexture() const;
		inline std::shared_ptr<ShaderEffect> getShaderEffect() const;
		inline std::shared_ptr<Animation> getAnimation() const;

		//virtual std::vector<std::string> getLocations() const override;
		//virtual const GL::Matrix4x4 & getModel() const override;

		//virtual void draw() override;

        //void prepare();
        //inline void update(const float elaspedTime);
        //void render(Program & program, const glm::mat4 & view, const glm::mat4 & projection);
		//void render(Program & program, const glm::mat4 & view, const glm::mat4 & projection);

        /*inline const Point3D getAbsoluteCenter() const;
        inline const Point3D getRelativeCenter() const;
        inline const Matrix4x4 & getModel() const;*/

    protected:
		/*VertexBufferID vboPosition;
		VertexBufferID vboColor;*/

		/*OldAnimation animation;
		Matrix4x4 model;*/

		//virtual void computeCenter() override;

		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Skeleton> skeleton;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<ShaderEffect> shaderEffect;
		std::shared_ptr<Animation> animation;

		//GL::VertexArrayID handle;
		//GL::RenderMode renderMode;
    };
}

#include "Model\Object.inl"

#endif // OBJECT_HPP