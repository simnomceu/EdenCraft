#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "Scene\Camera.hpp"
#include "Model\Object.hpp"
#include "Renderer\Program.hpp"

namespace ece
{
	class Scene
	{
	public:
		Scene();

		void init();
		void render();
		void addObject(const std::string pathname);

	private:
		Camera cam;
		//std::vector<Object> objects;
		std::vector<std::shared_ptr<Object>> objects;
		glm::mat4 projection;
		Program program;
		//std::shared_ptr<Program> program;
	};
}

#endif // SCENE_HPP