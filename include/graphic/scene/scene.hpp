#ifndef SCENE_HPP
#define SCENE_HPP

#include "graphic/scene/camera.hpp"
#include "graphic/scene/projection.hpp"

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
		Camera _camera;
		std::vector<Renderable *> _objects;
	};
}

#include "graphic/scene/scene.inl"

#endif // SCENE_HPP