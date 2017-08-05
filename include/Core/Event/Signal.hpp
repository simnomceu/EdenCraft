#ifndef SIGNAL_HPP
#define SIGNAL_HPP

namespace ece
{
	class Signal final
	{
	public:
		using SignalID = unsigned int;
		using GlobalSignalID = unsigned int;

		static const Signal::GlobalSignalID INVALID_SIGNAL = -1;

		Signal() = delete;
		inline Signal(const GlobalSignalID id);
		Signal(const Signal & copy) = default;
		Signal(Signal && move) = default;
		~Signal() = default;

		Signal & operator=(const Signal & copy) = default;
		Signal & operator=(Signal && move) = default;

		inline const GlobalSignalID getId() const;
		
		inline const bool isDirty() const;
		inline void setDirty(const bool dirty);

	private:
		GlobalSignalID id;
		bool dirty;
	};
}

#include "Event\Signal.inl"

#endif // SIGNAL_HPP
