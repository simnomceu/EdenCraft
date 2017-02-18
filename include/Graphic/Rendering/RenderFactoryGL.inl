namespace ece
{
	inline Program * RenderFactoryGL::createProgram() { return new ProgramGL(); }

	inline Shader * RenderFactoryGL::createShader(const Shader::ShaderType & type) { return new ShaderGL(type); }
}