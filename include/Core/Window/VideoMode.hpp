#ifndef VIDEOMODE_HPP
#define VIDEOMODE_HPP

/**
* @file VideMode.hpp
* @author IsiliBN (casa2pir@hotmail.fr)
* @date October, 24th 2016
* @copyright ----------
* @brief Store the value for the video mode of a window.
*
* Store the value for the video mode of a window.  Modifying the value of the video mode doesn't affect directly the hints to the window.
*
**/

#include "Core\Window\Window.inl"

/**
* @namespace ece
*
* A namespace to gather classes and functionalities of the core engine of EdenCraft.
*
**/
namespace ece
{
	/**
	* @class VideoMode
	* @brief Store all the parameters of the video mode for a window.
	*
	* Store all the parameters of the video mode for a window. It is used for read and write operation.
	* The object is completely compatible with movable or copyable operations.
	* Setting values in VideoMode doesn't affect anything else than this object.
	*
	**/
	class VideoMode
	{
	public:
		VideoMode();
		VideoMode(const VideoMode & copy) = default;
		VideoMode(VideoMode && copy) = default;
		~VideoMode();

		VideoMode & operator=(const VideoMode & copy) = default;
		VideoMode & operator=(VideoMode && copy) = default;

		bool operator==(const VideoMode & rightOperand) const;
		bool operator!=(const VideoMode & rightOperand) const;

		void setRefreshRate(const unsigned short int refreshRate);
		void setColorBits(const ece::ColorRGBA & colorBits);
		void setDepthBits(const unsigned short int dephtBits);
		void setStencilBits(const unsigned short int stencilBits);
		void setSamples(const unsigned short int samples);
		void setDoubleBuffering(const bool doubleBuffering);
		void setSrgbCapable(const bool srgbCapable);

		unsigned short int getRefreshRate() const;
		ece::ColorRGBA getColorBits() const;
		unsigned short int getDepthBits() const;
		unsigned short int getStencilBits() const;
		unsigned short int getSamples() const;
		bool isDoubleBufferingActivate() const;
		bool isSrgbCapable() const;

	private:
		unsigned short int refreshRate;
		ece::ColorRGBA colorBits;
		unsigned short int depthBits;
		unsigned short int stencilBits;
		unsigned short int samples;
		bool doubleBuffering;
		bool srgbCapable;
	};
}

#endif // VIDEOMODE_HPP
