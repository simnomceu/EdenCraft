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

#include "ia/pch.hpp"
#include "ia/neural/neurone.hpp"

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