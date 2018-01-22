#include <algorithm>

namespace ece
{
	inline void ShaderEffect::removeShader(std::shared_ptr<Shader> & shader)
	{
		this->_shaders.erase(std::find(this->_shaders.begin(), this->_shaders.end(), shader));
	}

	inline void ShaderEffect::clear() { this->_shaders.clear(); }

	inline std::vector<std::shared_ptr<Shader>> & ShaderEffect::getShaders() { return this->_shaders; }
}
