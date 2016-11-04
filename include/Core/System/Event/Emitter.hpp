#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "Core\System\Event\Event.inl"

#include <map>

namespace ece
{
	class Emitter
	{
	public:
		Emitter();
		virtual ~Emitter() = 0;

		void addSignal(const ece::SignalID signal);
		void removeSignal(const ece::SignalID signal);

		void emit(const ece::SignalID signal);

		const ece::GlobalSignalID getSignal(const ece::SignalID signal) const;

	private:
		std::map<ece::SignalID, ece::GlobalSignalID> signals;
	};
}

#endif // EMITTER_HPP
