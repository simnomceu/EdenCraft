#pragma once

namespace Util
{
	template<typename T>
	class Rectangle
	{
	public:
		Rectangle() = default;
		inline Rectangle(const T x, const T y, const T w, const T h);
		Rectangle(const Rectangle & copy) = default;
		Rectangle(Rectangle && copy) = default;
		~Rectangle() = default;

		Rectangle & operator=(const Rectangle & rightOperand) = default;
		Rectangle & operator=(Rectangle && rightOperand) = default;

		inline T getX() const;
		inline T getY() const;
		inline T getWidth() const;
		inline T getHeight() const;

	private:
		T x;
		T y;
		T w;
		T h;
	};
}

#include "Rectangle.inl"