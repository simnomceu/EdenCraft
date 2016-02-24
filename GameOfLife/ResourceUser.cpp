#include "ResourceUser.hpp"

using namespace core::rsc;

std::shared_ptr<ResourceManager> ResourceUser::rm;
std::shared_ptr<std::mutex> ResourceUser::lockRm = nullptr;

void ResourceUser::setResourceManager(std::shared_ptr<ResourceManager> rmIn, std::shared_ptr<std::mutex> lockRmIn)
{
	ResourceUser::rm = rmIn;
	ResourceUser::lockRm = lockRmIn;
}

void ResourceUser::lockRM()
{
	ResourceUser::lockRm->lock();
}

void ResourceUser::unlockRM()
{
	ResourceUser::lockRm->unlock();
}

std::shared_ptr<ResourceManager> ResourceUser::getRM()
{
	return ResourceUser::rm;
}
