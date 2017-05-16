namespace ece
{
	inline void ShaderEffect::removeShader(std::shared_ptr<Shader> & shader)
	{
		this->shaders.erase(std::find(this->shaders.begin(), this->shaders.end(), shader));
	}

	inline void ShaderEffect::clear() { this->shaders.clear(); }
}