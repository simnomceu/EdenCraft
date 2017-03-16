#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "Util\OpenGL\OpenGL.hpp"
#include "Renderer\Shader.hpp"

#include <vector>

namespace ece
{
	class Renderable
	{
	public:
		Renderable() = default;
		Renderable(const Renderable & copy) = default;
		Renderable(Renderable && move) = default;

		~Renderable() = default;

		Renderable & operator=(const Renderable & copy) = default;
		Renderable & operator=(Renderable & move) = default;

		virtual std::vector<std::string> getLocations() const = 0;
		virtual std::vector<Shader &> getShaders() const = 0;
		virtual const Matrix4x4 & getModel() const = 0;

		virtual void draw() = 0;
	};
}

#endif // RENDERABLE_HPP