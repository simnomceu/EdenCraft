namespace ece
{
	inline WGLExtension::WGLExtension() : OpenGLExtension(), _openglLib(nullptr) {}
}

extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribs;