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

#include "Window\Window.inl"
#include "Window\Constant.inl"

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
		inline VideoMode();
		VideoMode(const VideoMode & copy) = default;
		VideoMode(VideoMode && copy) = default;
		inline ~VideoMode();

		VideoMode & operator=(const VideoMode & copy) = default;
		VideoMode & operator=(VideoMode && copy) = default;

		bool operator==(const VideoMode & rightOperand) const;
		inline bool operator!=(const VideoMode & rightOperand) const;

		inline void setRefreshRate(const unsigned short int refreshRate);
		inline void setColorBits(const ece::ColorRGBA & colorBits);
		inline void setDepthBits(const unsigned short int dephtBits);
		inline void setStencilBits(const unsigned short int stencilBits);
		inline void setSamples(const unsigned short int samples);
		inline void setStereo(const bool stereo);
		inline void setDoubleBuffering(const bool doubleBuffering);
		inline void setSrgbCapable(const bool srgbCapable);

		inline unsigned short int getRefreshRate() const;
		inline ece::ColorRGBA getColorBits() const;
		inline unsigned short int getDepthBits() const;
		inline unsigned short int getStencilBits() const;
		inline unsigned short int getSamples() const;
		inline bool isStereoActivate() const;
		inline bool isDoubleBufferingActivate() const;
		inline bool isSrgbCapable() const;

	private:
		unsigned short int refreshRate;
		ece::ColorRGBA colorBits;
		unsigned short int depthBits;
		unsigned short int stencilBits;
		unsigned short int samples;
		bool stereo;
		bool doubleBuffering;
		bool srgbCapable;
	};
}

#include "Window\VideoMode.inl"

#endif // VIDEOMODE_HPP
