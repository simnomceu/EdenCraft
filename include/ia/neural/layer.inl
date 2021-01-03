/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															 ooooo       .o.
															 `888'      .888.
															  888      .8"888.
															  888     .8' `888.
															  888    .88ooo8888.
															  888   .8'     `888.
															 o888o o88o     o8888o



				This file is part of EdenCraft Engine - Core module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.
*/

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