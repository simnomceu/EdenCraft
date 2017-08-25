#include "debug/exception.hpp"

namespace ece
{
	template <class Base>
	template <class Derived>
	std::shared_ptr<Base> ServiceFactory<Base>::build()
	{
		if (!std::is_base_of<Base, Derived>()) {
			throw InitializationException("This class cannot be instantiate as the service wished. Check again.");
		}
		return std::shared_ptr<Base>(new Derived());
	}
}
