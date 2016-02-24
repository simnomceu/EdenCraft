#include "RenderUser.hpp"

using namespace core::cmn;

std::shared_ptr<sf::RenderTexture> RenderUser::render = nullptr;
std::shared_ptr<std::mutex> RenderUser::renderLock = nullptr;

void RenderUser::setRender(std::shared_ptr<sf::RenderTexture> renderIn, std::shared_ptr<std::mutex> renderLockIn)
{
	RenderUser::render = renderIn;
	RenderUser::renderLock = renderLockIn;
}

void RenderUser::lockRender()
{
	RenderUser::renderLock->lock();
}

void RenderUser::unlockRender()
{
	RenderUser::renderLock->unlock();
}

std::shared_ptr<sf::RenderTexture> RenderUser::getRender()
{
	return RenderUser::render;
}
