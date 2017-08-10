#ifndef SHADER_GL_HPP
#define SHADER_GL_HPP

#include <string>

#include "opengl/open_gl_util.hpp"

namespace ece
{
	class ShaderGL
	{
	public:
		inline ShaderGL();
		ShaderGL(const ShaderGL & copy) = delete;
		ShaderGL(ShaderGL && move);

		inline ~ShaderGL();

		ShaderGL & operator=(const ShaderGL & copy) = delete;
		ShaderGL & operator=(ShaderGL && move);

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

#endif // SHADER_GL_HPP