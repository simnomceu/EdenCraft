namespace ece
{
	inline WGLExtension::WGLExtension() : OpenGLExtension(), openglLib(nullptr) {}
}

extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribs;