#ifndef UPDATEPERSECOND_HPP
#define UPDATEPERSECOND_HPP

#include "Core\Util\Chrono.hpp"

namespace ece
{
	class UpdatePerSecond
	{
	public:
		UpdatePerSecond(const int UPS);

		const bool isReadyToUpdate();

		const double getUPS() const;

	private:
		Chrono chrono;

		float rate;
		long int nbFrames;
		double average;
	};

	class FramePerSecond : private UpdatePerSecond
	{
	public:
		enum FPSrate : int
		{
			FRAME_30 = 30,
			FRAME_60 = 60
		};

		FramePerSecond(FPSrate rate = FRAME_60);

		using UpdatePerSecond::isReadyToUpdate;

		const double getFPS() const;
	};
}

#endif // UPDATEPERSECOND_HPP