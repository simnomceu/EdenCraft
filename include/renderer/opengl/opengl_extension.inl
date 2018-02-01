#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

inline GLenum glGetError()
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGETERRORPROC>("glGetError");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glGetError");
	}
	return proxy();
}

inline void glClear(GLbitfield mask)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCLEARPROC>("glClear");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glClear");
	}
	proxy(mask);
}

inline void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCLEARCOLORPROC>("glClearColor");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glClearColor");
	}
	proxy(red, green, blue, alpha);
}

inline const GLubyte * glGetString(GLenum name)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGETSTRINGPROC>("glGetString");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glGetString");
	}
	return proxy(name);
}

inline void glGetIntegerv(GLenum pname, GLint * data)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGETINTEGERVPROC>("glGetIntegerv");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glGetIntegerv");
	}
	proxy(pname, data);
}

inline void glGenBuffers(GLsizei n, GLuint * buffers)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGENBUFFERSPROC>("glGenBuffers");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glGenBuffers");
	}
	proxy(n, buffers);
}

inline void glBindBuffer(GLenum target, GLuint buffer)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLBINDBUFFERPROC>("glBindBuffer");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glBindBuffer");
	}
	proxy(target, buffer);
}

inline GLuint glCreateProgram()
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCREATEPROGRAMPROC>("glCreateProgram");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glCreateProgram");
	}
	return proxy();
}

inline void glEnable(GLenum cap)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLENABLEPROC>("glEnable");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glEnable");
	}
	proxy(cap);
}

inline void glDisable(GLenum cap)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDISABLEPROC>("glDisable");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glDisable");
	}
	proxy(cap);
}

inline void glEnablei(GLenum cap, GLuint index)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLENABLEIPROC>("glEnablei");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glEnablei");
	}
	proxy(cap, index);
}

inline void glDisablei(GLenum cap, GLuint index)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDISABLEIPROC>("glDisablei");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glDisablei");
	}
	proxy(cap, index);
}


inline void glCullFace(GLenum mode)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCULLFACEPROC>("glCullFace");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glCullFace");
	}
	proxy(mode);
}

inline void glFrontFace(GLenum mode)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLFRONTFACEPROC>("glFrontFace");
	if (!proxy) {
		throw ece::OpenGLExtensionException("v");
	}
	proxy(mode);
}

inline void glDepthFunc(GLenum func)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDEPTHFUNCPROC>("glDepthFunc");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glDepthFunc");
	}
	proxy(func);
}

inline GLuint glCreateShader(GLenum shaderType)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCREATESHADERPROC>("glCreateShader");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glCreateShader");
	}
	return proxy(shaderType);
}

inline void glShaderSource(GLuint shader, GLsizei count, const GLchar ** string, const GLint * length)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLSHADERSOURCEPROC>("glShaderSource");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glShaderSource");
	}
	proxy(shader, count, string, length);
}

inline void glCompileShader(GLuint shader)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLCOMPILESHADERPROC>("glCompileShader");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glCompileShader");
	}
	proxy(shader);
}

inline void glDeleteShader(GLuint shader)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDELETESHADERPROC>("glDeleteShader");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glDeleteShader");
	}
	proxy(shader);
}

inline void glAttachShader(GLuint program, GLuint shader)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLATTACHSHADERPROC>("glAttachShader");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glAttachShader");
	}
	proxy(program, shader);
}

inline void glLinkProgram(GLuint program)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLLINKPROGRAMPROC>("glLinkProgram");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glLinkProgram");
	}
	proxy(program);
}

inline void glUseProgram(GLuint program)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLUSEPROGRAMPROC>("glUseProgram");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glUseProgram");
	}
	proxy(program);
}

inline void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLBUFFERDATAPROC>("glBufferData");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glBufferData");
	}
	proxy(target, size, data, usage);
}

inline void glGenVertexArrays(GLsizei n, GLuint *arrays)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLGENVERTEXARRAYSPROC>("glGenVertexArrays");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glGenVertexArrays");
	}
	proxy(n, arrays);
}


inline void glBindVertexArray(GLuint array)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLBINDVERTEXARRAYPROC>("glBindVertexArray");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glBindVertexArray");
	}
	proxy(array);
}


inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLVERTEXATTRIBPOINTERPROC>("glVertexAttribPointer");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glVertexAttribPointer");
	}
	proxy(index, size, type, normalized, stride, pointer);
}


inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLVERTEXATTRIBIPOINTERPROC>("glVertexAttribIPointer");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glVertexAttribIPointer");
	}
	proxy(index, size, type, stride, pointer);
}


inline void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLVERTEXATTRIBLPOINTERPROC>("glVertexAttribLPointer");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glVertexAttribLPointer");
	}
	proxy(index, size, type, stride, pointer);
}


inline void glEnableVertexAttribArray(GLuint index)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLENABLEVERTEXATTRIBARRAYPROC>("glEnableVertexAttribArray");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glEnableVertexAttribArray");
	}
	proxy(index);
}

inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices)
{
	static auto proxy = ece::loadOpenGLProc<PFNGLDRAWELEMENTSPROC>("glDrawElements");
	if (!proxy) {
		throw ece::OpenGLExtensionException("glDrawElements");
	}
	proxy(mode, count, type, indices);
}

