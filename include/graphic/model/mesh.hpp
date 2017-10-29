#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <iostream>

#include "mathematics/vertex3u.hpp"
#include "mathematics/box3d.hpp"
#include "renderable/vertex.hpp"

namespace ece
{
	class Mesh: public Vertex
	{
	public:
		Mesh() = default;
		Mesh(const Mesh & copy) = default;
		Mesh(Mesh && move) = default;

		~Mesh() {}

		Mesh & operator=(const Mesh & copy) = default;
		Mesh & operator=(Mesh && move) = default;

		bool loadFromFile(const std::string & filename);

		inline const unsigned int size() const;
		Box3D getAABB() const;

		inline virtual std::vector<FloatVertex3u> getPositions() const override;
		inline virtual std::vector<FloatVertex3u> getColors() const override;
		inline virtual std::vector<FloatVertex3u> getNormals() const override;
		inline virtual std::vector<int> getIndices() const override;

	private:
		std::vector<FloatVertex3u> vertices;
		std::vector<FloatVertex3u> colors;
	};
}

#include "model/mesh.inl"

#endif // MESH_HPP