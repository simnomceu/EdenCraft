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

#ifndef NEURONE_HPP
#define NEURONE_HPP


#include "ia/config.hpp"
#include "ia/pch.hpp"
#include "utility/mathematics/functions.hpp"

namespace ece
{
	using Activation = std::function<double(double)>;

	class ECE_IA_API Neurone
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
