#include "model\mesh.hpp"
#include "model\skeleton.hpp"
#include "model\texture.hpp"
#include "model\shader_effect.hpp"
#include "model\animation.hpp"

namespace ece
{
	inline Object::Object(): mesh(nullptr), skeleton(nullptr), texture(nullptr), shaderEffect(nullptr), animation(nullptr) {}

	inline void Object::setMesh(const std::shared_ptr<Mesh> & mesh) { this->mesh = mesh; }

	inline void Object::setSkeleton(const std::shared_ptr<Skeleton> & skeleton) { this->skeleton = skeleton; }

	inline void Object::setTexture(const std::shared_ptr<Texture> & texture) { this->texture = texture; }

	inline void Object::setShaderEffect(const std::shared_ptr<ShaderEffect> & shaderEffect) { this->shaderEffect = shaderEffect; }

	inline void Object::setAnimation(const std::shared_ptr<Animation> & animation) { this->animation = animation; }

	inline std::shared_ptr<Mesh> Object::getMesh() const { return this->mesh; }

	inline std::shared_ptr<Skeleton> Object::getSkeleton() const { return this->skeleton; }

	inline std::shared_ptr<Texture> Object::getTexture() const { return this->texture; }

	inline std::shared_ptr<ShaderEffect> Object::getShaderEffect() const { return this->shaderEffect; }

	inline std::shared_ptr<Animation> Object::getAnimation() const { return this->animation; }

	inline Vertex * Object::getVertices() const { return this->mesh.get(); }
}


