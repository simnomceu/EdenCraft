#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "Core\Graphic\Rendering\Camera.hpp"
#include "Core\Graphic\Rendering\Object.hpp"

namespace ece
{
	class Scene
	{
	public:
		Scene();

		void render();

	private:
		Camera cam;
		std::vector<Object> objects;
		glm::mat4 projection;
	};
}

#endif // SCENE_HPP