namespace ece
{
	inline VideoMode::VideoMode() :
		_refreshRate(),
		_colorBits(32),
		_depthBits(24),
		_stencilBits(8),
		_samples(16),
		_doubleBuffering(true),
		_changed(false)
	{
	}

	inline VideoMode::~VideoMode() {}

	inline bool VideoMode::operator!=(const VideoMode & rightOperand) const { return !operator==(rightOperand); }

	inline unsigned short int VideoMode::getRefreshRate() const { return this->_refreshRate; }

	inline unsigned short int VideoMode::getColorBits() const { return this->_colorBits; }

	inline unsigned short int VideoMode::getDepthBits() const { return this->_depthBits; }

	inline unsigned short int VideoMode::getStencilBits() const { return this->_stencilBits; }

	inline unsigned short int VideoMode::getSamples() const { return this->_samples; }

	inline bool VideoMode::isDoubleBufferingActivate() const { return this->_doubleBuffering; }

	inline bool VideoMode::hasChanged() const { return this->_changed; }

	inline void VideoMode::applyChanges() { this->_changed = false; }
}