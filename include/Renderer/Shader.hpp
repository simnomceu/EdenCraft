#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include "Util\OpenGL\OpenGL.hpp"

namespace ece
{
	class Shader
	{
	public:
		inline Shader();
		Shader(const Shader & copy) = delete;
		Shader(Shader && move);

		inline ~Shader();

		Shader & operator=(const Shader & copy) = delete;
		Shader & operator=(Shader && move);

		void loadFromFile(const GL::ShaderType & type, const std::string & filename);
		void loadFromString(const GL::ShaderType & type, const std::string & sourceCode);

		inline const std::string & getFilename() const;
		inline const std::string & getSource() const;
		inline const GL::ShaderType & getType() const;

		inline const GL::ShaderID & getHandle() const;

		void compile();
		void terminate();

	private:
		std::string filename;
		std::string source;
		GL::ShaderType type;

		GL::ShaderID handle;
	};
}

#include "Renderer\Shader.inl"

#endif // SHADER_HPP