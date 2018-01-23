#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "utility/mathematics/vector3u.hpp"

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

		virtual std::vector<FloatVector3u> getPositions() const = 0;
		virtual std::vector<FloatVector3u> getColors() const = 0;
		virtual std::vector<FloatVector3u> getNormals() const = 0;
		virtual std::vector<int> getIndices() const = 0;

		inline bool isIndexed() const;
	};
}

#include "graphic/renderable/vertex.inl"

#endif // VERTEX_HPP