#ifndef NONEGL_HPP
#define NONEGL_HPP

#include "GraphicLibrary\BaseGL.hpp"

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

#include "GraphicLibrary\NoneGL.inl"

#endif // NONEGL_HPP