#include "OpenGL\OpenGL.hpp"

#include "Log\ServiceLogger.hpp"
#include "GLFW\glfw3.h"
#include "Debug\Exception.hpp"

#include <vector>

namespace ece
{
	namespace GL
	{
		bool initGLFW()
		{
			if (!glfwInit()) {
				ServiceLoggerLocator::getService().logError("GLFW has encoutered a problem and couldn't be initialized.");
				return false;
			}
			else {
				int major, minor, rev;
				glfwGetVersion(&major, &minor, &rev);
				ServiceLoggerLocator::getService().logInfo("GLFW initialized in version " + std::to_string(major) + "." + std::to_string(minor)
					+ "." + std::to_string(rev));
				return true;
			}
		}

		bool initGlew()
		{
			// Required to use VAO & VBO & ShaderProgram.
			glewExperimental = GL_TRUE;

			GLint GlewInitResult = glewInit();
			if (GLEW_OK != GlewInitResult)
			{
				ServiceLoggerLocator::getService().logInfo("Glew has encoutered a problem and couldn't be initialized: " + std::string(reinterpret_cast<const char *>(glewGetErrorString(GlewInitResult))));
				return false;
			}
			else {
				ServiceLoggerLocator::getService().logInfo("Glew has been initialized.");
				ServiceLoggerLocator::getService().logInfo("Renderer used: " + std::string(reinterpret_cast<const char *>(glGetString(GL_RENDERER))));
				ServiceLoggerLocator::getService().logInfo(std::string(reinterpret_cast<const char *>(glGetString(GL_VERSION))) + " used in an GLFW context.");

				glEnable(GL_DEPTH_TEST);
				glDepthFunc(GL_LESS);
				return true;
			}
		}

		ShaderID createShader(const ShaderType & type)
		{
			auto handle = glCreateShader(type);
			if (handle == NULL_ID) {
				throw InitializationException::makeException("GL Shader");
			}
			return handle;
		}

		ProgramID createProgram()
		{
			auto handle = glCreateProgram();
			if (handle == NULL_ID) {
				throw InitializationException::makeException("GL Program");
			}
			return handle;
		}

		void compileShader(const ShaderID & shaderHandle, const std::string & source)
		{
			const GLchar * data = source.data();
			GLint length[1] = { static_cast<GLint>(source.size()) };

			glShaderSource(shaderHandle, 1, &data, length);
			glCompileShader(shaderHandle);
		}

		CompilationStatus checkShaderCompilationStatus(const ShaderID & shaderHandle)
		{
			CompilationStatus result;

			GLint temp = GL_FALSE;

			glGetShaderiv(shaderHandle, GL_SHADER_TYPE, &temp);
			result.type = static_cast<ShaderType>(temp);

			glGetShaderiv(shaderHandle, GL_DELETE_STATUS, &temp);
			result.deleteFlag = static_cast<bool>(temp);

			glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &temp);
			result.compiled = static_cast<bool>(temp);

			glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &temp);
			if (temp > 0) {
				std::vector<GLchar> error(temp);
				glGetShaderInfoLog(shaderHandle, temp, &temp, &error[0]);
				result.log = std::string(error.data());
			}
			else {
				result.log = "";
			}

			glGetShaderiv(shaderHandle, GL_SHADER_SOURCE_LENGTH, &temp);
			if (temp > 0) {
				std::vector<GLchar> source(temp);
				glGetShaderSource(shaderHandle, temp, &temp, &source[0]);
				result.source = std::string(source.data());
			}
			else {
				result.source = "";
			}

			return result;
		}

		void deleteShader(const ShaderID & shaderHandle)
		{
			if (shaderHandle == NULL_ID) {
				throw BadInputException::makeException("This shader reference is null and cannot be delete.");
			}
			glDeleteShader(shaderHandle);

			GLint deleteTag = GL_FALSE;
			glGetShaderiv(shaderHandle, GL_DELETE_STATUS, &deleteTag);
			if (!deleteTag) {
				//TODO: throw exception
			}
		}

		void attachShaderToProgram(const ShaderID & shaderHandle, const ProgramID & programHandle)
		{
			if (shaderHandle == GL::NULL_ID) {
				throw BadInputException::makeException("An invalid reference to a shader cannot be attached to a program.");
			}
			if (programHandle == GL::NULL_ID) {
				throw BadInputException::makeException("A shader cannot be attached to an invalid reference to a program.");
			}
			glAttachShader(programHandle, shaderHandle);

			GLint size = 256; // TODO: weird number????
			std::vector<GLuint> shaders;
			glGetAttachedShaders(shaderHandle, size, &size, shaders.data());
			if (shaders.empty() || std::find(shaders.begin(), shaders.end(), shaderHandle) == shaders.end()) {
				// throw RuntimeException
			}
		}

		void detachShaderFromProgram(const ShaderID & shaderHandle, const ProgramID & programHandle)
		{
			if (shaderHandle == GL::NULL_ID) {
				throw BadInputException::makeException("An invalid reference to a shader cannot be detached to a program.");
			}
			if (programHandle == GL::NULL_ID) {
				throw BadInputException::makeException("A shader cannot be detached to an invalid reference to a program.");
			}
			glDetachShader(programHandle, shaderHandle);

			GLint size = 256; // TODO: weird number????
			std::vector<GLuint> shaders;
			glGetAttachedShaders(shaderHandle, size, &size, shaders.data());
			if (shaders.empty() && std::find(shaders.begin(), shaders.end(), shaderHandle) != shaders.end()) {
				// throw RuntimeException
			}
		}

		VertexArrayID createObject()
		{
			VertexArrayID handle = NULL_ID;
			glGenVertexArrays(1, &handle);
			if (handle == NULL_ID) {
				throw InitializationException::makeException("GL object");
			}
			return handle;
		}

		void renderObject(const VertexArrayID & objectHandle, const RenderMode & renderMode, const unsigned int numberOfVertices)
		{
			if (objectHandle == NULL_ID) {
				throw BadInputException::makeException("An invalid reference to an object cannot be used for rendering.");
			}
			glBindVertexArray(objectHandle);
			glDrawArrays(renderMode, 0, (GLsizei)(numberOfVertices * 3));
			glBindVertexArray(NULL_ID);
		}
	}
}