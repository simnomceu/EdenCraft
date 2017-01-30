#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include "GL\glew.h"

namespace ece
{
	class Mesh
	{
	public:
		Mesh(const GLenum mode);
		~Mesh() = default;

		void addVertices(const std::vector<float> & vertices);
		const std::vector<float>& getVertices();

		const int getNumberOfVertices() const;

		void computeCenter();

	private:		
		std::vector<float> vertices;

		float center[3];
	};
}

#endif // MESH_HPP