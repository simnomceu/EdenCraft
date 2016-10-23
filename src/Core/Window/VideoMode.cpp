#include "Core\Window\VideoMode.hpp"

namespace ece
{
	VideoMode::VideoMode(): 
		refreshRate(60), 
		colorBits({8, 8, 8}), 
		depthBits(24), 
		stencilBits(24), 
		samples(0), 
		doubleBuffering(true),
		srgbCapable(0)
	{
	}

	VideoMode::~VideoMode()
	{
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
	void VideoMode::setDoubleBuffering(const bool doubleBuffering)
	{
		this->doubleBuffering = doubleBuffering;
	}

	void VideoMode::setSrgbCapable(const unsigned short int srgbCapable)
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
	bool VideoMode::isDoubleBufferingActivate() const
	{
		return this->doubleBuffering;
	}
	unsigned short int VideoMode::getSrgbCapable() const
	{
		return this->srgbCapable;
	}
}