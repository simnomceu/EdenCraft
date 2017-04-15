namespace ece
{
	inline FramePerSecond::FramePerSecond(FPSrate rate) : UpdatePerSecond(rate)
	{
	}

	inline const double FramePerSecond::getFPS() const { return this->getUPS(); }
}