#ifndef VIDEOMODE_HPP
#define VIDEOMODE_HPP

#include "Geom\Vector.hpp"

namespace Utils
{
	class VideoMode
	{
	public:
		VideoMode();
		~VideoMode();

		void setRefreshRate(const unsigned short int refreshRate);
		void setColorBits(const Geom::Vector<unsigned short int, 4> & colorBits);
		void setDepthBits(const unsigned short int dephtBits);
		void setStencilBits(const unsigned short int stencilBits);
		void setSamples(const unsigned short int samples);
		void setDoubleBuffering(const bool doubleBuffering);
		void setSrgbCapable(const unsigned short int srgbCapable);

		unsigned short int getRefreshRate() const;
		const Geom::Vector<unsigned short int, 4> & getColorBits() const;
		unsigned short int getDepthBits() const;
		unsigned short int getStencilBits() const;
		unsigned short int getSamples() const;
		bool isDoubleBufferingActivate() const;
		unsigned short int getSrgbCapable() const;

	private:
		unsigned short int refreshRate;
		Geom::Vector<unsigned short int, 4> colorBits;
		unsigned short int depthBits;
		unsigned short int stencilBits;
		/* Deprecated
		Geom::Vector<unsigned int, 4> accumColorBits;*/
		/* Deprecated
		unsigned short int auxBuffers;*/
		unsigned short int samples;
		bool doubleBuffering;
		unsigned short int srgbCapable;
	};
}

#endif // VIDEOMODE_HPP
