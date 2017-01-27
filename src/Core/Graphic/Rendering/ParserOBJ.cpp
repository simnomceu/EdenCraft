#include "Core\Graphic\Rendering\ParserOBJ.hpp"

#include <fstream>
#include <sstream>
#include <vector>

namespace ece
{
	Mesh ParserOBJ::open(const std::string & pathname)
	{
		std::vector<float*> vertices;
		std::vector<float*> textures;
		std::vector<float*> normales;
		std::vector<int*> faces;

		std::ifstream file(pathname, std::ios::out);
		if (!file.is_open()) {
			throw std::exception(std::string("Error while trying to open " + pathname).c_str());
			// TODO replace by a great exception.
		}
		std::string line, command;
		while (file.good()) {
			getline(file, line);
			command = line.substr(0, 2);
			std::istringstream stream(line.substr(2));

			// TODO add checks for the format of the file

			if (command == "v ") {
				float* vertice = new float[3];
				stream >> vertice[0] >> vertice[1] >> vertice[2];
				vertices.push_back(vertice);
			}
			else if (command == "vt") {
				float* texture = new float[2];
				stream >> texture[0] >> texture[1];
				textures.push_back(texture);
			}
			else if (command == "vn") {
				float* normale = new float[3];
				stream >> normale[0] >> normale[1] >> normale[2];
				normales.push_back(normale);
			}
			else if (command == "f ") {
				int* face = new int[9];
				sscanf_s(line.substr(2).c_str(), "%i/%i/%i %i/%i/%i %i/%i/%i", &face[0], &face[1], &face[2], &face[3], &face[4], 
					&face[5], &face[6], &face[7], &face[8]);
				faces.push_back(face);
				// TODO check that it uses existing vertices, normales, and textures.
			}
			else if (command == "g ") {

			}
			else if (command == "o ") {

			}
			else if (line.substr(0, 6) == "usemtl") {

			}
		}
		// TODO care about objects groups and faces groups
		return Mesh();
	}
}