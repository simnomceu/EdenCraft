#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include "GL\glew.h"

namespace ece
{
	class Mesh
	{
	public:
		inline Mesh(const GLenum mode);
		Mesh(const Mesh & copy) = default;
		~Mesh() = default;

		void addVertices(const std::vector<float> & vertices, const std::vector<int> & index);
		void addColors(const std::vector<float> & colors);
		inline const std::vector<float>& getVertices();
		inline const std::vector<int> & getVerticesIndex();
		inline const std::vector<float>& getColors();

		inline const int getNumberOfVertices() const;
		inline const int getNumberOfIndex() const;

		void reset();

		inline GLenum getModeRender() const;

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

#include "Rendering\Mesh.inl"

#endif // MESH_HPP