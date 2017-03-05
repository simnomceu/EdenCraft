#ifndef TYPE_HPP 
#define TYPE_HPP 

#include "glm\glm.hpp"
#include "GL\glew.h"

namespace ece
{
	using uint8 = unsigned __int8;
	using uint16 = unsigned __int16;
	using uint32 = unsigned __int32;
	using uint64 = unsigned __int64;

	using int8 = __int8;
	using int16 = __int16;
	using int32 = __int32;
	using int64 = __int64;

	using Matrix4x4 = glm::mat4;
	using Point3D = glm::vec3;
	using Vertex3D = glm::vec3;

	using VertexArrayID = GLuint;
	using VertexBufferID = GLuint;

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

	enum VBOIndex : unsigned short int
	{
		POSITION = 0,
		COLOR = 1
	};

	enum FileCodeError : unsigned short int
	{
		BAD_PATH = 0,
		PARSE_ERROR = 1
	};
}

#endif // TYPE_HPP