#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include "ia/neural/layer.hpp"

namespace ece
{
	/**
	 * @class Perceptron
	 * @brief Design a neurone able to solve linear problems with a binary solution.
	 */
	class Perceptron
	{
	public:
		/**
		 * Perceptron()
		 * @brief Default constructor. Build the perceptron with input weights and threshold initialized.
		 */
		Perceptron(const int nbInputs, const double learningFactor, const double threshold);
		Perceptron(const Perceptron & copy) = default;
		Perceptron(Perceptron && move) = default;

		~Perceptron() = default;

		Perceptron & operator=(const Perceptron & copy) = default;
		Perceptron & operator=(Perceptron && move) = default;

		double evaluate(const std::vector<double> & inputs);
		void learn(const std::vector<double> & inputs, const double result, const double output);

	protected:
		double learningFactor;

		Neurone neurone;
		double bias;
	};
}

#endif // PERCEPTRON_HPP