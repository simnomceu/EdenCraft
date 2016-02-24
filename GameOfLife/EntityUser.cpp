#include "EntityUser.hpp"

using namespace core::ent;

std::shared_ptr<EntityManager> EntityUser::em = nullptr;
std::shared_ptr<std::mutex> EntityUser::lockEm = nullptr;

void EntityUser::setEntityManager(std::shared_ptr<EntityManager> cmIn, std::shared_ptr<std::mutex> lockCmIn)
{
	EntityUser::em = cmIn;
	EntityUser::lockEm = lockCmIn;
}

void EntityUser::lockEM()
{
	EntityUser::lockEm->lock();
}

void EntityUser::unlockEM()
{
	EntityUser::lockEm->unlock();
}

std::shared_ptr<EntityManager> EntityUser::getEM()
{
	return EntityUser::em;
}
