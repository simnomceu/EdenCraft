#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <iostream>

#include "Util\Type.hpp"
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

		inline const std::vector<FastVertex3D> & getVertices() const;
		inline const std::vector<FastVertex3D> & getColors() const;
		inline const unsigned int size() const;
		const Box3D & getAABB() const;

	private:
		std::vector<FastVertex3D> vertices;
		std::vector<FastVertex3D> colors;
	};
}

#include "Rendering\Model\Mesh.inl"

#endif // MESH_HPP