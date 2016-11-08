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

	template <class Base>
	template <class Derived>
	std::shared_ptr<Base> ServiceFactory<Base>::build()
	{
		if(!std::is_base_of<Base, Derived>()) {
			throw std::exception("This class cannot be instantiate as the service wished. Chec again.");
		}
		return std::shared_ptr<Base>(new Derived());
	}
}

#endif
