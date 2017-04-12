#ifndef RENDERQUEUE_HPP
#define RENDERQUEUE_HPP

#include "Renderer\Renderable.hpp"
#include "Util\OpenGL\OpenGL.hpp"
#include "Renderer\Program.hpp"

namespace ece
{
	class RenderQueue
	{
	public:
		RenderQueue() = default;
		RenderQueue(const RenderQueue & copy) = default;
		RenderQueue(RenderQueue && move) = default;

		~RenderQueue() = default;

		RenderQueue & operator=(const RenderQueue & copy) = default;
		RenderQueue & operator=(RenderQueue && move) = default;

		void render(const GL::Matrix4x4 & VP, Renderable & object);

	private:
		Program program;
	};
}

#endif // RENDERQUEUE_HPP