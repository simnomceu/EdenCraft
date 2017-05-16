#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "Mathematics\Vertex3D.hpp"

namespace ece
{
	class Vertex
	{
	public:
		Vertex() = default;
		Vertex(const Vertex & copy) = default;
		Vertex(Vertex && move) = default;

		~Vertex() = default;

		Vertex & operator=(const Vertex & copy) = default;
		Vertex & operator=(Vertex && move) = default;

		virtual std::vector<FloatVertex3D> getPositions() const = 0;
		virtual std::vector<FloatVertex3D> getColors() const = 0;
		virtual std::vector<FloatVertex3D> getNormals() const = 0;
		virtual std::vector<int> getIndices() const = 0;

		inline bool isIndexed() const;
	};
}

#include "Renderable\Vertex.inl"

#endif // VERTEX_HPP