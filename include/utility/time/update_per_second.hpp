#ifndef UPDATE_PER_SECOND_HPP
#define UPDATE_PER_SECOND_HPP

#include "utility/time/chrono.hpp"

namespace ece
{
	class UpdatePerSecond
	{
	public:
		inline UpdatePerSecond(const int UPS);

		const bool isReadyToUpdate();

		inline int getLimit() const;
		inline const double getUPS() const;

		void setUPS(const int limit);

	private:
		Chrono chrono;

		float rate;
		long int nbFrames;
		double average;
	};

}

#include "utility/time/update_per_second.inl"

#endif // UPDATE_PER_SECOND_HPP