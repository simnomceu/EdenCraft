#include "Util\Time\UpdatePerSecond.hpp"

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
}