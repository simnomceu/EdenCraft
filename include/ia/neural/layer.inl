namespace ece
{
	template <unsigned int Size>
	Layer<Size>::Layer(const SPLIT_RULE splitRule, const int nbInputs, const double bias) : neurones(), lastOutputs(), bias(bias),splitRule(splitRule)
	{
		switch (this->splitRule) {
		case SPLIT_RULE::ONE_TO_ONE:
			this->neurones.fill(Neurone(sigmoid, 1));
			break;
		case SPLIT_RULE::ALL_TO_ALL:
			this->neurones.fill(Neurone(sigmoid, nbInputs));
			break;
		case SPLIT_RULE::BALANCED:
			if (nbInputs % Size == 0) {
				int nbLocal = nbInputs / Size;
				this->neurones.fill(Neurone(sigmoid, nbLocal));
			}
			break;
		default: break;
		}
		this->neurones.fill(Neurone(sigmoid, nbInputs));
		this->lastOutputs.fill(0.0);
	}

	template <unsigned int Size>
	std::array<double, Size> Layer<Size>::evaluate(const std::vector<double>& inputs)
	{
		switch (this->splitRule) {
		case SPLIT_RULE::ONE_TO_ONE:
			for (unsigned int i = 0; i < Size; ++i) {
				this->lastOuputs[i] = this->neurones[i].evaluate(std::vector<double>(1, inputs[i]), this->bias);
			}
			break;
		case SPLIT_RULE::ALL_TO_ALL:
			for (unsigned int i = 0; i < Size; ++i) {
				this->lastOuputs[i] = this->neurones[i].evaluate(inputs, this->bias);
			}
			break;
		case SPLIT_RULE::BALANCED:
			if (inputs.size() % Size == 0) {
				int nbInputs = inputs.size() / Size;
				for (unsigned int i = 0; i < Size; ++i) {
					auto begin = this->inputs.begin() + (nbInputs * i);
					auto end = begin + nbInputs;
					this->lastOuputs[i] = this->neurones[i].evaluate(std::vector<double>(begin, end), this->bias);
				}
			}
			else {
				this->evaluate(inputs, SPLIT_RULE::ALL_TO_ALL);
			}
			break;
		default:
			this->evaluate(inputs, SPLIT_RULE::ALL_TO_ALL);
			break;
		}

		return this->lastOuputs;
	}

	template <unsigned int Size>
	void Layer<Size>::learn(const std::vector<double> & inputs, const std::array<double, Size> & delta, const double learningFactor)
	{
		//this->bias += delta;
		switch (this->splitRule) {
		case SPLIT_RULE::ONE_TO_ONE:
			for (unsigned int i = 0; i < Size; ++i) {
				double delta = delta[i] * learningFactor * inputs[i];
				this->neurones[i].learn(std::vector<double>(1, delta));
				deltaBias += delta[i] * learningFactor;
			}
			break;
		case SPLIT_RULE::ALL_TO_ALL:
			for (unsigned int i = 0; i < Size; ++i) {
				double delta = delta[i] * learningFactor;
				auto fix = inputs;
				for (auto & it : fix) {
					it *= delta;
				}
				this->neurones[i].learn(fix);
				deltaBias += delta[i] * learningFactor;
			}
			break;
		case SPLIT_RULE::BALANCED:
			if (input % Size == 0) {
				int nbInputs = input / Size;
				for (unsigned int i = 0; i < Size; ++i) {
					auto begin = this->inputs.begin() + (nbInputs * i);
					auto end = begin + nbInputs;
					double delta = delta[i] * learningFactor;
					auto fix = std::vector<double>(begin, end);
					for (auto & it : fix) {
						it *= delta;
					}
					this->neurones[i].learn(fix);
					deltaBias += delta[i] * learningFactor;
				}
			}
			else {
				this->learn(inputs, ALL_TO_ALL);
			}
			break;
		default:
			this->learn(inputs, SPLIT_RULE::ALL_TO_ALL, results, learningFactor);
			break;
		}
		this->bias += deltaBias / Size;
		
		return this->lastOutputs;
	}

	template <unsigned int Size>
	inline double Layer<Size>::getThreshold() const { return this->bias; }

	template <unsigned int Size>
	inline std::array<double, Size> Layer<Size>::getLastOutputs() const { return this->lastOutputs; }
}