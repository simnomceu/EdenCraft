#ifndef CHRONO_HPP
#define CHRONO_HPP

#include <chrono>

namespace ece
{
	class Chrono
	{
	public:
		Chrono();
		
		void start();
		const int reset();

		const int getElapsedTime() const;

	private:
		std::chrono::time_point<std::chrono::system_clock> begin;
	};
}

#endif CHRONO_HPP
