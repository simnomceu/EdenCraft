#ifndef UPDATE_PER_SECOND_HPP
#define UPDATE_PER_SECOND_HPP

#include "time/chrono.hpp"

namespace ece
{
	class UpdatePerSecond
	{
	public:
		inline UpdatePerSecond(const int UPS);

		const bool isReadyToUpdate();

		inline const double getUPS() const;

	private:
		Chrono chrono;

		float rate;
		long int nbFrames;
		double average;
	};

}

#include "time/update_per_second.inl"

#endif // UPDATE_PER_SECOND_HPP