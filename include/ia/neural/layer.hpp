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

#ifndef LAYER_HPP
#define LAYER_HPP

#include "ia/config.hpp"
#include "ia/pch.hpp"
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
	class ECE_IA_API Layer
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