#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <iostream>

#include "Mathematics\Vertex3D.hpp"
#include "Geom\Box3D.hpp"

namespace ece
{
	class Mesh
	{
	public:
		Mesh() = default;
		Mesh(const Mesh & copy) = default;
		Mesh(Mesh && move) = default;

		~Mesh() {}

		Mesh & operator=(const Mesh & copy) = default;
		Mesh & operator=(Mesh && move) = default;

		bool loadFromFile(const std::string & filename);

		inline const std::vector<FloatVertex3D> & getVertices() const;
		inline const std::vector<FloatVertex3D> & getColors() const;
		inline const unsigned int size() const;
		Box3D getAABB() const;

	private:
		std::vector<FloatVertex3D> vertices;
		std::vector<FloatVertex3D> colors;
	};
}

#include "Model\Mesh.inl"

#endif // MESH_HPP