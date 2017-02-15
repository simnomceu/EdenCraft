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
		Mesh(const Mesh & copy) = default;
		~Mesh() = default;

		void addVertices(const std::vector<float> & vertices, const std::vector<int> & index);
		void addColors(const std::vector<float> & colors);
		const std::vector<float>& getVertices();
		const std::vector<int> & getVerticesIndex();
		const std::vector<float>& getColors();

		const int getNumberOfVertices() const;
		const int getNumberOfIndex() const;

		void reset();

		GLenum getModeRender() const;

	protected:
		void computeCenter();

	private:
		std::vector<float> vertices;
		std::vector<int> index;

		std::vector<float> colors;

		float center[3];

		GLenum modeRender;
	};
}

#endif // MESH_HPP