namespace ece
{
	inline VideoMode::VideoMode() :
		refreshRate(/*DEFAULT_REFRESH_RATE_ECE*/),
		colorBits(/*{ DEFAULT_RED_BITS_ECE, DEFAULT_GREEN_BITS_ECE, DEFAULT_BLUE_BITS_ECE, DEFAULT_ALPHA_BITS_ECE }*/),
		depthBits(/*DEFAULT_DEPTH_BITS_ECE*/),
		stencilBits(/*DEFAULT_STENCIL_BITS_ECE*/),
		samples(/*DEFAULT_SAMPLES_ECE*/),
		stereo(/*DEFAULT_STEREO_ECE*/),
		doubleBuffering(/*DEFAULT_DOUBLE_BUFFERING_ECE*/),
		srgbCapable(/*DEFAULT_SRGB_CAPABLE_ECE*/)
	{
	}

	inline VideoMode::~VideoMode() {}

	inline bool VideoMode::operator!=(const VideoMode & rightOperand) const { return !operator==(rightOperand); }

	inline void VideoMode::setRefreshRate(const unsigned short int refreshRate) { this->refreshRate = refreshRate; }

	inline void VideoMode::setColorBits(const ece::ColorRGBA& colorBits) { this->colorBits = colorBits; }

	inline void VideoMode::setDepthBits(const unsigned short int dephtBits) { this->depthBits = dephtBits; }

	inline void VideoMode::setStencilBits(const unsigned short int stencilBits) { this->stencilBits = stencilBits; }

	inline void VideoMode::setSamples(const unsigned short int samples) { this->samples = samples; }

	inline void VideoMode::setStereo(const bool stereo) { this->stereo = stereo; }

	inline void VideoMode::setDoubleBuffering(const bool doubleBuffering) { this->doubleBuffering = doubleBuffering; }

	inline void VideoMode::setSrgbCapable(const bool srgbCapable) { this->srgbCapable = srgbCapable; }

	inline unsigned short int VideoMode::getRefreshRate() const { return this->refreshRate; }

	inline ece::ColorRGBA VideoMode::getColorBits() const { return ece::ColorRGBA(this->colorBits); }

	inline unsigned short int VideoMode::getDepthBits() const { return this->depthBits; }

	inline unsigned short int VideoMode::getStencilBits() const { return this->stencilBits; }

	inline unsigned short int VideoMode::getSamples() const { return this->samples; }

	inline bool VideoMode::isStereoActivate() const { return this->stereo; }

	inline bool VideoMode::isDoubleBufferingActivate() const { return this->doubleBuffering; }

	inline bool VideoMode::isSrgbCapable() const { return this->srgbCapable; }
}