namespace ece
{
	inline Program::Program(): handle(GL::NULL_ID) {}

	inline const GL::ProgramID & Program::getHandle() const { return this->handle; }
}