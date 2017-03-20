namespace ece
{
	inline Camera & Scene::getCamera() { return this->camera; }

	inline Projection & Scene::getProjection() { return this->projection; }

	inline std::vector<Renderable *> & Scene::getObjects() { return this->objects; }
}