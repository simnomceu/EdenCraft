#ifndef EXTENSION_LOADER_HPP
#define EXTENSION_LOADER_HPP

#include <string>

#include "utility/indexing/version.hpp"

namespace ece
{
	void * loadOpenGLProc(const std::string & name, const Version<2> & requiredVersion);

	template <class T>
	inline T loadOpenGLProc(const std::string & name, const Version<2> & requiredVersion);

	Version<2> initLoader(const Version<2> & minVersionGL, const Version<2> & maxVersionGL);
}

#include "renderer/opengl/extension_loader.inl"

#endif // EXTENSION_LOADER_HPP