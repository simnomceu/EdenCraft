namespace ece
{
	inline Object::Object() : modeRender(RenderMode::TRIANGLES), vao(0), vboPosition(0), vboColor(0), vertices(), colors(),
		center(0.0f, 0.0f, 0.0f), model(1.0f) {}

	inline Object::Object(const RenderMode mode) : modeRender(mode), vao(0), vboPosition(0), vboColor(0), vertices(),
		colors(), center(0.0f, 0.0f, 0.0f), model(1.0f) {}

	inline Object::~Object() {}

	inline const unsigned int Object::getNbVertices() const { return (int)this->vertices.size() / 3; }

	inline void Object::update(const float elapsedTime) { this->animation.animate(elapsedTime, this->model); }

	inline const Point3D Object::getAbsoluteCenter() const { return this->center; }

	inline const Point3D Object::getRelativeCenter() const { return glm::vec3(this->model * glm::vec4((glm::vec3)this->center, 1)); }

	inline const glm::mat4 & Object::getModel() const { return this->model; }
}