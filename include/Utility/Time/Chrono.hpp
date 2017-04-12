#ifndef CHRONO_HPP
#define CHRONO_HPP

#include <chrono>

namespace ece
{
	class Chrono
	{
	public:
		inline Chrono();
		
		inline void start();
		const int reset();

		const int getElapsedTime() const;

	private:
		std::chrono::time_point<std::chrono::system_clock> begin;
	};
}

#include "Time\Chrono.inl"

#endif CHRONO_HPP
