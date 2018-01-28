namespace ece
{
	inline void Renderer::setProgram(const Shader & program) { program.use(); }
}