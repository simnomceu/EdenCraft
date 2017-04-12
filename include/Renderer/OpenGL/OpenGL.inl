#include "glm\gtc\matrix_transform.hpp"

namespace ece
{
	namespace GL
	{
		inline Matrix4x4 lookAt(Vertex3D position, Point3D target, Vertex3D upAxis) { return glm::lookAt(position, target, upAxis); }
	}
}