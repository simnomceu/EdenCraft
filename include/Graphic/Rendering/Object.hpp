#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <queue>

#include "Rendering\Mesh.hpp"
#include "Rendering\ProgramGL.hpp"
#include "Rendering\Texture.hpp"
#include "Rendering\Transformation.hpp"
#include "Util\Type.hpp"

namespace ece
{
	class Object
	{
	public:
		enum MeshAttribute
		{
			POSITION = 0,
			COLOR = 1,
			INDEX = 2
		};

		Object() = delete;
		Object(const Mesh & mesh);

		inline ~Object();

		void prepare();
		Point3D getCenter() const;

		void render(const glm::mat4 & view, const glm::mat4 & projection);

	private:
		Mesh mesh;
		Program* program;
		Texture texture;
		std::queue<Transformation*> transformations;

		GLuint vao;
		std::vector<GLuint> vbos;
		glm::mat4 model;
	};
}

#include "Rendering\Object.inl"

#endif // OBJECT_HPP