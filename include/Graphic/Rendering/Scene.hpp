#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "Rendering\Scene\Camera.hpp"
#include "Rendering\Model\Object.hpp"
#include "Rendering\Model\Program.hpp"

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