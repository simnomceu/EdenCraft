namespace ece
{
	inline Camera & Scene::getCamera() { return this->camera; }

	inline std::vector<Renderable *> & Scene::getObjects() { return this->objects; }
}