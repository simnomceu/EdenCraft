#include "Core\Util\UpdatePerSecond.hpp"

namespace ece
{
	UpdatePerSecond::UpdatePerSecond(const int UPS): chrono(), rate(1000.0f / rate), nbFrames(0), average(0.0)
	{
		this->chrono.start();
	}

	const bool UpdatePerSecond::isReadyToUpdate()
	{
		float elapsedTime = (float)this->chrono.getElapsedTime();
		bool isReady = elapsedTime >= this->rate;
		if (isReady) {
			this->chrono.reset();
			this->average = ((this->average*this->nbFrames) + elapsedTime) / (this->nbFrames + 1);
			this->nbFrames++;
		}
		return isReady;
	}

	const double UpdatePerSecond::getUPS() const
	{
		return this->average;
	}

	FramePerSecond::FramePerSecond(FPSrate rate): UpdatePerSecond(rate)
	{
	}
	const double FramePerSecond::getFPS() const
	{
		return this->getUPS();
	}
}