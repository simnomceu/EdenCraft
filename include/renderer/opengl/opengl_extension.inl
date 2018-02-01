#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

inline GLenum glGetError()
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGETERRORPROC>("glGetError");
	if (proxy) {
		throw ece::OpenGLExtensionException("glGetError");
	}
	return proxy();
}

inline void glClear(GLbitfield mask)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCLEARPROC>("glClear");
	if (proxy) {
		throw ece::OpenGLExtensionException("glClear");
	}
	proxy(mask);
}

inline void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCLEARCOLORPROC>("glClearColor");
	if (proxy) {
		throw ece::OpenGLExtensionException("glClearColor");
	}
	proxy(red, green, blue, alpha);
}

inline const GLubyte * glGetString(GLenum name)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGETSTRINGPROC>("glGetString");
	if (proxy) {
		throw ece::OpenGLExtensionException("glGetString");
	}
	return proxy(name);
}

inline void glGetIntegerv(GLenum pname, GLint * data)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGETINTEGERVPROC>("glGetIntegerv");
	if (proxy) {
		throw ece::OpenGLExtensionException("glGetIntegerv");
	}
	proxy(pname, data);
}

inline void glGenBuffers(GLsizei n, GLuint * buffers)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGENBUFFERSPROC>("glGenBuffers");
	if (proxy) {
		throw ece::OpenGLExtensionException("glGenBuffers");
	}
	proxy(n, buffers);
}

inline void glBindBuffer(GLenum target, GLuint buffer)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLBINDBUFFERPROC>("glBindBuffer");
	if (proxy) {
		throw ece::OpenGLExtensionException("glBindBuffer");
	}
	proxy(target, buffer);
}

inline GLuint glCreateProgram()
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCREATEPROGRAMPROC>("glCreateProgram");
	if (proxy) {
		throw ece::OpenGLExtensionException("glCreateProgram");
	}
	return proxy();
}

inline void glEnable(GLenum cap)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLENABLEPROC>("glEnable");
	if (proxy) {
		throw ece::OpenGLExtensionException("glEnable");
	}
	proxy(cap);
}

inline void glDisable(GLenum cap)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDISABLEPROC>("glDisable");
	if (proxy) {
		throw ece::OpenGLExtensionException("glDisable");
	}
	proxy(cap);
}

inline void glEnablei(GLenum cap, GLuint index)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLENABLEIPROC>("glEnablei");
	if (proxy) {
		throw ece::OpenGLExtensionException("glEnablei");
	}
	proxy(cap, index);
}

inline void glDisablei(GLenum cap, GLuint index)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDISABLEIPROC>("glDisablei");
	if (proxy) {
		throw ece::OpenGLExtensionException("glDisablei");
	}
	proxy(cap, index);
}


inline void glCullFace(GLenum mode)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCULLFACEPROC>("glCullFace");
	if (proxy) {
		throw ece::OpenGLExtensionException("glCullFace");
	}
	proxy(mode);
}

inline void glFrontFace(GLenum mode)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLFRONTFACEPROC>("glFrontFace");
	if (proxy) {
		throw ece::OpenGLExtensionException("v");
	}
	proxy(mode);
}

inline void glDepthFunc(GLenum func)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDEPTHFUNCPROC>("glDepthFunc");
	if (proxy) {
		throw ece::OpenGLExtensionException("glDepthFunc");
	}
	proxy(func);
}