#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <queue>

#include "Core\Graphic\Rendering\Mesh.hpp"
#include "Core\Graphic\Rendering\ProgramGLSL.hpp"
#include "Core\Graphic\Rendering\Texture.hpp"
#include "Core\Graphic\Rendering\Transformation.hpp"
#include "glm\glm.hpp"

namespace ece
{
	using Point3D = glm::vec3;

	class Object
	{
	public:
		enum MeshAttribute
		{
			POSITION = 0,
			COLOR = 1
		};

		Object() = delete;
		Object(const Mesh & mesh, const ProgramGLSL program);

		void prepare();
		Point3D getCenter() const;

		void render(const glm::mat4 view, const glm::mat4 projection);

	private:
		Mesh mesh;
		ProgramGLSL program;
		Texture texture;
		std::queue<Transformation*> transformations;

		GLenum modeRender;
		GLuint vao;
		std::vector<GLuint> vbos;
	};
}

#endif // OBJECT_HPP