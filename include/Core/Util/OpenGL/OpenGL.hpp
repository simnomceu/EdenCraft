#ifndef OPENGL_HPP
#define OPENGL_HPP

#include "Util\Type.hpp"
#include "glm\glm.hpp"
#include "GL\glew.h"

#include <string>

namespace ece
{
	namespace GL
	{
		using Matrix4x4 = glm::mat4;
		using Point3D = glm::vec3;
		using Vertex3D = glm::vec3;

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

		bool initGLFW();
		bool initGlew();

		inline Matrix4x4 lookAt(Vertex3D position, Point3D target, Vertex3D upAxis);

		ShaderID createShader(const ShaderType & type);
		ProgramID createProgram();

		void compileShader(const ShaderID & shaderHandle, const std::string & source);
		CompilationStatus checkShaderCompilationStatus(const ShaderID & shaderHandle);
		void deleteShader(const ShaderID & shaderHandle);

		void attachShaderToProgram(const ShaderID & shaderHandle, const ProgramID & programHandle);
		void detachShaderFromProgram(const ShaderID & shaderHandle, const ProgramID & programHandle);
	};
}

#include "Util\OpenGL\OpenGL.inl"

#endif // OPENGL_HPP