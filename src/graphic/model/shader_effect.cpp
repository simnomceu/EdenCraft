#include "graphic/model/shader_effect.hpp"

namespace ece
{
	std::shared_ptr<Shader> ShaderEffect::addShader()
	{
		this->_shaders.push_back(std::make_shared<Shader>());
		return this->_shaders.back();
	}
}