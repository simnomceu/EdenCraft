#ifndef RENDERINGSERVICE_HPP
#define RENDERINGSERVICE_HPP

#include "Util\Module\ServiceFactory.hpp"
#include "Util\Module\ServiceLocator.hpp"
#include "Rendering\RenderFactoryNull.hpp"

namespace ece
{
	typedef ServiceFactory<RenderFactory> RenderingServiceFactory;
	typedef ServiceLocator<RenderFactory, RenderFactoryNull> RenderingServiceLocator;
}

#endif // RENDERINGSERVICE_HPP