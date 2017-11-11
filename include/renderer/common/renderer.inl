namespace ece
{
	inline void Renderer::setProgram(const Program & program) { program.use(); }
}