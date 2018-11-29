#include "adaptative_proportion.hpp"
/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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
	namespace renderer
	{
		namespace image
		{
				template <class T>
				AdaptativeProportion<T>::AdaptativeProportion(proportion_type targetResolution, proportion_type measure) noexcept : 
					_targetResolution(std::move(targetResolution)), _measure(std::move(measure))
				{
				}

				template <class T>
				inline AdaptativeProportion<T> & AdaptativeProportion<T>::operator=(proportion_type measure) noexcept { this->_measure = std::move(measure); return *this; }

				template <class T>
				inline void AdaptativeProportion<T>::setTargetResolution(proportion_type targetResolution) { this->_targetResolution = std::move(targetResolution); }

				template<class T>
				inline T AdaptativeProportion<T>::get(proportion_type currentResolution) { return this->_measure * (currentResolution / this->_targetResolution); }

				template<class T>
				inline const T & AdaptativeProportion<T>::getTargetResolution() const noexcept { return this->_targetResolution; }

				template<class T>
				inline const T & AdaptativeProportion<T>::getMeasure() const noexcept { return this->_measure; }

		} // namespace image
	} // namespace renderer
} // namespace ece