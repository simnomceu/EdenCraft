#include "utility/time/update_per_second.hpp"

namespace ece
{
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

	void UpdatePerSecond::setUPS(const int limit)
	{
		this->rate = 1000.0f / limit;
		this->nbFrames = 0;
		this->average = 0.0;
		this->chrono.start();
	}
}