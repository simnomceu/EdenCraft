#ifndef SHADEREFFECT_HPP
#define SHADEREFFECT_HPP

#include "Model\Shader.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class ShaderEffect
	{
	public:
		ShaderEffect() = default;
		ShaderEffect(const ShaderEffect & copy) = default;
		ShaderEffect(ShaderEffect && move) = default;

		~ShaderEffect() = default;

		ShaderEffect & operator=(const ShaderEffect & copy) = default;
		ShaderEffect & operator=(ShaderEffect && move) = default;

		std::shared_ptr<Shader> addShader();

		inline void clear();

//		void compileAll();
//		void terminateAll();
		
		//void attachTo(const GL::ProgramID & programHandle);
		//void detachFrom(const GL::ProgramID & programHandle);

	private:
		std::vector<std::shared_ptr<Shader>> shaders;
	};
}

#include "Model\ShaderEffect.inl"

#endif // SHADEREFFECT_HPP