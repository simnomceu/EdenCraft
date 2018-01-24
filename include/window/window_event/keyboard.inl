namespace ece
{
	inline bool Keyboard::isKeyPressed(const Key code)
	{
		if (code == Keyboard::Key::KEY_NONE) {
			throw std::runtime_error("That code is not a valid key.");
		}
		return Keyboard::_states[static_cast<unsigned int>(code)];
	}

	inline void Keyboard::pressKey(const Key code, const bool state)
	{
		if (code == Keyboard::Key::KEY_NONE) {
			throw std::runtime_error("That code is not a valid key.");
		}
		Keyboard::_states[static_cast<unsigned int>(code)] = state;
	}
}