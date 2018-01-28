#include "renderer/common/renderer.hpp"

#include "renderer/opengl/vao.hpp"

namespace ece
{
	Shader Renderer::getProgram() const
	{
		int handle = 0;
		OpenGL::getInteger(Parameter::CURRENT_PROGRAM, handle);
		return Shader(static_cast<ProgramHandle>(handle));
	}

	void Renderer::drawPrimitives(const PrimitiveMode mode, const VAO & vao)
	{
		OpenGL::enable(Capability::CULL_FACE);
		OpenGL::cullFace(CullFaceMode::BACK);
		OpenGL::frontFace(FrontFaceMode::CW);

		vao.bind();
		OpenGL::drawArrays(mode, 0, 3);
	}
}