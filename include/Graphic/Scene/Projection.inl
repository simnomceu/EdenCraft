namespace ece
{
	inline void Projection::setProjection(const double FOV, const double ratio, const double nearClipping, const double farClipping)
	{
		this->projection = glm::perspective(20.0f, 800.0f / 600.0f, 0.3f, 30.0f);
	}

	inline const GL::Matrix4x4 & Projection::getProjection() const { return this->projection; }
}