#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>

#include "Renderable\Renderable.hpp"

namespace ece
{
	class Mesh;
	class Skeleton;
	class Texture;
	class ShaderEffect;
	class Animation;

    class Object: public Renderable
    {
    public:
        inline Object();
        Object(const Object & copy) = default;
        Object(Object && move) = default;

        ~Object() = default;

        Object & operator=(const Object & copy) = default;
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

		virtual std::vector<Vertex> getVertices() const override;
		virtual std::vector<BaseUniform *> getUniforms() const override;
		virtual std::vector<ShaderSource *> getShaderSources() const override;

    protected:
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Skeleton> skeleton;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<ShaderEffect> shaderEffect;
		std::shared_ptr<Animation> animation;
    };
}

#include "Model\Object.inl"

#endif // OBJECT_HPP