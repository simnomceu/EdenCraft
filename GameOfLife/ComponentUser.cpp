#include "ComponentUser.hpp"
#include "EntityUser.hpp"

using namespace core::cmp;

std::shared_ptr<ComponentManager> ComponentUser::cm = nullptr;
std::shared_ptr<std::mutex> ComponentUser::lockCm = nullptr;

void ComponentUser::setComponentManager(std::shared_ptr<ComponentManager> cmIn, std::shared_ptr<std::mutex> lockCmIn)
{
	ComponentUser::cm = cmIn;
	ComponentUser::lockCm = lockCmIn;
}

void ComponentUser::lockCM()
{
	this->lockCm->lock();
}

void ComponentUser::unlockCM()
{
	this->lockCm->unlock();
}

std::shared_ptr<ComponentManager> ComponentUser::getCM()
{
	return this->cm;
}
