#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "Rendering\Camera.hpp"
#include "Rendering\Object.hpp"

namespace ece
{
	class Scene
	{
	public:
		Scene();

		void render();
		void addObject(const std::string pathname);

	private:
		Camera cam;
		std::vector<Object> objects;
		glm::mat4 projection;
	};
}

#endif // SCENE_HPP