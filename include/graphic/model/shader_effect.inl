#include <algorithm>

namespace ece
{
	inline void ShaderEffect::removeShader(std::shared_ptr<Shader> & shader)
	{
		this->shaders.erase(std::find(this->shaders.begin(), this->shaders.end(), shader));
	}

	inline void ShaderEffect::clear() { this->shaders.clear(); }

	inline std::vector<std::shared_ptr<Shader>> & ShaderEffect::getShaders() { return this->shaders; }
}
