#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "Rendering\Scene\Camera.hpp"
//#include "Rendering\Object.hpp"
#include "Rendering\Model\OldObject3D.hpp"
#include "Rendering\Model\OldGLSLProgram.hpp"

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
		std::vector<std::shared_ptr<OldObject3D>> objects;
		glm::mat4 projection;
		OldGLSLProgram program;
		//std::shared_ptr<Program> program;
	};
}

#endif // SCENE_HPP