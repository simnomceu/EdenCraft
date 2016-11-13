#include "Catch\catch.hpp"

/*#include "Core\System\EventManagerLocator.hpp"
#include "Core\System\EventManagerBuilder.hpp"
#include "Core\System\EventManager.hpp"
#include "Core\System\Emitter.hpp"
#include "Core\System\Listener.hpp"

#include <memory>

class A : public ece::Emitter
{
public:
	A() {
		this->addSignal(0);
		this->addSignal(1);
	}
};

class B : public ece::Listener
{
public:
	B(): counter(0) {
		this->addSlot(0, std::shared_ptr<ece::Slot>(new ece::Slot([this](const ece::Emitter & emitter, const ece::SignalID signal) { this->counter = 5; })));
		this->addSlot(1, std::shared_ptr<ece::Slot>(new ece::Slot([this](const ece::Emitter & emitter, const ece::SignalID signal) { this->counter = 10; })));
	}

	void connect(A & a) {
		ece::EventManagerLocator::getService().connect(*this, 0, a, 0);
		ece::EventManagerLocator::getService().connect(*this, 1, a, 1);
	}
	int counter;
};

SCENARIO("Event", "[Core][System]")
{
	GIVEN("A event manager initialized. Signals and slots are created and connected.")
	{
		ece::EventManagerLocator::provide(ece::EventManagerBuilder::makeEventManager<ece::EventManager>());

		A a; B b;
		b.connect(a);

		WHEN("Signal is emitted.")
		{
			a.emit(0);
			THEN("Slot is called.")
			{
				REQUIRE(b.counter == 5);
			}
		}

		WHEN("Second signal is emitted.")
		{
			a.emit(1);
			THEN("Second slot is called.")
			{
				REQUIRE(b.counter == 10);
			}
		}
	}
}*/