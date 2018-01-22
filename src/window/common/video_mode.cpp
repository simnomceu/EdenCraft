#include "window/common/video_mode.hpp"

namespace ece
{
	bool VideoMode::operator==(const VideoMode & rightOperand) const
	{
		return this->_refreshRate == rightOperand.getRefreshRate()
			&& this->_colorBits == rightOperand.getColorBits()
			&& this->_depthBits == rightOperand.getDepthBits()
			&& this->_stencilBits == rightOperand.getStencilBits()
			&& this->_samples == rightOperand.getSamples()
			&& this->_doubleBuffering == rightOperand.isDoubleBufferingActivate();
	}

	void VideoMode::setRefreshRate(const unsigned short int refreshRate)
	{
		this->_refreshRate = refreshRate;
		this->_changed = true;
	}

	void VideoMode::setColorBits(const unsigned short int colorBits)
	{
		this->_colorBits = colorBits;
		this->_changed = true;
	}

	void VideoMode::setDepthBits(const unsigned short int dephtBits)
	{
		this->_depthBits = dephtBits;
		this->_changed = true;
	}

	void VideoMode::setStencilBits(const unsigned short int stencilBits)
	{
		this->_stencilBits = stencilBits;
		this->_changed = true;
	}

	void VideoMode::setSamples(const unsigned short int samples)
	{
		this->_samples = samples;
		this->_changed = true;
	}

	void VideoMode::setDoubleBuffering(const bool doubleBuffering)
	{
		this->_doubleBuffering = doubleBuffering;
		this->_changed = true;
	}
}