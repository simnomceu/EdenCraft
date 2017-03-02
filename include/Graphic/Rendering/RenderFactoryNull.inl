namespace ece
{
	inline Program * RenderFactoryNull::createProgram() { return nullptr; }
	inline Shader * RenderFactoryNull::createShader(const Shader::ShaderType & type) { return nullptr; }
}