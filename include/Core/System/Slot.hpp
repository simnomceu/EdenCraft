#ifndef SLOT_HPP
#define SLOT_HPP

#include "Core\System\Event.inl"

#include <functional>

namespace ece
{
	class Slot
	{
	public:
		Slot(const ece::SlotID&  id, const std::function<void()> & handle);
		~Slot();

		bool operator==(const Slot & rightOperand);

		void trigger();

		const ece::SlotID & getId() const;

	private:
		ece::SlotID id;
		std::function<void()> handle;
	};
}

#endif // SLOT_HPP
