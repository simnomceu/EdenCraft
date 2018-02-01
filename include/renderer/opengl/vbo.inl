namespace ece
{
	template<class T>
	void VBO::bufferData(const std::vector<T>& data, const BufferUsage usage)
	{
		this->bind();
		OpenGL::bufferData(this->_type, data, usage);
	}

	inline void VBO::setType(const BufferType type) { this->_type = type; }

	inline Handle VBO::getHandle() const { return this->_handle; }
}