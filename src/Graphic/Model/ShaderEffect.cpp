#include "Model\ShaderEffect.hpp"

namespace ece
{
	std::shared_ptr<Shader> ShaderEffect::addShader()
	{
		this->shaders.push_back(std::make_shared<Shader>());
		return this->shaders.back();
	}
}