#ifndef PROGRAMGLSL_HPP
#define PROGRAMGLSL_HPP

#include <string>
#include <vector>

#include "GL\glew.h"

namespace ece
{
	class ProgramGLSL
	{
	public:
		enum ShaderType : int
		{
			COMPUTE_SHADER = GL_COMPUTE_SHADER,
			FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
			GEOMETRY_SHADER = GL_GEOMETRY_SHADER,
			VERTEX_SHADER = GL_VERTEX_SHADER,
			TESS_EVALUATION_SHADER = GL_TESS_EVALUATION_SHADER,
			TESS_CONTROL_SHADER = GL_TESS_CONTROL_SHADER
		};

		ProgramGLSL();
		~ProgramGLSL();

		void loadShader(const std::string & pathname, const ShaderType type);
		void link();
		void use();
		void unuse();
		void removeShader(const ShaderType type);

	private:
		struct ShaderScript
		{
			GLuint shaderId;
			ShaderType type;
		};

		GLuint programId;
		std::vector<ShaderScript> shaders;
	};
}

#endif // PROGRAMGLSL_HPP