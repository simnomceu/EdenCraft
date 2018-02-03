#ifndef SHADER_HPP
#define SHADER_HPP

#include "renderer/opengl/opengl.hpp"
#include "renderer/common/shader_stage.hpp"

namespace ece
{
	class Shader
	{
	public:
		Shader();
		inline Shader(const Handle handle);
		Shader(const Shader & copy) = default;
		Shader(Shader && move) = default;

		~Shader() = default;

		Shader & operator=(const Shader & copy) = default;
		Shader & operator=(Shader && move) = default;

		inline Handle getHandle() const;

		virtual void setStage(ShaderStage & shader);
		void link();
		void use() const;

		template<class T> void uniform(const std::string & uniform, const T & value);

	protected:
		Handle _handle;
	};
}

#include "renderer/common/shader.inl"

#endif // SHADER_HPP
