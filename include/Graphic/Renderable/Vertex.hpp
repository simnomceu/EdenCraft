#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

namespace ece
{
	struct Position
	{
		int data[3];
	};

	typedef Position Color;
	typedef Position Normal;

	class Vertex
	{
	public:
		Vertex() = default;
		Vertex(const Vertex & copy) = default;
		Vertex(Vertex && move) = default;

		~Vertex() = default;

		Vertex & operator=(const Vertex & copy) = default;
		Vertex & operator=(Vertex && move) = default;

		std::vector<Position> getPositions() const;
		std::vector<Color> getColors() const;
		std::vector<Normal> getNormals() const;
		std::vector<int> getIndices() const;

		bool isIndexed() const;
	};
}

#endif // VERTEX_HPP