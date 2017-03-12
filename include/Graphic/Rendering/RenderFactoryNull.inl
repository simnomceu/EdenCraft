namespace ece
{
	inline Program * RenderFactoryNull::createProgram() { return nullptr; }
	inline Shader * RenderFactoryNull::createShader(const ShaderType & type) { return nullptr; }
}