namespace ece
{
	inline Object::Object() : Movable(), modeRender(RenderMode::TRIANGLES), vao(0), vboPosition(0), vboColor(0), vertices(), colors(), model(1.0f) {}

	inline Object::Object(const RenderMode mode) : Movable(), modeRender(mode), vao(0), vboPosition(0), vboColor(0), vertices(),
		colors(), model(1.0f) {}

	inline Object::~Object() {}

	inline const unsigned int Object::getNbVertices() const { return (int)this->vertices.size() / 3; }

	inline void Object::update(const float elapsedTime) { this->animation.animate(elapsedTime, this->model); }

	inline const Point3D Object::getAbsoluteCenter() const { return this->getPosition(); }

	inline const Point3D Object::getRelativeCenter() const { return glm::vec3(this->model * glm::vec4((glm::vec3)this->getPosition(), 1)); }

	inline const glm::mat4 & Object::getModel() const { return this->model; }
}