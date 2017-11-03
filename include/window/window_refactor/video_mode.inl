namespace ece
{
	inline VideoMode::VideoMode() :
		refreshRate(),
		colorBits(32),
		depthBits(24),
		stencilBits(8),
		samples(16),
		doubleBuffering(true),
		changed(false)
	{
	}

	inline VideoMode::~VideoMode() {}

	inline bool VideoMode::operator!=(const VideoMode & rightOperand) const { return !operator==(rightOperand); }

	inline unsigned short int VideoMode::getRefreshRate() const { return this->refreshRate; }

	inline unsigned short int VideoMode::getColorBits() const { return this->colorBits; }

	inline unsigned short int VideoMode::getDepthBits() const { return this->depthBits; }

	inline unsigned short int VideoMode::getStencilBits() const { return this->stencilBits; }

	inline unsigned short int VideoMode::getSamples() const { return this->samples; }

	inline bool VideoMode::isDoubleBufferingActivate() const { return this->doubleBuffering; }

	inline bool VideoMode::hasChanged() const { return this->changed; }

	inline void VideoMode::applyChanges() { this->changed = false; }
}