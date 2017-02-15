#ifndef SERVICELOCATOR_HPP
#define SERVICELOCATOR_HPP

#include <memory>

namespace ece
{
	template <class Base, class Null>
	class ServiceLocator
	{
		static_assert(std::is_base_of<Base, Null>::value, "ServiceLocator cannot be instantiate with this template parameters.");

	public:
		static void provide(const std::shared_ptr<Base> & service);
		static Base & getService();
		static Base * getServicePtr();
		static void stop();

	protected:
		static std::shared_ptr<Base> service;
	};

	template <class Base, class Null>
	std::shared_ptr<Base> ServiceLocator<Base, Null>::service = std::shared_ptr<Null>();

	template <class Base, class Null>
	void ServiceLocator<Base, Null>::provide(const std::shared_ptr<Base> & service)
	{
		ServiceLocator<Base, Null>::service = service;
	}

	template <class Base, class Null>
	Base & ServiceLocator<Base, Null>::getService()
	{
		if (ServiceLocator<Base, Null>::service.get() == nullptr) {
			throw std::exception("Invalid pointer to a service.");
		}
		return *ServiceLocator<Base, Null>::service;
	}

	template <class Base, class Null>
	Base * ServiceLocator<Base, Null>::getServicePtr()
	{
		return ServiceLocator<Base, Null>::service.get();
	}

	template <class Base, class Null>
	void ServiceLocator<Base, Null>::stop()
	{
		ServiceLocator<Base, Null>::service = std::shared_ptr<Null>();
	}
}

#endif // SERVICELOCATOR_HPP
