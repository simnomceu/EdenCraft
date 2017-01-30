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
		void addColors(const std::vector<float> & colors);
		const std::vector<float>& getVertices();
		const std::vector<float>& getColors();

		const int getNumberOfVertices() const;

		void reset();

	protected:
		void computeCenter();

	private:
		std::vector<float> vertices;
		std::vector<float> colors;

		float center[3];
	};
}

#endif // MESH_HPP