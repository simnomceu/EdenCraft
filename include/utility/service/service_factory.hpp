#ifndef SERVICE_FACTORY_HPP
#define SERVICE_FACTORY_HPP

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

#include "service/service_factory.inl"

#endif // SERVIC_FACTORY_HPP
