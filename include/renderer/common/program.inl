namespace ece
{
	inline Program::Program(const ProgramHandle handle) : _handle(handle) {}

	inline ProgramHandle Program::getHandle() const { return this->_handle; }

	template<class T>
	void Program::uniform(const std::string & uniform, const T & value)
	{
		this->use();
		auto location = OpenGL::getUniformLocation(this->_handle, uniform);
		OpenGL::uniform<T>(location, value);
		// TODO: keep the uniform location to not get it twice. And set the uniforms only at linkage step. 
	}
}