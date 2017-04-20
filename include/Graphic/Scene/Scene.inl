namespace ece
{
	inline Camera & Scene::getCamera() { return this->camera; }

	inline std::vector<Object> & Scene::getObjects() { return this->objects; }
}