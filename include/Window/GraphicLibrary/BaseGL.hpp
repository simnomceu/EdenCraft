#ifndef BASEGL_HPP
#define BASEGL_HPP

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

#include "GraphicLibrary\BaseGL.inl"

#endif // BASEGL_HPP