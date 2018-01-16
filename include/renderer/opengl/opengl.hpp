#ifndef OPENGL_HPP
#define OPENGL_HPP

#include <memory>
#include <vector>
#include <bitset>

#ifdef __unix__
#include "renderer/x11/glx_extension.hpp"
#elif __WINDOW__
#include "renderer/win32/wgl_extension.hpp"
#elif __OSX__
#include "renderer/cocoa/agl_extension.hpp"
#else
#include "renderer/win32/wgl_extension.hpp"
#endif

#include "renderer/opengl/opengl_exception.hpp"
#include "utility/mathematics/matrix2u.hpp"
#include "utility/mathematics/matrix3u.hpp"
#include "utility/mathematics/matrix4u.hpp"
#include "utility/mathematics/vector2u.hpp"
#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/vector4u.hpp"

namespace ece
{
	enum ShaderType : unsigned short int
	{
		COMPUTE_SHADER			= GL_COMPUTE_SHADER,
		FRAGMENT_SHADER			= GL_FRAGMENT_SHADER,
		GEOMETRY_SHADER			= GL_GEOMETRY_SHADER,
		VERTEX_SHADER			= GL_VERTEX_SHADER,
		TESS_EVALUATION_SHADER	= GL_TESS_EVALUATION_SHADER,
		TESS_CONTROL_SHADER		= GL_TESS_CONTROL_SHADER
	};

	enum BufferType : unsigned short int
	{
		ARRAY_BUFFER				= GL_ARRAY_BUFFER,
		ATOMIC_COUNTER_BUFFER		= GL_ATOMIC_COUNTER_BUFFER,
		COPY_READ_BUFFER			= GL_COPY_READ_BUFFER,
		COPY_WRITE_BUFFER			= GL_COPY_WRITE_BUFFER,
		DISPATCH_INDIRECT_BUFFER	= GL_DISPATCH_INDIRECT_BUFFER,
		DRAW_INDIRECT_BUFFER		= GL_DRAW_INDIRECT_BUFFER,
		ELEMENT_ARRAY_BUFFER		= GL_ELEMENT_ARRAY_BUFFER,
		PIXEL_PACK_BUFFER			= GL_PIXEL_PACK_BUFFER,
		PIXEL_UNPACK_BUFFER			= GL_PIXEL_UNPACK_BUFFER,
		QUERY_BUFFER				= GL_QUERY_BUFFER,
		SHADER_STORAGE_BUFFER		= GL_SHADER_STORAGE_BUFFER,
		TEXTURE_BUFFER				= GL_TEXTURE_BUFFER,
		TRANSFORM_FEEDBACK_BUFFER	= GL_TRANSFORM_FEEDBACK,
		UNIFORM_BUFFER				= GL_UNIFORM_BUFFER
	};

	enum BufferUsage : unsigned short int
	{
		STREAM_DRAW		= GL_STREAM_DRAW,
		STREAM_READ		= GL_STREAM_READ,
		STREAM_COPY		= GL_STREAM_COPY,
		STATIC_DRAW		= GL_STATIC_DRAW,
		STATIC_READ		= GL_STATIC_READ,
		STATIC_COPY		= GL_STATIC_COPY,
		DYNAMIC_DRAW	= GL_DYNAMIC_DRAW,
		DYNAMIC_READ	= GL_DYNAMIC_READ,
		DYNAMIC_COPY	= GL_DYNAMIC_COPY
	};

	enum DataType : unsigned short int
	{
		BYTE							= GL_BYTE,
		UNSIGNED_BYTE					= GL_UNSIGNED_BYTE,
		SHORT							= GL_SHORT,
		UNSIGNED_SHORT					= GL_UNSIGNED_SHORT,
		INT								= GL_INT,
		UNSIGNED_INT					= GL_UNSIGNED_INT,
		HALF_FLOAT						= GL_HALF_FLOAT,
		FLOAT							= GL_FLOAT,
		DOUBLE							= GL_DOUBLE,
		FIXED							= GL_FIXED,
		INT_2_10_10_10_REV				= GL_INT_2_10_10_10_REV,
		UNSIGNED_INT_2_10_10_10_REV		= GL_UNSIGNED_INT_2_10_10_10_REV,
		UNSIGNED_INT_10F_11F_11F_REV	= GL_UNSIGNED_INT_10F_11F_11F_REV
	};

