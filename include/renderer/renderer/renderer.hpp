#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

namespace ece
{
	class Camera;
	class Projection;
	class Renderable;

	class Renderer
	{
	public:
		inline virtual ~Renderer() = 0;

		virtual void render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects) = 0;
	};
}

#include "renderer/renderer/renderer.inl"

#endif // RENDERER_HPP
