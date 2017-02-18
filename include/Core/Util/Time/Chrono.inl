namespace ece
{

	inline Chrono::Chrono() : begin() {}

	inline void Chrono::start() { this->begin = std::chrono::system_clock::now(); }
}