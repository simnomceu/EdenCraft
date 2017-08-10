#include "window/video_mode.hpp"

#include "window/constant.inl"

namespace ece
{
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
}