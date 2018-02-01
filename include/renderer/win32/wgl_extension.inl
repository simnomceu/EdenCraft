#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

inline BOOL wglChoosePixelFormat(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats)
{
	static auto proxy = ece::loadOpenGLProc<PFNWGLCHOOSEPIXELFORMATARBPROC>("wglChoosePixelFormat");
	if (!proxy) {
		throw ece::OpenGLExtensionException("wglChoosePixelFormat");
	}
	return proxy(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}

inline HGLRC wglCreateContextAttribs(HDC hdc, HGLRC hShareContext, const int *attribList)
{
	static auto proxy = ece::loadOpenGLProc<PFNWGLCREATECONTEXTATTRIBSARBPROC>("wglCreateContextAttribs");
	if (!proxy) {
		throw ece::OpenGLExtensionException("wglChoosePixelFormat");
	}
	return proxy(hdc, hShareContext, attribList);
}