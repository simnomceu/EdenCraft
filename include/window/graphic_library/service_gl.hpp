#ifndef SERVICE_GL_HPP
#define SERVICE_GL_HPP

#include "service/service_factory.hpp"
#include "service/service_locator.hpp"
#include "graphic_library/none_gl.hpp"

namespace ece
{
	typedef ServiceFactory<BaseGL> ServiceGLFactory;
	typedef ServiceLocator<BaseGL, NoneGL> ServiceGLLocator;
}

#endif // SERVICE_GL_HPP