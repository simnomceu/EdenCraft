namespace ece
{
	inline Shader::Shader(const Handle handle) : _handle(handle) {}

	inline Handle Shader::getHandle() const { return this->_handle; }

	template<class T>
	void Shader::uniform(const std::string & uniform, const T & value)
	{
		this->use();
		auto location = OpenGL::getUniformLocation(this->_handle, uniform);
		OpenGL::uniform<T>(location, value);
		// TODO: keep the uniform location to not get it twice. And set the uniforms only at linkage step. 
	}
}