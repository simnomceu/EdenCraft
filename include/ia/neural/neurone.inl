#include <numeric>

namespace ece
{
	inline double Neurone::evaluate(const std::vector<double> & inputs, const double bias) const
	{
		return this->activation(std::inner_product(this->weights.begin(), this->weights.end(), inputs.begin(), 0.0) + bias);
	}
}