#pragma once

#include <memory>
#include <mutex>

#include "EntityManager.hpp"

namespace core
{
	namespace ent
	{
		class EntityUser
		{
		public:
			static void setEntityManager(std::shared_ptr<EntityManager> emIn, std::shared_ptr<std::mutex> lockEmIn);

			void lockEM();
			void unlockEM();
			std::shared_ptr<EntityManager> getEM();
		private:
			static std::shared_ptr<EntityManager> em;
			static std::shared_ptr<std::mutex> lockEm;
		};
	}
}
