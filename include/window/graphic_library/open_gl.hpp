#ifndef OPEN_GL_HPP
#define OPEN_GL_HPP

#include "graphic_library/base_gl.hpp"
#include "graphic_library/glfw.hpp"
#include "graphic_library/glew.hpp"

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

#endif // OPEN_GL_HPP