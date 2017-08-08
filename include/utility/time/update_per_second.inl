namespace ece
{

	inline UpdatePerSecond::UpdatePerSecond(const int UPS) : chrono(), rate(1000.0f / rate), nbFrames(0), average(0.0)
	{
		this->chrono.start();
	}

	inline const double UpdatePerSecond::getUPS() const { return this->average; }
}