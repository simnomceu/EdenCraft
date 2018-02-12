#ifndef BASE_CONTEXT_OPENGL_HPP
#define BASE_CONTEXT_OPENGL_HPP

#include <memory>

#include "utility/indexing/version.hpp"

namespace ece
{
	class RenderWindow;

	class BaseContextOpenGL: public std::enable_shared_from_this<BaseContextOpenGL>
	{
	public:
		inline BaseContextOpenGL();
		BaseContextOpenGL(const BaseContextOpenGL & copy) = delete;
		BaseContextOpenGL(BaseContextOpenGL && move) = delete;

		inline virtual ~BaseContextOpenGL() = 0;

		BaseContextOpenGL & operator=(const BaseContextOpenGL & copy) = delete;
		BaseContextOpenGL & operator=(BaseContextOpenGL && move) = delete;

		inline void setMinVersion(const Version<2> & minVersion);
		inline void setMaxVersion(const Version<2> & maxVersion);

		virtual void create(const RenderWindow & window) = 0;
		virtual void swapBuffers() = 0;

		virtual void setCurrent() = 0;

		void logInfos();

	protected:
		Version<2> _minVersion;
		Version<2> _maxVersion;
	};
}

#include "renderer/opengl/base_context_opengl.inl"

#endif // BASE_CONTEXT_OPENGL_HPP
