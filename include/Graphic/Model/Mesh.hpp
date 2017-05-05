#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <iostream>

#include "Mathematics\Vertex3D.hpp"
#include "Geom\Box3D.hpp"
#include "Renderable\Vertex.hpp"

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

		inline virtual std::vector<FloatVertex3D> getPositions() const override;
		inline virtual std::vector<FloatVertex3D> getColors() const override;
		inline virtual std::vector<FloatVertex3D> getNormals() const override;
		inline virtual std::vector<int> getIndices() const override;

	private:
		std::vector<FloatVertex3D> vertices;
		std::vector<FloatVertex3D> colors;
	};
}

#include "Model\Mesh.inl"

#endif // MESH_HPP