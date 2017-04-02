#include "Model\Mesh.hpp"
#include "Model\Skeleton.hpp"
#include "Model\Texture.hpp"
#include "Model\ShaderEffect.hpp"
#include "Model\Animation.hpp"
#include "Object.hpp"


namespace ece
{
	/*inline Object::Object() : Movable(), modeRender(RenderMode::TRIANGLES), vao(NULL_ID), vboPosition(NULL_ID), vboColor(NULL_ID), 
		mesh(nullptr), model(1.0f) {}*/

	/*inline Object::Object(const RenderMode mode) : Movable(), modeRender(mode), vao(NULL_ID), vboPosition(0), vboColor(0), mesh(nullptr),
		model(1.0f) {}*/

	//inline Object::~Object() { this->mesh.reset(); }


	//inline void Object::update(const float elapsedTime) { this->animation.animate(elapsedTime, this->model); }

	/*inline const Point3D Object::getAbsoluteCenter() const { return this->getPosition(); }

	inline const Point3D Object::getRelativeCenter() const { return glm::vec3(this->model * glm::vec4((glm::vec3)this->getPosition(), 1)); }

	inline const glm::mat4 & Object::getModel() const { return this->model; }*/

	inline Object::Object(): mesh(nullptr), skeleton(nullptr), texture(nullptr), shaderEffect(nullptr), animation(nullptr), 
		handle(GL::NULL_ID), renderMode(GL::TRIANGLES) {}

	inline Object::~Object() {}

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
}


