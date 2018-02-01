#ifndef WGL_EXTENSION_HPP
#define WGL_EXTENSION_HPP

#include "GL/wglext.h"

inline BOOL wglChoosePixelFormat(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

inline HGLRC wglCreateContextAttribs(HDC hdc, HGLRC hShareContext, const int *attribList);

#include "renderer/win32/wgl_extension.inl"

#endif // WGL_EXTENSION_HPP
