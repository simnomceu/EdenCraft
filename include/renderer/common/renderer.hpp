#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "renderer/opengl/opengl.hpp"
#include "renderer/common/program.hpp"

namespace ece
{
	class VAO;

	class Renderer
	{
	public:
		Renderer() = default;
		Renderer(const Renderer & copy) = default;
		Renderer(Renderer && move) = default;

		~Renderer() = default;

		Renderer & operator=(const Renderer & copy) = default;
		Renderer & operator=(Renderer && move) = default;

		Program getProgram() const;
		inline void setProgram(const Program & program);

		void drawPrimitives(const PrimitiveMode mode, const VAO & vao);

	private:
	};
}

#include "renderer/common/renderer.inl"

#endif // RENDERER_HPP
