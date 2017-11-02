#ifndef BASIC_RENDERER_HPP
#define BASIC_RENDERER_HPP

#include "renderer.hpp"

#include <vector>

namespace ece
{
	class Camera;
	class Projection;
	class Renderable;

	class BasicRenderer: public Renderer
	{
	public:
		BasicRenderer() = default;
		BasicRenderer(const BasicRenderer & copy) = default;
		BasicRenderer(BasicRenderer && move) = default;

		~BasicRenderer() = default;

		BasicRenderer & operator=(const BasicRenderer & copy) = default;
		BasicRenderer & operator=(BasicRenderer && move) = default;

		virtual void render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects) override;
	};
}

#endif // BASIC_RENDERER_HPP