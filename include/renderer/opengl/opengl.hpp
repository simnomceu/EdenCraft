#ifndef OPENGL_HPP
#define OPENGL_HPP

#include <memory>
#include <vector>
#include <bitset>
#include <array>

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
#include "renderer/enum.hpp"

namespace ece
{
	using Handle = unsigned int;

	class OpenGL
	{
	public:
		~OpenGL() = default;

		static void init(const OptionOpenGL options);

		static inline int getLatestMinorVersion();
		static inline int getLatestMajorVersion();

		static unsigned int getError();
		static void checkErrors(const std::string & location);

		static void clear(const Bitfield mask);
		static void clearColor(const float r, const float g, const float b, const float a);
		static void enable(const Capability cap);
		static void disable(const Capability cap);
		static void enableIndexed(const Capability cap, const unsigned short int index);
		static void disableIndexed(const Capability cap, const unsigned short int index);

		static void cullFace(const CullFaceMode mode);
		static void frontFace(const FrontFaceMode mode);
		static void depthFunc(const DepthFunctionCondition condition);

		static void getInteger(const Parameter parameter, int & data);
		static void getString(const InfoGL parameter, std::string & data);

		static void getIntegers(const Parameter parameter, std::vector<int> & data);

		static Handle createShader(const ShaderType type);
		static void shaderSource(const Handle handle, const std::string & source);
		static void shaderSource(const Handle handle, const std::vector<std::string> & source);
		static void compileShader(const Handle handle);
		static void deleteShader(const Handle handle);

		static Handle createProgram();
		static void attachShader(const Handle program, const Handle shader);
		static void linkProgram(const Handle handle);
		static void useProgram(const Handle handle);

		static Handle getUniformLocation(const Handle handle, const std::string & uniform);
		template<class T> static void uniform(const Handle uniform, const T value);
		template<> static void uniform(const Handle uniform, const int value);
		template<> static void uniform(const Handle uniform, const float value);
		template<> static void uniform(const Handle uniform, const bool value);
		template<> static void uniform(const Handle uniform, const IntVector2u value);
		template<> static void uniform(const Handle uniform, const IntVector3u value);
		template<> static void uniform(const Handle uniform, const IntVector4u value);
		template<> static void uniform(const Handle uniform, const FloatVector2u value);
		template<> static void uniform(const Handle uniform, const FloatVector3u value);
		template<> static void uniform(const Handle uniform, const FloatVector4u value);
		template<> static void uniform(const Handle uniform, const FloatMatrix2u value);
		template<> static void uniform(const Handle uniform, const FloatMatrix3u value);
		template<> static void uniform(const Handle uniform, const FloatMatrix4u value);

		static void genBuffers(Handle & handle);
		static void genBuffers(const int count, std::vector<Handle> & handles);
		static void bindBuffer(const BufferType type, const Handle handle);
		template<class T> static void bufferData(const BufferType type, const std::vector<T> & data, const BufferUsage usage);
		static void genVertexArrays(Handle & handle);
		static void genVertexArrays(const int count, std::vector<Handle> & handles);
		static void bindVertexArray(const Handle handle);
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

		static void drawArrays(const PrimitiveMode mode, const int first, const unsigned int count);
		static void drawElements(const PrimitiveMode mode, const unsigned int count, const DataType type, const int offset);

	private:
		OpenGL() = default;
		OpenGL(const OpenGL & copy) = default;
		OpenGL(OpenGL && move) = default;

		static std::unique_ptr<OpenGLExtension> _extensions;
		static std::array<int, 2> _latestVersion;

		OpenGL & operator=(const OpenGL & copy) = default;
		OpenGL & operator=(OpenGL && move) = default;
	};
}

#include "renderer/opengl/opengl.inl"

#endif // OPENGL_HPP
