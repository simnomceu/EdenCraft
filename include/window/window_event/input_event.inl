namespace ece
{
	inline InputEvent::InputEvent() : 
		type(ECE_TYPE_NONE), 
		doubleTap(ECE_TAP_NONE), 
		mouseButton(Mouse::ECE_MOUSE_NONE), 
		mousePosition(), 
		key(Keyboard::ECE_KEY_NONE) {}
}