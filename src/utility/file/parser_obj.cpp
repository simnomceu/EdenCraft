#include "utility/file/parser_obj.hpp"

#include "utility/debug/exception.hpp"
#include "utility/type.hpp"

#include <fstream>
#include <sstream>

#ifdef __linux__
	#define sscanf_s sscanf
#endif

namespace ece
{
	void ParserOBJ::open(const std::string & pathname)
	{

		std::ifstream file(pathname, std::ios::out);
		if (!file.is_open()) {
			throw FileException(FileCodeError::BAD_PATH, pathname);
		}
		std::string line, command;
		while (file.good()) {
			getline(file, line);
			if (line.size() >= 2) {
				command = line.substr(0, 2);
				std::istringstream stream(line.substr(2));

				// TODO add checks for the format of the file

				if (command == "v ") {
					float vertice[3];
					stream >> vertice[0] >> vertice[1] >> vertice[2];
					vertices.push_back(vertice[0]);
					vertices.push_back(vertice[1]);
					vertices.push_back(vertice[2]);
				}
				else if (command == "vt") {
					float texture[2];
					stream >> texture[0] >> texture[1];
					textures.push_back(texture[0]);
					textures.push_back(texture[1]);
				}
				else if (command == "vn") {
					float normale[3];
					stream >> normale[0] >> normale[1] >> normale[2];
					normales.push_back(normale[0]);
					normales.push_back(normale[1]);
					normales.push_back(normale[2]);
				}
				else if (command == "f ") {
					int face[9];
					sscanf_s(line.substr(2).c_str(), "%i/%i/%i %i/%i/%i %i/%i/%i", &face[0], &face[1], &face[2], &face[3], &face[4],
						&face[5], &face[6], &face[7], &face[8]);
					faces.push_back(face[0] * 3);
					//faces.push_back(face[1]);
					//faces.push_back(face[2]);
					faces.push_back(face[3] * 3);
					//faces.push_back(face[4]);
					//faces.push_back(face[5]);
					faces.push_back(face[6] * 3);
					//faces.push_back(face[7]);
					//faces.push_back(face[8]);

					// TODO check that it uses existing vertices, normales, and textures.
				}
				else if (command == "g ") {

				}
				else if (command == "o ") {

				}
				else if (line.size() > 6 && line.substr(0, 6) == "usemtl") {

				}
			}
		}
		// TODO care about objects groups and faces groups
	}
}
