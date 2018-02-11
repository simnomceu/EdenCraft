#include "renderer/common/renderer.hpp"

#include "renderer/opengl/vao.hpp"

namespace ece
{
	Shader Renderer::getProgram() const
	{
		auto handle = OpenGL::getInteger(Parameter::CURRENT_PROGRAM);
		return Shader(static_cast<Handle>(handle[0]));
	}

	void Renderer::drawPrimitives(const PrimitiveMode mode, const VAO & vao)
	{
		OpenGL::enable(Capability::CULL_FACE);
		OpenGL::cullFace(CullFaceMode::BACK);
		OpenGL::frontFace(FrontFaceMode::CW);

		vao.bind();
		vao.bindIndexBuffer();
		OpenGL::drawElements(mode, vao.getNbVertices(), DataType::UNSIGNED_INT, 0);
	}
}