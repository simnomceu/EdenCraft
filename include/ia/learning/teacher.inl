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

#include "utility/log.hpp"

namespace ece
{
	inline Teacher::Teacher(const double thresholdError): thresholdError(thresholdError)
	{
	}

	void Teacher::teachTo(const Epoch & epoch, Perceptron & perceptron)
	{
		int count = 0;
		std::vector<double> errors(epoch.patterns.size());
		double error = 0.0;
		ece::INFO << "========== Pattern " << epoch.name << " ==========" << ece::flush;
		do {
			error = 0;
			ece::INFO << "Epoch " << count << " | Output: ";
			for (unsigned int i = 0; i < epoch.patterns.size(); ++i) {
				auto output = perceptron.evaluate(epoch.patterns[i].inputs);
				perceptron.learn(epoch.patterns[i].inputs, epoch.patterns[i].result, output);
				errors[i] = std::fabs(epoch.patterns[i].result - output);
				error += errors[i];
				ece::INFO << output << "|";
			}
			error /= epoch.patterns.size();
			ece::INFO << "Error: " << error << ece::flush;
			++count;
		} while (error > this->thresholdError);
		ece::INFO << "========== Learning " << epoch.name << " completed ==========\n\n" << ece::flush;
	}
}