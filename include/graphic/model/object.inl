#include "graphic/model/mesh.hpp"
#include "graphic/model/skeleton.hpp"
#include "graphic/model/texture.hpp"
#include "graphic/model/shader_effect.hpp"
#include "graphic/model/animation.hpp"

namespace ece
{
	inline Object::Object(): _mesh(nullptr), _skeleton(nullptr), _texture(nullptr), _shaderEffect(nullptr), _animation(nullptr) {}

	inline void Object::setMesh(const std::shared_ptr<Mesh> & mesh) { this->_mesh = mesh; }

	inline void Object::setSkeleton(const std::shared_ptr<Skeleton> & skeleton) { this->_skeleton = skeleton; }

	inline void Object::setTexture(const std::shared_ptr<Texture> & texture) { this->_texture = texture; }

	inline void Object::setShaderEffect(const std::shared_ptr<ShaderEffect> & shaderEffect) { this->_shaderEffect = shaderEffect; }

	inline void Object::setAnimation(const std::shared_ptr<Animation> & animation) { this->_animation = animation; }

	inline std::shared_ptr<Mesh> Object::getMesh() const { return this->_mesh; }

	inline std::shared_ptr<Skeleton> Object::getSkeleton() const { return this->_skeleton; }

	inline std::shared_ptr<Texture> Object::getTexture() const { return this->_texture; }

	inline std::shared_ptr<ShaderEffect> Object::getShaderEffect() const { return this->_shaderEffect; }

	inline std::shared_ptr<Animation> Object::getAnimation() const { return this->_animation; }

	inline Vertex * Object::getVertices() const { return this->_mesh.get(); }
}


