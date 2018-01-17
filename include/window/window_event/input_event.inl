namespace ece
{
	inline InputEvent::InputEvent() : 
		_type(ECE_TYPE_NONE), 
		_doubleTap(ECE_TAP_NONE), 
		_mouseButton(Mouse::ECE_MOUSE_NONE), 
		_mousePosition(), 
		_key(Keyboard::KEY_NONE) {}
}