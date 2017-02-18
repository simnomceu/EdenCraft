namespace ece
{
	inline Event::Event() : type(NONE) {}

	inline const Event::EventType Event::getType() const { return this->type; }

	inline void Event::setType(const Event::EventType type) { this->type = type; }
}