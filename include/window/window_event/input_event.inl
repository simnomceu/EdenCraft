namespace ece
{
	inline InputEvent::InputEvent() : 
		_type(InputEvent::Type::ECE_TYPE_NONE),
		_doubleTap(InputEvent::DoubleTap::ECE_TAP_NONE),
		_mouseButton(Mouse::Button::ECE_MOUSE_NONE), 
		_mousePosition(), 
		_key(Keyboard::Key::KEY_NONE) {}
}