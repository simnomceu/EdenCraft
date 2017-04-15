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
		static inline void provide(const std::shared_ptr<Base> & service);
		static Base & getService();
		//static std::weak_ptr<Base> getServicePtr();
		static inline void stop();

	protected:
		static std::shared_ptr<Base> service;
	};
}

#include "Module\ServiceLocator.inl"

#endif // SERVICELOCATOR_HPP
