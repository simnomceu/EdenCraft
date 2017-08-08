#ifndef NONE_GL_HPP
#define NONE_GL_HPP

#include "graphic_library\base_gl.hpp"

namespace ece
{
	class NoneGL : public BaseGL
	{
	public:
		NoneGL() = default;

		~NoneGL() = default;

		inline virtual void preInit() override;
		inline virtual void postInit() override;
		inline virtual bool isPreInitialized() override;
		inline virtual bool isPostInitialized() override;
	};
}

#include "graphic_library\none_gl.inl"

#endif // NONE_GL_HPP