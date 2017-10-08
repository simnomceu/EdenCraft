#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "event/signal.hpp"
#include "event/slot.hpp"

namespace ece
{
	class Connection final
	{
	public:
		Connection() = delete;
		inline Connection(const Slot::GlobalSlotID slot, const Signal::GlobalSignalID signal);
		Connection(const Connection & copy) = default;
		Connection(Connection && move) = default;
		~Connection() = default;

		Connection & operator=(const Connection & copy) = default;
		Connection & operator=(Connection && move) = default;

		inline bool operator==(const Connection & rightOperand);

		inline const Slot::GlobalSlotID getSlot() const;
		inline const Slot::GlobalSlotID getSignal() const;

		inline void setDirty(const bool dirty);
		inline const bool isDirty() const;

	private:
		Slot::GlobalSlotID slot;
		Signal::GlobalSignalID signal;
		bool dirty;
	};
}

#include "event/connection.inl"

#endif // CONNECTION_HPP
