namespace ece
{
	template <class T>
	inline T loadOpenGLProc(const std::string & name)
	{
		return reinterpret_cast<T>(OpenGLExtension::loadOpenGLProc(name));
	}
}