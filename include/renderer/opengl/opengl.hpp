#ifndef OPENGL_HPP
#define OPENGL_HPP

#include <memory>
#include <vector>

#ifdef __unix__
#include "renderer/x11/glx_extension.hpp"
#elif __WINDOW__
#include "renderer/win32/wgl_extension.hpp"
#elif __OSX__
#include "renderer/cocoa/agl_extension.hpp"
#else
#include "renderer/win32/wgl_extension.hpp"
#endif

#include "utility/mathematics/matrix2u.hpp"
#include "utility/mathematics/matrix3u.hpp"
#include "utility/mathematics/matrix4u.hpp"

namespace ece
{
	enum ShaderType : unsigned short int {
		ECE_NULL_SHADER = 0,
		ECE_COMPUTE_SHADER = 1,
		ECE_FRAGMENT_SHADER = 2,
		ECE_GEOMETRY_SHADER = 3,
		ECE_VERTEX_SHADER = 4,
		ECE_TESS_EVALUATION_SHADER = 5,
		ECE_TESS_CONTROL_SHADER = 6
	};

	using ShaderHandle = unsigned short int;
	using ProgramHandle = unsigned short int;
	using UniformHandle = unsigned short int;

	class OpenGL
	{
	public:
		~OpenGL() = default;

		static void init(const OptionOpenGL options);

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
		template<> static void uniform(const UniformHandle uniform, const IntVertex2u value);
		template<> static void uniform(const UniformHandle uniform, const IntVertex3u value);
		template<> static void uniform(const UniformHandle uniform, const IntVertex4u value);
		template<> static void uniform(const UniformHandle uniform, const FloatVertex2u value);
		template<> static void uniform(const UniformHandle uniform, const FloatVertex3u value);
		template<> static void uniform(const UniformHandle uniform, const FloatVertex4u value);
		template<> static void uniform(const UniformHandle uniform, const FloatMatrix2u value);
		template<> static void uniform(const UniformHandle uniform, const FloatMatrix3u value);
		template<> static void uniform(const UniformHandle uniform, const FloatMatrix4u value);

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
