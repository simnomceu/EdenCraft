namespace ece
{
	inline double heaviside(const double value) noexcept { return (value >= 0.0 ? 1.0 : 0.0); }

	inline double halfMaxHeaviside(const double value) noexcept { return value > 0.0 ? 1.0 : (value < 0.0 ? 0.0 : 0.5); }

	inline double sigmoid(const double value) noexcept { return 1.0 / (1.0 + std::exp(-value)); }
}