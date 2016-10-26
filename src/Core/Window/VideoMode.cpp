#include "Core\Window\VideoMode.hpp"

#include "Core\Window\Constant.inl"

namespace ece
{
	VideoMode::VideoMode(): 
		refreshRate(DEFAULT_REFRESH_RATE_ECE), 
		colorBits({DEFAULT_RED_BITS_ECE, DEFAULT_GREEN_BITS_ECE, DEFAULT_BLUE_BITS_ECE, DEFAULT_ALPHA_BITS_ECE}), 
		depthBits(DEFAULT_DEPTH_BITS_ECE), 
		stencilBits(DEFAULT_STENCIL_BITS_ECE), 
		samples(DEFAULT_SAMPLES_ECE), 
		stereo(DEFAULT_STEREO_ECE),
		doubleBuffering(DEFAULT_DOUBLE_BUFFERING_ECE),
		srgbCapable(DEFAULT_SRGB_CAPABLE_ECE)
	{
	}

	VideoMode::~VideoMode()
	{
	}

	bool VideoMode::operator==(const VideoMode & rightOperand) const
	{
		return this->refreshRate == rightOperand.getRefreshRate()
			&& this->colorBits == rightOperand.getColorBits()
			&& this->depthBits == rightOperand.getDepthBits()
			&& this->stencilBits == rightOperand.getStencilBits()
			&& this->samples == rightOperand.getSamples()
			&& this->stereo == rightOperand.isStereoActivate()
			&& this->doubleBuffering == rightOperand.isDoubleBufferingActivate()
			&& this->srgbCapable == rightOperand.isSrgbCapable();
	}

	bool VideoMode::operator!=(const VideoMode & rightOperand) const
	{
		return !operator==(rightOperand);
	}

	void VideoMode::setRefreshRate(const unsigned short int refreshRate)
	{
		this->refreshRate = refreshRate;
	}

	void VideoMode::setColorBits(const ece::ColorRGBA& colorBits)
	{
		this->colorBits = colorBits;
	}

	void VideoMode::setDepthBits(const unsigned short int dephtBits)
	{
		this->depthBits = dephtBits;
	}

	void VideoMode::setStencilBits(const unsigned short int stencilBits)
	{
		this->stencilBits = stencilBits;
	}

	void VideoMode::setSamples(const unsigned short int samples)
	{
		this->samples = samples;
	}

	void VideoMode::setStereo(const bool stereo)
	{
		this->stereo = stereo;
	}

	void VideoMode::setDoubleBuffering(const bool doubleBuffering)
	{
		this->doubleBuffering = doubleBuffering;
	}

	void VideoMode::setSrgbCapable(const bool srgbCapable)
	{
		this->srgbCapable = srgbCapable;
	}

	unsigned short int VideoMode::getRefreshRate() const
	{
		return this->refreshRate;
	}

	ece::ColorRGBA VideoMode::getColorBits() const
	{
		return ece::ColorRGBA(this->colorBits);
	}

	unsigned short int VideoMode::getDepthBits() const
	{
		return this->depthBits;
	}

	unsigned short int VideoMode::getStencilBits() const
	{
		return this->stencilBits;
	}

	unsigned short int VideoMode::getSamples() const
	{
		return this->samples;
	}

	bool VideoMode::isStereoActivate() const
	{
		return this->stereo;
	}

	bool VideoMode::isDoubleBufferingActivate() const
	{
		return this->doubleBuffering;
	}

	bool VideoMode::isSrgbCapable() const
	{
		return this->srgbCapable;
	}
}