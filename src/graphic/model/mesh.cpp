/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															  .oooooo.                                  oooo         o8o            
															 d8P'  `Y8b                                 `888         `"'            
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.  
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8 
															888     ooooo  888      .oP"888   888   888  888   888   888  888       
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8 
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P' 
																							  888                                   
																							 o888o                                  
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Graphic module.
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

#include "graphic/model/mesh.hpp"

#include "utility/debug/exception.hpp"

#include <iostream>
#include <algorithm>

namespace ece
{
	bool Mesh::loadFromFile(const std::string & /*filename*/)
	{
		// TODO: use a resource manager to load only if not already loaded. 
		// if modification on a resource loaded, copy as a new resource.
		bool result = true;
		/*ParserModelDAT parser;
		try {
			parser.open(filename);
			this->vertices = parser.getVertices();
			this->colors = parser.getColors();
		}
		catch (FileException & e) {
			std::cerr << e.what() << std::endl;
			this->vertices.clear();
			this->colors.clear();
			result = false;
		}*/
		return result;
	}

	Box3D Mesh::getAABB() const
	{
		auto xMin = (*std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b){ return a[0] < b[0]; }))[0];
		auto xMax = (*std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[0] < b[0]; }))[0];

		auto yMin = (*std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[1] < b[1]; }))[1];
		auto yMax = (*std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[1] < b[1]; }))[1];

		auto zMin = (*std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[2] < b[2]; }))[2];
		auto zMax = (*std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[2] < b[2]; }))[2];

		return Box3D(FloatVector3u{ xMin, yMin, zMin }, FloatVector3u{ xMax, yMax, zMax });
	}
}