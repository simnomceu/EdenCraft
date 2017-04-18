#include "Model\ShaderEffect.hpp"

namespace ece
{
	std::shared_ptr<Shader> ShaderEffect::addShader()
	{
		this->shaders.push_back(std::shared_ptr<Shader>());
		return this->shaders.back();
	}

/*	void ShaderEffect::compileAll()
	{
		// TODO: only one shader of each shader type ?
		for (auto shader : this->shaders) {
			shader->compile();
		}
	}

	void ShaderEffect::terminateAll()
	{
		for (auto shader : this->shaders) {
			shader->terminate();
		}
	}

	void ShaderEffect::attachTo(const GL::ProgramID & programHandle)
	{
		for (auto shader : this->shaders) {
			GL::attachShaderToProgram(shader->getHandle(), programHandle);
		}
	}

	void ShaderEffect::detachFrom(const GL::ProgramID & programHandle)
	{
		for (auto shader : this->shaders) {
			GL::detachShaderFromProgram(shader->getHandle(), programHandle);
		}
	}*/
}