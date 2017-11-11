namespace ece
{
	template<class T>
	void VBO::bufferData(const std::vector<T>& data, const BufferUsage usage)
	{
		this->bind();
		OpenGL::bufferData(this->type, data, usage);
	}

	inline void VBO::setType(const BufferType type) { this->type = type; }

	inline VBOHandle VBO::getHandle() const { return this->handle; }
}