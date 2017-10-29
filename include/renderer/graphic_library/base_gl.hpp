#ifndef BASE_GL_HPP
#define BASE_GL_HPP

namespace ece
{
	class BaseGL
	{
	public:
		inline BaseGL();
		inline virtual ~BaseGL() = 0;

		virtual void preInit() = 0;
		virtual void postInit() = 0;
		virtual bool isPreInitialized() = 0;
		virtual bool isPostInitialized() = 0;
	};
}

#include "graphic_library/base_gl.inl"

#endif // BASE_GL_HPP