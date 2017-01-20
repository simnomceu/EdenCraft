#include "Catch\catch.hpp"

#include "Core\Core.hpp"
#include "Core\System\EventService.hpp"

#include "Core\System\Event\Emitter.hpp"
#include "Core\System\Event\Listener.hpp"
#include "Core\System\Event\SlotBuilder.hpp"

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
		this->addSlot(0, ece::SlotBuilder::makeSlot([this](const ece::Emitter & emitter, const ece::SignalID signal) { this->counter = 5; }));
		this->addSlot(1, ece::SlotBuilder::makeSlot([this](const ece::Emitter & emitter, const ece::SignalID signal) { this->counter = 10; }));
	}

	void connect(A & a) {
		ece::EventServiceLocator::getService().connect(*this, 0, a, 0);
		ece::EventServiceLocator::getService().connect(*this, 1, a, 1);
	}
	int counter;
};

SCENARIO("Event", "[Core][System]")
{
	GIVEN("A event manager initialized. Signals and slots are created and connected.")
	{
		ece::Core::init(ece::LOG, ece::SYSTEM);
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

	GIVEN("The event manager is not initialized.")
	{
		WHEN("Signal is created.")
		{
			A a;
			THEN("Nothing happens.")
			{
				//REQUIRE();
			}
		}
	}
}