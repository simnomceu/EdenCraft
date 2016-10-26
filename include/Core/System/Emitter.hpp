#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "Core\System\Event.inl"

#include <vector>

namespace ece
{
	class Emitter
	{
	public:
		Emitter();
		virtual ~Emitter() = 0;

		void addSignal(const ece::SignalID & signal);
		void removeSignal(const ece::SignalID & signal);

		void emit(const ece::SignalID & signal);

	private:
		std::vector<ece::SignalID> signals;
	};
}

#endif // EMITTER_HPP
