#ifndef OPEN_GL_UTIL_HPP
#define OPEN_GL_UTIL_HPP

#include "type.hpp"
#include "glm\glm.hpp"
#include "gl\glew.h"

#include <string>

namespace ece
{
	namespace GL
	{
		//TODO: rename as XxxxxxHandle instead of XxxxxxID ?
		using VertexArrayID = GLuint;
		using VertexBufferID = GLuint;
		using ProgramID = GLuint;
		using ShaderID = GLuint;

		static const unsigned short int NULL_ID = 0;

		enum RenderMode : GLenum
		{
			POINTS = GL_POINTS,
			LINES = GL_LINES,
			LINE_STRIP = GL_LINE_STRIP,
			LINE_LOOP = GL_LINE_LOOP,
			TRIANGLES = GL_TRIANGLES,
			TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
			TRIANGLE_FAN = GL_TRIANGLE_FAN,
			QUADS = GL_QUADS,
			QUAD_STRIP = GL_QUAD_STRIP,
			POLYGON = GL_POLYGON
		};

		enum ShaderType : GLenum
		{
			COMPUTE_SHADER = GL_COMPUTE_SHADER,
			FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
			GEOMETRY_SHADER = GL_GEOMETRY_SHADER,
			VERTEX_SHADER = GL_VERTEX_SHADER,
			TESS_EVALUATION_SHADER = GL_TESS_EVALUATION_SHADER,
			TESS_CONTROL_SHADER = GL_TESS_CONTROL_SHADER,
			NULL_TYPE_SHADER
		};

		enum VBOIndex : unsigned short int
		{
			POSITION = 0,
			COLOR = 1
		};

		struct CompilationStatus
		{
			ShaderType type;
			bool deleteFlag;
			bool compiled;
			std::string log;
			std::string source;
		};

		ShaderID createShader(const ShaderType & type);
		ProgramID createProgram();

		void compileShader(const ShaderID & shaderHandle, const std::string & source);
		CompilationStatus checkShaderCompilationStatus(const ShaderID & shaderHandle);
		void deleteShader(const ShaderID & shaderHandle);

		void attachShaderToProgram(const ShaderID & shaderHandle, const ProgramID & programHandle);
		void detachShaderFromProgram(const ShaderID & shaderHandle, const ProgramID & programHandle);

		VertexArrayID createObject();
		void renderObject(const VertexArrayID & objectHandle, const RenderMode & renderMode, const unsigned int numberOfVertices);
	};
}

#endif // OPEN_GL_UTIL_HPP