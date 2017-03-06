#include "Movable.hpp"
namespace ece
{
	inline Movable::Movable(): position(0.0f, 0.0f, 0.0f) {}

	inline Movable::~Movable() {}

	inline const glm::vec3 & Movable::getPosition() const { return this->position; }
}