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
	template <unsigned int Input, unsigned int Output, unsigned int Hidden>
	Network<Input, Output, Hidden>::Network(const SPLIT_RULE splitRule, const double threshold, const double learningFactor) :
		inputLayer(splitRule, Input, threshold),
		hiddenLayers(),
		outputLayer(splitRule, Output, threshold),
		learningFactor(learningFactor)
	{
		hiddenLayers.fill(Layer<(Input + Output) / 2>(splitRule, Input, threshold));
	}

	template <unsigned int Input, unsigned int Output, unsigned int Hidden>
	std::vector<double> Network<Input, Output, Hidden>::evaluate(const std::vector<double> & inputs)
	{
		auto outputs = this->inputLayer.evaluate(inputs);
		for (auto & hidden : this->hiddenLayer) {
			outputs = hidden.evaluate(outputs)
		}
		return this->outputLayer.evaluate(outputs);
	}

	template <unsigned int Input, unsigned int Output, unsigned int Hidden>
	void Network<Input, Output, Hidden>::learn(const std::vector<double> & inputs, const std::vector<double> & results)
	{
		auto outputs = this->inputLayer.evaluate(inputs);
		for (auto & hidden : this->hiddenLayer) {
			outputs = hidden.evaluate(outputs);
		}
		outputs = this->outputLayer.evaluate(outputs);

		std::array<double, Size> deltaOutputs;
		std::array<std::array<double, Size>, Hidden> deltaHidden;
		std::array<double, Size> deltaInputs;
		for (int i = 0; i < outputs.size(); ++i) {
			deltaOutputs[i] = outputs[i] * (1.0 - outputs[i]) * (results[i] - outputs[i]);
		}
		for (unsigned int k = 0; k < Hidden + 1; ++k) {
			for (unsigned int j = 0; j < this->hiddenLayers[k].getSize(); j++) {
				double cumulateError = 0.0;
				for (unsigned int i = 0; i < outputs.size(); ++i) {
					cumulateError += this->hiddenLayers[k + 1].getNeurone(j).getWeight(i) * deltaOutputs[i];
				}
				deltaHidden[k][j] = this->hiddenLayers(k).getLastOutput(j) * (1.0 - this->hiddenLayers(k).getLastOutput(j)) * cumulateError;
			}
		}
		for (int j = 0; j < Input; ++j) {
			double cumulateError = 0.0;
			for (unsigned int i = 0; i < Input.size(); ++i) {
				cumulateError += this->hiddenLayers[0].getNeurone(i).getWeight(j) * deltaHidden[0][i];
			}
			deltaInput[j] = this->inputLayer.getLastOutput(j) * (1.0 - this->inputLayer.getLastOutput(j)) * cumulateError;
		}

		this->outputLayer.learn(this->hiddenLayers[Hidden - 1].getLastOutputs(), deltaOutputs, this->learningFactor);
		for (unsigned int i = 1; i < Hidden; ++i) {
			this->hiddenLayers[i].learn(this->hiddenLayers[i - 1].getLastOutputs(), deltaHidden[i], this->learningFactor);
		}
		this->hiddenLayers[0].learn(this->inputLayers.getLastOutputs(), deltaHidden[i], this->learningFactor);
		this->inputLayer.learn(inputs, deltaInputs, this->learningFactor);
	}
}