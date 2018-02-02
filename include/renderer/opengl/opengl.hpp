#ifndef OPENGL_HPP
#define OPENGL_HPP

#include <memory>
#include <vector>
#include <bitset>
#include <array>

/*#ifdef __unix__
#include "renderer/x11/glx_extension.hpp"
#elif __WINDOW__
#include "renderer/win32/wgl_extension.hpp"
#elif __OSX__
#include "renderer/cocoa/agl_extension.hpp"
#else
#include "renderer/win32/wgl_extension.hpp"
#endif*/

#include "renderer/opengl/opengl_exception.hpp"
#include "utility/mathematics/matrix2u.hpp"
#include "utility/mathematics/matrix3u.hpp"
#include "utility/mathematics/matrix4u.hpp"
#include "utility/mathematics/vector2u.hpp"
#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/vector4u.hpp"
#include "renderer/enum.hpp"
#include "utility/indexing/version.hpp"

namespace ece
{
	using Handle = unsigned short int;

	class OpenGL
	{
	public:
		~OpenGL() = default;

		static void init(const Version<2> & minVersionGL, const Version<2> & maxVersionGL);

		static inline unsigned short int getLatestMinorVersion();
		static inline unsigned short int getLatestMajorVersion();

		static inline ErrorGL getError();
		static void checkErrors(const std::string & location);

		static inline void clear(const Bitfield mask);
		static inline void clearColor(const float r, const float g, const float b, const float a);
		static inline void enable(const Capability cap);
		static inline void disable(const Capability cap);
		static inline void enableIndexed(const Capability cap, const unsigned short int index);
		static inline void disableIndexed(const Capability cap, const unsigned short int index);

		static inline void cullFace(const CullFaceMode mode);
		static inline void frontFace(const FrontFaceMode mode);
		static inline void depthFunc(const DepthFunctionCondition condition);

		static inline void getInteger(const Parameter parameter, int & data);
		static inline std::string getString(const InfoGL parameter);

/*		static inline void getIntegers(const Parameter parameter, std::vector<int> & data);*/

		static inline Handle createShader(const ShaderType type);
		static inline void shaderSource(const Handle handle, const std::string & source);
		static inline void shaderSource(const Handle handle, const std::vector<std::string> & source);
		static inline void compileShader(const Handle handle);
		static inline void deleteShader(const Handle handle);

		static inline Handle createProgram();
		static inline void attachShader(const Handle program, const Handle shader);
		static inline void linkProgram(const Handle handle);
		static inline void useProgram(const Handle handle);
/*
		static inline Handle getUniformLocation(const Handle handle, const std::string & uniform);
		template<class T> static inline void uniform(const Handle uniform, const T value);
		template<> static inline void uniform(const Handle uniform, const int value);
		template<> static inline void uniform(const Handle uniform, const float value);
		template<> static inline void uniform(const Handle uniform, const bool value);
		template<> static inline void uniform(const Handle uniform, const IntVector2u value);
		template<> static inline void uniform(const Handle uniform, const IntVector3u value);
		template<> static inline void uniform(const Handle uniform, const IntVector4u value);
		template<> static inline void uniform(const Handle uniform, const FloatVector2u value);
		template<> static inline void uniform(const Handle uniform, const FloatVector3u value);
		template<> static inline void uniform(const Handle uniform, const FloatVector4u value);
		template<> static inline void uniform(const Handle uniform, const FloatMatrix2u value);
		template<> static inline void uniform(const Handle uniform, const FloatMatrix3u value);
		template<> static inline void uniform(const Handle uniform, const FloatMatrix4u value);*/

		static inline Handle genBuffers();
		static inline std::vector<Handle> genBuffers(const int count);
		static inline void bindBuffer(const BufferType type, const Handle handle);
		template<class T> static inline void bufferData(const BufferType type, const std::vector<T> & data, const BufferUsage usage);
		static inline void genVertexArrays(Handle & handle);
		static inline void genVertexArrays(const int count, std::vector<Handle> & handles);
		static inline void bindVertexArray(const Handle handle);
		template<class T> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset);
		template<> static inline void vertexAttribPointer<short>(const int location, const int size, const bool normalized, const int offset);
		template<> static inline void vertexAttribPointer<unsigned short>(const int location, const int size, const bool normalized, const int offset);
		template<> static inline void vertexAttribPointer<int>(const int location, const int size, const bool normalized, const int offset);
		template<> static inline void vertexAttribPointer<unsigned int>(const int location, const int size, const bool normalized, const int offset);
		template<> static inline void vertexAttribPointer<float>(const int location, const int size, const bool normalized, const int offset);
		template<> static inline void vertexAttribPointer<double>(const int location, const int size, const bool normalized, const int offset);
		template<class T> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<T> & data);
		template<> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<short> & data);
		template<> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned short> & data);
		template<> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<int> & data);
		template<> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned int> & data);
		template<> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<float> & data);
		template<> static inline void vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<double> & data);
		static inline void enableVertexAttribArray(const int location);
/*		static inline void disableVertexAttribArray(const int location);

		static inline void drawArrays(const PrimitiveMode mode, const int first, const unsigned int count);*/
		static inline void drawElements(const PrimitiveMode mode, const unsigned int count, const DataType type, const int offset);
		
	private:
		OpenGL() = default;
		OpenGL(const OpenGL & copy) = default;
		OpenGL(OpenGL && move) = default;

		static Version<2> _latestVersion;

		OpenGL & operator=(const OpenGL & copy) = default;
		OpenGL & operator=(OpenGL && move) = default;
	};
}

#include "renderer/opengl/opengl.inl"

#endif // OPENGL_HPP
