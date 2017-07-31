#include "Model\Object.hpp"

#include "Renderable\Uniform.hpp"

namespace ece
{
	std::vector<BaseUniform *> Object::getUniforms() const
	{
		// TODO : this method has been generated automatically.
		return std::vector<BaseUniform *>();
	}

	std::vector<ShaderSource *> Object::getShaderSources() const
	{
		std::vector<ShaderSource *> sources;
		for (auto element : this->shaderEffect->getShaders()) {
			sources.push_back(element.get());
		}
		return sources;
	}
}
