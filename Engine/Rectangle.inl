#pragma once

namespace Utils
{
	template<typename T>
	inline Rectangle<T>::Rectangle(const T x, const T y, const T w, const T h) :
		x(x),
		y(y),
		w(w),
		h(h)
	{
	}

	template<typename T>
	inline T Rectangle<T>::getX() const
	{
		return this->x;
	}

	template<typename T>
	inline T Rectangle<T>::getY() const
	{
		return this->y;
	}

	template<typename T>
	inline T Rectangle<T>::getWidth() const
	{
		return this->w;
	}

	template<typename T>
	inline T Rectangle<T>::getHeight() const
	{
		return this->h;
	}
}