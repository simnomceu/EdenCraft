#include "debug/exception.hpp"

namespace ece
{
	template <class Base, class Null>
	std::shared_ptr<Base> ServiceLocator<Base, Null>::service = std::shared_ptr<Null>();

	template <class Base, class Null>
	inline void ServiceLocator<Base, Null>::provide(const std::shared_ptr<Base> & service)
	{
		ServiceLocator<Base, Null>::service = service;
	}

	template <class Base, class Null>
	Base & ServiceLocator<Base, Null>::getService()
	{
		if (ServiceLocator<Base, Null>::service.get() == nullptr) {
			throw MemoryAccessException("A service.");
		}
		return *ServiceLocator<Base, Null>::service;
	}

	/*template <class Base, class Null>
	std::weak_ptr<Base> ServiceLocator<Base, Null>::getServicePtr()
	{
	if (ServiceLocator<Base, Null>::service.get() == nullptr) {
	throw std::exception("Invalid pointer to a service.");
	}
	return ServiceLocator<Base, Null>::service;
	}*/

	template <class Base, class Null>
	inline void ServiceLocator<Base, Null>::stop()
	{
		ServiceLocator<Base, Null>::service = std::shared_ptr<Null>();
	}
}
