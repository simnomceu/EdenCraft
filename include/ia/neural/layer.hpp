#ifndef LAYER_HPP
#define LAYER_HPP

#include "ia/neural/neurone.hpp"

namespace ece
{
	enum class SPLIT_RULE : int
	{
		ONE_TO_ONE,
		ALL_TO_ALL,
		BALANCED
	};

	template <unsigned int Size>
	class Layer
	{
	public:
		Layer() = default;
		Layer(const SPLIT_RULE splitRule, const int nbInputs, const double bias);
		Layer(const Layer & copy) = default;
		Layer(Layer && move) = default;

		~Layer() = default;

		Layer & operator=(const Layer & copy) = default;
		Layer & operator=(Layer && move) = default;

		std::array<double, Size> evaluate(const std::vector<double> & inputs);
		void learn(const std::vector<double>& inputs, const std::array<double, Size> & delta, const double learningFactor);

		inline double getThreshold() const;
		inline std::array<double, Size> getLastOutputs() const;

	private:
		std::array<Neurone, Size> neurones;
		std::array<double, Size> lastOutputs;
		double bias;

		SPLIT_RULE splitRule;
	};
}

#include "ia/neural/layer.inl"

#endif // LAYER_HPP