	enum PrimitiveMode : unsigned short int
	{
		POINTS = GL_POINTS,
		LINE_STRIP = GL_LINE_STRIP,
		LINE_LOOP = GL_LINE_LOOP,
		LINES = GL_LINES,
		LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
		LINES_ADJACENCY = GL_LINES_ADJACENCY,
		TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
		TRIANGLE_FAN = GL_TRIANGLE_FAN,
		TRIANGLES = GL_TRIANGLES,
		TRIANGLES_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
		TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
		PATCHES = GL_PATCHES
	};

	using ShaderHandle = unsigned short int;
	using ProgramHandle = unsigned short int;
	using UniformHandle = unsigned short int;
	using VBOHandle = unsigned int;
	using VAOHandle = unsigned int;

	class OpenGL
	{
	public:
		~OpenGL() = default;

		static void init(const OptionOpenGL options);

		static unsigned int getError();
		static void checkErrors();

		static ShaderHandle createShader(const ShaderType type);
		static void shaderSource(const ShaderHandle handle, const std::string & source);
		static void shaderSource(const ShaderHandle handle, const std::vector<std::string> & source);
		static void compileShader(const ShaderHandle handle);
		static void deleteShader(const ShaderHandle handle);

		static ProgramHandle createProgram();
		static void attachShader(const ProgramHandle program, const ShaderHandle shader);
		static void linkProgram(const ProgramHandle handle);
		static void useProgram(const ProgramHandle handle);

		static UniformHandle getUniformLocation(const ProgramHandle handle, const std::string & uniform);
		template<class T> static void uniform(const UniformHandle uniform, const T value);
		template<> static void uniform(const UniformHandle uniform, const int value);
		template<> static void uniform(const UniformHandle uniform, const float value);
		template<> static void uniform(const UniformHandle uniform, const bool value);
		template<> static void uniform(const UniformHandle uniform, const IntVector2u value);
		template<> static void uniform(const UniformHandle uniform, const IntVector3u value);
		template<> static void uniform(const UniformHandle uniform, const IntVector4u value);
		template<> static void uniform(const UniformHandle uniform, const FloatVector2u value);
		template<> static void uniform(const UniformHandle uniform, const FloatVector3u value);
		template<> static void uniform(const UniformHandle uniform, const FloatVector4u value);
		template<> static void uniform(const UniformHandle uniform, const FloatMatrix2u value);
		template<> static void uniform(const UniformHandle uniform, const FloatMatrix3u value);
		template<> static void uniform(const UniformHandle uniform, const FloatMatrix4u value);

		static void genBuffers(VBOHandle & handle);
		static void genBuffers(const int count, std::vector<VBOHandle> & handles);
		static void bindBuffer(const BufferType type, const VBOHandle handle);
		template<class T> static void bufferData(const BufferType type, const std::vector<T> & data, const BufferUsage usage);
		static void genVertexArrays(VAOHandle & handle);
		static void genVertexArrays(const int count, std::vector<VAOHandle> & handles);
		static void bindVertexArray(const VAOHandle handle);
		template<class T> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset);
		template<> static void vertexAttribPointer<short>(const int location, const int size, const bool normalized, const int offset);
		template<> static void vertexAttribPointer<unsigned short>(const int location, const int size, const bool normalized, const int offset);
		template<> static void vertexAttribPointer<int>(const int location, const int size, const bool normalized, const int offset);
		template<> static void vertexAttribPointer<unsigned int>(const int location, const int size, const bool normalized, const int offset);
		template<> static void vertexAttribPointer<float>(const int location, const int size, const bool normalized, const int offset);
		template<> static void vertexAttribPointer<double>(const int location, const int size, const bool normalized, const int offset);
		template<class T> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<T> & data);
		template<> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<short> & data);
		template<> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned short> & data);
		template<> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<int> & data);
		template<> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned int> & data);
		template<> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<float> & data);
		template<> static void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<double> & data);
		static void enableVertexAttribArray(const int location);
		static void disableVertexAttribArray(const int location);

	private:
		OpenGL() = default;
		OpenGL(const OpenGL & copy) = default;
		OpenGL(OpenGL && move) = default;

		static std::unique_ptr<OpenGLExtension> extensions;

		OpenGL & operator=(const OpenGL & copy) = default;
		OpenGL & operator=(OpenGL && move) = default;
	};
}

#include "renderer/opengl/opengl.inl"

#endif // OPENGL_HPP
