#ifndef SLOT_HPP
#define SLOT_HPP

#include "Core\System\Event.inl"

#include <functional>

namespace ece
{
	class Slot
	{
	public:
		Slot() = default;
		Slot(const std::function<void()> & handle);
		~Slot();

		void trigger();

		const ece::GlobalSlotID & getId() const;

	private:
		ece::GlobalSlotID id;
		std::function<void()> handle;
	};


}

#endif // SLOT_HPP
