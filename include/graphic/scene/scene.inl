namespace ece
{
	inline Camera & Scene::getCamera() { return this->_camera; }

	inline std::vector<Renderable *> & Scene::getObjects() { return this->_objects; }
}