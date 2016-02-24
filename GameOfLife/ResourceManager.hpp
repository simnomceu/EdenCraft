#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace core
{
	namespace rsc
	{
		class ResourceManager
		{
		public:
			ResourceManager();
			~ResourceManager();

		private:
			std::unordered_map<std::string, sf::Texture> textures;
		};

	}
}

