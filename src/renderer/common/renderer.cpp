#include "renderer/common/renderer.hpp"

#include "renderer/opengl/vao.hpp"

namespace ece
{
	Shader Renderer::getProgram() const
	{
		auto handle = OpenGL::getInteger(Parameter::CURRENT_PROGRAM);
		return Shader(static_cast<Handle>(handle[0]));
	}

	void Renderer::enableFaceCulling(const CullFaceMode cullFaceMode, const FrontFaceMode frontFaceMode)
	{
		OpenGL::enable(Capability::CULL_FACE);
		OpenGL::cullFace(cullFaceMode);
		OpenGL::frontFace(frontFaceMode);
	}

	void Renderer::disableFaceCulling()
	{
		OpenGL::disable(Capability::CULL_FACE);
	}

	void Renderer::setPolygonMode(const PolygonMode mode)
	{
		OpenGL::polygonMode(mode);
	}

	void Renderer::drawPrimitives(const PrimitiveMode mode, const VAO & vao)
	{
		this->enableFaceCulling(CullFaceMode::BACK, FrontFaceMode::CW);

		vao.bind();
		vao.bindIndexBuffer();
		OpenGL::drawElements(mode, vao.getNbVertices(), DataType::UNSIGNED_INT, 0);
	}
}