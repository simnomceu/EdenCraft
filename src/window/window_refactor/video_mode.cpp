#include "window/window_refactor/video_mode.hpp"

namespace ece
{
	bool VideoMode::operator==(const VideoMode & rightOperand) const
	{
		return this->refreshRate == rightOperand.getRefreshRate()
			&& this->colorBits == rightOperand.getColorBits()
			&& this->depthBits == rightOperand.getDepthBits()
			&& this->stencilBits == rightOperand.getStencilBits()
			&& this->samples == rightOperand.getSamples()
			&& this->doubleBuffering == rightOperand.isDoubleBufferingActivate();
	}

	void VideoMode::setRefreshRate(const unsigned short int refreshRate)
	{
		this->refreshRate = refreshRate;
		this->changed = true;
	}

	void VideoMode::setColorBits(const unsigned short int colorBits)
	{
		this->colorBits = colorBits;
		this->changed = true;
	}

	void VideoMode::setDepthBits(const unsigned short int dephtBits)
	{
		this->depthBits = dephtBits;
		this->changed = true;
	}

	void VideoMode::setStencilBits(const unsigned short int stencilBits)
	{
		this->stencilBits = stencilBits;
		this->changed = true;
	}

	void VideoMode::setSamples(const unsigned short int samples)
	{
		this->samples = samples;
		this->changed = true;
	}

	void VideoMode::setDoubleBuffering(const bool doubleBuffering)
	{
		this->doubleBuffering = doubleBuffering;
		this->changed = true;
	}
}