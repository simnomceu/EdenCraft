#ifndef LIFECYCLE_HPP
#define LIFECYCLE_HPP

#include "core/event/emitter.hpp"
#include "core/event/signal.hpp"

namespace ece
{
	class Lifecycle: public Emitter
	{
	public:
		const Signal::SignalID PRE_INIT = 0;
		const Signal::SignalID POST_INIT = 1;
		const Signal::SignalID PRE_PROCESS = 2;
		const Signal::SignalID PRE_UPDATE = 3;
		const Signal::SignalID POST_UPDATE = 4;
		const Signal::SignalID POST_RENDER = 5;
		const Signal::SignalID PRE_TERMINATE = 6;
		const Signal::SignalID POST_TERMINATE = 7;

		Lifecycle();
		Lifecycle(const Lifecycle & copy) = default;
		Lifecycle(Lifecycle && move) = default;

		~Lifecycle() = default;

		Lifecycle & operator=(const Lifecycle & copy) = default;
		Lifecycle & operator=(Lifecycle && move) = default;

		inline void preInit();
		inline void postInit();
		inline void preProcess();
		inline void preUpdate();
		inline void postUpdate();
		inline void postRender();
		inline void preTerminate();
		inline void postTerminate();

		inline void onPreInit(const Listener & listener, const unsigned int slot);
		inline void onPostInit(const Listener & listener, const unsigned int slot);
		inline void onPreProcess(const Listener & listener, const unsigned int slot);
		inline void onPreUpdate(const Listener & listener, const unsigned int slot);
		inline void onPostUpdate(const Listener & listener, const unsigned int slot);
		inline void onPostRender(const Listener & listener, const unsigned int slot);
		inline void onPreTerminate(const Listener & listener, const unsigned int slot);
		inline void onPostTerminate(const Listener & listener, const unsigned int slot);
	};
}

#include "core/application/lifecycle.inl"

#endif // LIFECYCLE_HPP
