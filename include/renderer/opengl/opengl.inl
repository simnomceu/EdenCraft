namespace ece
{
	template<class T> 
	void OpenGL::uniform(const UniformHandle uniform, const T value)
	{
		throw std::runtime_error("A uniform cannot be set with this type.");
	}
}