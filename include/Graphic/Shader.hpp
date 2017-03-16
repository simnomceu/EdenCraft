#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include "Util\OpenGL\OpenGL.hpp"

namespace ece
{
	class Shader
	{
	public:
		using ShaderID = int;

		Shader() = delete;
		inline Shader(const ShaderType & type); // TODO: shader type should be provided at same time that the source code.
		Shader(const Shader & copy) = delete;
		Shader(Shader && move) = default;

		inline virtual ~Shader() = 0;

		Shader & operator=(const Shader & copy) = delete;
		Shader & operator=(Shader && move) = default;

		virtual void loadFromFile(const std::string & filename) = 0;
		virtual void loadFromString(const std::string & sourceCode) = 0;

		virtual void compile() = 0;

		inline const ShaderID & getId() const;
		inline const ShaderType & getType() const;
		inline const std::string & getFilename() const;

		virtual void reset() = 0;

	protected:
		ShaderID id;
		ShaderType type;
		std::string filename;
	};
}

#include "Shader.inl"

#endif // SHADER_HPP