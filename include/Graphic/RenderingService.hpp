#ifndef RENDERINGSERVICE_HPP
#define RENDERINGSERVICE_HPP

#include "Core\Util\Module\Service.hpp"
#include "Core\Util\Module\ServiceFactory.hpp"
#include "Core\Util\Module\ServiceLocator.hpp"
#include "Core\Graphic\Rendering\RenderFactoryNull.hpp"

namespace ece
{
	typedef ServiceFactory<RenderFactory> RenderingServiceFactory;
	typedef ServiceLocator<RenderFactory, RenderFactoryNull> RenderingServiceLocator;

	class RenderingService : public Service
	{
	public:
		RenderingService();

		virtual void init(Mode mode = Mode::NONE);

		virtual void setMode(Mode mode);

	private:

	};
}

#endif // RENDERINGSERVICE_HPP