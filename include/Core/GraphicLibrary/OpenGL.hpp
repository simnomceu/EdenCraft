#ifndef OPENGL_HPP
#define OPENGL_HPP

#include "GraphicLibrary\BaseGL.hpp"
#include "GraphicLibrary\GLFW.hpp"
#include "GraphicLibrary\GLEW.hpp"

namespace ece
{
	class OpenGL : public BaseGL
	{
	public:
		OpenGL() = default;
		~OpenGL() = default;

		virtual void preInit() override;
		virtual void postInit() override;
		virtual bool isPreInitialized() override;
		virtual bool isPostInitialized() override;

	private:
		GLFW glfwHandle;
		GLEW glewHandle;
	};
}

#endif // OPENGL_HPP