#ifndef VIDEO_MODE_HPP
#define VIDEO_MODE_HPP

/**
* @file window/common/video_mode.hpp
* @author IsiliBN (casa2pir@hotmail.fr)
* @date January, 12th 2018
* @copyright ----------
* @brief Store the value for the video mode of a window.
*
* Store the value for the video mode of a window.  Modifying the value of the video mode doesn't affect directly the hints to the window.
*
**/

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

		void setRefreshRate(const unsigned short int refreshRate);
		void setColorBits(const unsigned short int colorBits);
		void setDepthBits(const unsigned short int dephtBits);
		void setStencilBits(const unsigned short int stencilBits);
		void setSamples(const unsigned short int samples);
		void setDoubleBuffering(const bool doubleBuffering);

		inline unsigned short int getRefreshRate() const;
		inline unsigned short int getColorBits() const;
		inline unsigned short int getDepthBits() const;
		inline unsigned short int getStencilBits() const;
		inline unsigned short int getSamples() const;
		inline bool isDoubleBufferingActivate() const;

		inline bool hasChanged() const;
		inline void applyChanges();

	private:
		unsigned short int _refreshRate;
		unsigned short int _colorBits;
		unsigned short int _depthBits;
		unsigned short int _stencilBits;
		unsigned short int _samples;
		bool _doubleBuffering;

		bool _changed;
	};
}

#include "window/common/video_mode.inl"

#endif // VIDEO_MODE_HPP
