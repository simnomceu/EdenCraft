namespace ece
{
	inline ProgramHandle Program::getHandle() const { return this->handle; }

	template<class T>
	void Program::uniform(const std::string & uniform, const T & value)
	{
		this->use();
		auto location = OpenGL::getUniformLocation(this->handle, uniform);
		OpenGL::uniform<T>(location, value);
		// TODO: keep the uniform location to not get it twice. And set the uniforms only at linkage step. 
	}
}