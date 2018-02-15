namespace ece
{
	template <class T>
	inline T loadOpenGLProc(const std::string & name, const Version<2> & requiredVersion)
	{
		return reinterpret_cast<T>(loadOpenGLProc(name, requiredVersion));
	}
}