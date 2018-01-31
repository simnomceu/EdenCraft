#ifndef EXTENSION_LOADER_HPP
#define EXTENSION_LOADER_HPP

#include <string>

namespace ece
{
	inline void * loadOpenGLProc(const std::string & name);

	template <class T>
	inline T loadOpenGLProc(const std::string & name);
}

#include "renderer/opengl/extension_loader.inl"

#endif // EXTENSION_LOADER_HPP