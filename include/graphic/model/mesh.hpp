#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <iostream>

#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/box3d.hpp"
#include "graphic/renderable/vertex.hpp"

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

		inline virtual std::vector<FloatVector3u> getPositions() const override;
		inline virtual std::vector<FloatVector3u> getColors() const override;
		inline virtual std::vector<FloatVector3u> getNormals() const override;
		inline virtual std::vector<int> getIndices() const override;

	private:
		std::vector<FloatVector3u> _vertices;
		std::vector<FloatVector3u> _colors;
	};
}

#include "graphic/model/mesh.inl"

#endif // MESH_HPP