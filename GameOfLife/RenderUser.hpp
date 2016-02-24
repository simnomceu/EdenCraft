#pragma once

#include <memory>
#include <mutex>
#include <SFML/Graphics.hpp>

#include "EntityManager.hpp"

namespace core
{
	namespace cmn
	{
		class RenderUser
		{
		public:
			static void setRender(std::shared_ptr<sf::RenderTexture> renderIn, std::shared_ptr<std::mutex> renderLockIn);

			void lockRender();
			void unlockRender();
			std::shared_ptr<sf::RenderTexture> getRender();
		private:
			static std::shared_ptr<sf::RenderTexture> render;
			static std::shared_ptr<std::mutex> renderLock;
		};
	}
}
