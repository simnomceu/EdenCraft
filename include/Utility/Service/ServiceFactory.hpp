#ifndef SERVICEFACTORY_HPP
#define SERVICEFACTORY_HPP

#include <memory>

namespace ece
{
	template <class Base>
	class ServiceFactory
	{
	public:
		template <class Derived>
		static std::shared_ptr<Base> build();
	};
}

#include "Service\ServiceFactory.inl"

#endif
