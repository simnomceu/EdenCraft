namespace ece
{

	inline UpdatePerSecond::UpdatePerSecond(const int UPS) : chrono(), rate(1000.0f / UPS), nbFrames(0), average(0.0)
	{
		this->chrono.start();
	}

	inline int UpdatePerSecond::getLimit() const { return static_cast<int>(this->rate * 1000); }

	inline const double UpdatePerSecond::getUPS() const { return this->average; }
}