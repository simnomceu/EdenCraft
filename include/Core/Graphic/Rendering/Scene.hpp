#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "Core\Graphic\Rendering\Object.hpp"

namespace ece
{
	class Scene
	{
	public:
		Scene() = default;

	private:
		std::vector<Object> objects;
	};
}

#endif // SCENE_HPP