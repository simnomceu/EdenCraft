#include "Core\Util\Chrono.hpp"

namespace ece
{
	Chrono::Chrono(): begin()
	{
	}

	void Chrono::start()
	{
		this->begin = std::chrono::system_clock::now();
	}

	const int Chrono::reset()
	{
		auto end = std::chrono::system_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		this->begin = end;
		return (int)elapsedTime;
	}

	const int Chrono::getElapsedTime() const
	{
		auto end = std::chrono::system_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		return (int)elapsedTime;
	}
}
