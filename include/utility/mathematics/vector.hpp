#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <valarray>

#ifdef _MSC_VER
	#undef min
	#undef max
#endif

namespace ece
{
	template <unsigned int Size>
	struct HasCrossProduct
	{
		static const bool value = false;
	};

	template <class T, unsigned int Size>
	class Vector : protected std::valarray<T>
	{
		static_assert(std::is_arithmetic<T>::value, "This a geometric vector, and, it can be handled only using numerical types.");

	public:
		constexpr Vector() = default;
		template <class U> inline Vector(const Vector<U, Size> & rhs);
		Vector(const std::initializer_list<T> &  il);
		Vector(const Vector<T, Size> & copy) = default;
		Vector(Vector<T, Size> && move) noexcept = default;
		inline Vector(std::valarray<T> && move);

		~Vector() = default;

		Vector<T, Size> & operator=(const Vector<T, Size> & copy) = default;
		Vector<T, Size> & operator=(Vector<T, Size> && move) noexcept = default;
		Vector<T, Size> & operator=(const std::initializer_list<T> & il);

		inline const T & operator[](const unsigned int index) const;
		inline T & operator[](const unsigned int index);
		inline Vector<T, Size> operator[](std::slice_array<T> slicearr) const;
		inline std::slice_array<T> operator[](std::slice_array<T> slicearr);
		inline Vector<T, Size> operator[](std::gslice_array<T> & gslicearr) const;
		inline std::gslice_array<T> operator[](std::gslice_array<T> & gslicearr);
		inline Vector<T, Size> operator[](const Vector<bool, Size> & maskarr) const;
//		inline std::mask_array<T> operator[](const Vector<bool, Size> & maskarr);
//		inline Vector<T, Size> operator[](const Vector<bool, Size> & indarr) const;
//		inline std::indirect_array<T> operator[](const Vector<bool, Size> & indarr);

		inline Vector<T, Size> operator+() const noexcept;
		inline Vector<T, Size> operator-() const noexcept;
		inline Vector<T, Size> operator~() const noexcept;
		inline Vector<bool, Size> operator!() const noexcept;

		inline Vector<T, Size> & operator+=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator-=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator*=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator/=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator%=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator&=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator|=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator^=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator<<=(const Vector<T, Size> & v);
		inline Vector<T, Size> & operator>>=(const Vector<T, Size> & v);

		inline Vector<T, Size> & operator+=(const T & val);
		inline Vector<T, Size> & operator-=(const T & val);
		inline Vector<T, Size> & operator*=(const T & val);
		inline Vector<T, Size> & operator/=(const T & val);
		inline Vector<T, Size> & operator%=(const T & val);
		inline Vector<T, Size> & operator&=(const T & val);
		inline Vector<T, Size> & operator|=(const T & val);
		inline Vector<T, Size> & operator^=(const T & val);
		inline Vector<T, Size> & operator<<=(const T & val);
		inline Vector<T, Size> & operator>>=(const T & val);

		using std::valarray<T>::min;
		using std::valarray<T>::max;
		using std::valarray<T>::sum;

		inline Vector<T, Size> shift(int count) const;
		inline Vector<T, Size> cshift(int count) const;
		inline Vector<T, Size> apply(T func(T)) const;
		inline Vector<T, Size> apply(T func(const T&)) const;

		inline Vector<T, Size> operator+(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator-(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator*(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator/(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator%(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator&(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator|(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator^(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator<<(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator>>(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator&&(const Vector<T, Size> & rhs) const;
		inline Vector<T, Size> operator||(const Vector<T, Size> & rhs) const;

		inline Vector<T, Size> operator+(const T & rhs) const;
		inline Vector<T, Size> operator-(const T & rhs) const;
		inline Vector<T, Size> operator*(const T & rhs) const;
		inline Vector<T, Size> operator/(const T & rhs) const;
		inline Vector<T, Size> operator%(const T & rhs) const;
		inline Vector<T, Size> operator&(const T & rhs) const;
		inline Vector<T, Size> operator|(const T & rhs) const;
		inline Vector<T, Size> operator^(const T & rhs) const;
		inline Vector<T, Size> operator<<(const T & rhs) const;
		inline Vector<T, Size> operator>>(const T & rhs) const;
		inline Vector<T, Size> operator&&(const T & rhs) const;
		inline Vector<T, Size> operator||(const T & rhs) const;

		bool operator==(const Vector<T, Size> & rhs) const;

//		Vector<bool, Size> operator==(const Vector<T, Size> & rhs);
		Vector<bool, Size> operator!=(const Vector<T, Size> & rhs);
		Vector<bool, Size> operator<(const Vector<T, Size> & rhs);
		Vector<bool, Size> operator<=(const Vector<T, Size> & rhs);
		Vector<bool, Size> operator>(const Vector<T, Size> & rhs);
		Vector<bool, Size> operator>=(const Vector<T, Size> & rhs);

		Vector<bool, Size> operator==(const T & rhs);
		Vector<bool, Size> operator!=(const T & rhs);
		Vector<bool, Size> operator<(const T & rhs);
		Vector<bool, Size> operator<=(const T & rhs);
		Vector<bool, Size> operator>(const T & rhs);
		Vector<bool, Size> operator>=(const T & rhs);

		inline Vector<T, Size> abs() const;
		inline Vector<T, Size> exp() const;
		inline Vector<T, Size> log() const;
		inline Vector<T, Size> log10() const;
		inline Vector<T, Size> pow(const Vector<T, Size> & exp) const;
		inline Vector<T, Size> pow(const T & exp) const;
		inline Vector<T, Size> sqrt() const;
		inline Vector<T, Size> sin() const;
		inline Vector<T, Size> cos() const;
		inline Vector<T, Size> tan() const;
		inline Vector<T, Size> asin() const;
		inline Vector<T, Size> acos() const;
		inline Vector<T, Size> atan() const;
		inline Vector<T, Size> atan2(const Vector<T, Size> & x) const;
		inline Vector<T, Size> atan2(const T & x) const;
		inline Vector<T, Size> sinh() const;
		inline Vector<T, Size> cosh() const;
		inline Vector<T, Size> tanh() const;

		inline void normalize();
		inline T magnitude() const;
		inline Vector<T, Size> cross(const Vector<T, Size> & rightOperand) const;
		inline T dot(const Vector<T, Size> & rightOperand) const;
		inline T distanceFrom(const Vector<T, Size> & rightOperand) const;
	};
}

#include "utility/mathematics/vector.inl"

#endif // VECTOR_HPP