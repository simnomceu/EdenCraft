#ifndef SCENE_HPP
#define SCENE_HPP

#include "scene/camera.hpp"
#include "scene/projection.hpp"

#include <vector>

namespace ece
{
	class Renderable;
	class Object;

	class Scene
	{
	public:
		Scene();
		Scene(const Scene & copy) = default;
		Scene(Scene && move) = default;

		~Scene() = default;

		Scene & operator=(const Scene & copy) = default;
		Scene & operator=(Scene && move) = default;

		Object * addObject();

		inline Camera & getCamera();
		inline std::vector<Renderable *> & getObjects();

	private:
		Camera camera;
		std::vector<Renderable *> objects;
	};
}

#include "scene/scene.inl"

#endif // SCENE_HPP