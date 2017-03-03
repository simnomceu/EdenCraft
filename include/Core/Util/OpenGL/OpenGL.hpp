#ifndef OPENGL_HPP
#define OPENGL_HPP

#include "Util\Type.hpp"

namespace ece
{
	class OpenGL
	{
	public:
		static inline Matrix4x4 lookAt(Vertex3D position, Point3D target, Vertex3D upAxis);
	};
}

#include "Util\OpenGL\OpenGL.inl"

#endif // OPENGL_HPP