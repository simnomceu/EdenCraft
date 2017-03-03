#ifndef TYPE_HPP 
#define TYPE_HPP 

#include "glm\glm.hpp"

namespace ece
{
	using uint8 = unsigned __int8;
	using uint16 = unsigned __int16;
	using uint32 = unsigned __int32;
	using uint64 = unsigned __int64;

	using int8 = __int8;
	using int16 = __int16;
	using int32 = __int32;
	using int64 = __int64;

	using Matrix4x4 = glm::mat4;
	using Point3D = glm::vec3;
	using Vertex3D = glm::vec3;
}

#endif // TYPE_HPP