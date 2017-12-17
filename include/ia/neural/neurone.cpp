#include "ia/neural/neurone.hpp"

#include <random>

namespace ece
{
	Neurone::Neurone(const Activation & activation, const int nbInputs) : activation(activation), weights(nbInputs, 0.0)
	{
		std::random_device rd;
		std::seed_seq seed{ rd(), rd(), rd() , rd() , rd() , rd() , rd() , rd() , rd() };
		std::mt19937_64 r(seed);
		std::normal_distribution<double> distribution(0, 0.5);

		for (auto & weight : this->weights) {
			do {
				weight = distribution(r);
			} while (weight < -0.5 || weight > 0.5);
		}
	}

	void Neurone::learn(const std::vector<double> & fix)
	{
		for (unsigned short int i = 0; i < this->weights.size(); ++i) {
			this->weights[i] += fix[i];
		}
	}
}