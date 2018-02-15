namespace ece
{
	inline void IBO::bind() const { OpenGL::bindBuffer(BufferType::ELEMENT_ARRAY_BUFFER, this->_handle); }

	inline void IBO::bufferData(const std::vector<unsigned int> & data, const BufferUsage usage)
	{
		this->bind();
		OpenGL::bufferData(BufferType::ELEMENT_ARRAY_BUFFER, data, usage);
	}

	inline Handle IBO::getHandle() const { return this->_handle; }
}