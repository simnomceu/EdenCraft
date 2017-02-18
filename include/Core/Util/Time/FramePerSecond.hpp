#ifndef FRAMEPERSECOND_HPP
#define FRAMEPERSECOND_HPP

#include "Util\Time\UpdatePerSecond.hpp"

namespace ece
{
	class FramePerSecond : private UpdatePerSecond
	{
	public:
		enum FPSrate : int
		{
			FRAME_30 = 30,
			FRAME_60 = 60
		};

		inline FramePerSecond(FPSrate rate = FRAME_60);

		using UpdatePerSecond::isReadyToUpdate;

		inline const double getFPS() const;
	};
}

#include "Util\Time\FramePerSecond.inl"

#endif // FRAMEPERSECOND_HPP