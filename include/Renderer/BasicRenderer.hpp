#ifndef BASICRENDERER_HPP
#define BASICRENDERER_HPP

#include "Renderer.hpp"

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

#endif // BASICRENDERER_HPP