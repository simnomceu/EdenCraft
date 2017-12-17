#ifndef LAYER_HPP
#define LAYER_HPP

#include "ia/neural/neurone.hpp"

namespace ece
{
	class Layer
	{
	public:
		Layer(const int size, const int nbInputs, const double bias);
		Layer(const Layer & copy) = default;
		Layer(Layer && move) = default;

		~Layer() = default;

		Layer & operator=(const Layer & copy) = default;
		Layer & operator=(Layer && move) = default;

		std::vector<double> evaluate(const std::vector<double> & inputs, const bool split = false);
		void learn(const std::vector<double> & fix, const double delta);

		inline double getThreshold() const { return this->bias; }

	private:
		std::vector<Neurone> neurones;
		double bias;
	};
}

#endif // LAYER_HPP