namespace ece
{
	inline InputEvent::InputEvent() : type(NONE) {}

	inline const InputEvent::InputEventType InputEvent::getType() const { return this->type; }

	inline void InputEvent::setType(const InputEvent::InputEventType type) { this->type = type; }
}