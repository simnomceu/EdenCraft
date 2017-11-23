#ifndef FRAME_PER_SECOND_HPP
#define FRAME_PER_SECOND_HPP

#include "utility/time/update_per_second.hpp"

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

#include "utility/time/frame_per_second.inl"

#endif // FRAME_PER_SECOND_HPP