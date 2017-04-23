#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <vector>

#include "Renderable\Vertex.hpp"
#include "Renderable\BaseUniform.hpp"
#include "Renderable\ShaderSource.hpp"

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
		Renderable & operator=(Renderable && move) = default;

		virtual std::vector<Vertex> getVertices() const = 0;
		virtual std::vector<BaseUniform *> getUniforms() const = 0;
		virtual std::vector<ShaderSource *> getShaderSources() const = 0;
	};
}

#endif // RENDERABLE_HPP