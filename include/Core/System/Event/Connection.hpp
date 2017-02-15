#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "Core\System\Event\Signal.hpp"
#include "Core\System\Event\Slot.hpp"

namespace ece
{
	class Connection final
	{
	public:
		Connection() = delete;
		Connection(const Slot::GlobalSlotID slot, const Signal::GlobalSignalID signal);
		Connection(const Connection & copy) = default;
		Connection(Connection && move) = default;
		~Connection() = default;

		Connection & operator=(const Connection & copy) = default;
		Connection & operator=(Connection && move) = default;

		bool operator==(const Connection & rightOperand);

		const Slot::GlobalSlotID getSlot() const;
		const Slot::GlobalSlotID getSignal() const;

		void setDirty(const bool dirty);
		const bool isDirty() const;

	private:
		Slot::GlobalSlotID slot;
		Signal::GlobalSignalID signal;
		bool dirty;
	};
}

#endif // CONNECTION_HPP
