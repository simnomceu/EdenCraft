#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "Core\System\Event.inl"

namespace ece
{
	class Emitter
	{
	public:
		virtual ~Emitter() = 0;

		void addSignal(const ece::SignalID & signal);
		void emit(const ece::SignalID & signal);
	};
}

#endif // EMITTER_HPP
