#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <functional>
#include <vector>

#include "utility/mathematics/functions.hpp"

namespace ece
{
	using Activation = std::function<double(double)>;

	class Neurone
	{
	public:
		Neurone(const Activation & activation, const int nbInputs);
		Neurone() = default;
		Neurone(const Neurone & copy) = default;
		Neurone(Neurone && move) = default;

		~Neurone() = default;

		Neurone & operator=(const Neurone & copy) = default;
		Neurone & operator=(Neurone && move) = default;

		inline double evaluate(const std::vector<double> & inputs, const double bias) const;
		void learn(const std::vector<double> & fix);

	private:
		Activation activation;
		std::vector<double> weights;
	};
}

#include "ia/neural/neurone.inl"

#endif // NEURONE_HPP
