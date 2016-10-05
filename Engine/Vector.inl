#include "Vector.hpp"
#pragma once

namespace Utils
{
	template<class T, unsigned short int S>
	Vector<T, S>::Vector() : std::array<T, S>()
	{
	}

	template<class T, unsigned short int S>
	Vector<T, S>::Vector(std::initializer_list<T> values) : std::array<T, S>()
	{
		int i = 0;
		for (auto it = values.begin(); it != values.end(); ++it) {
			(*this)[i] = *it;
			++i;
		}
	}

	template<class T, unsigned short int S>
	Vector<T, S>::Vector(Vector && value) : std::array<T, S>(value)
	{
	}

	template<class T, unsigned short int S>
	Vector<T, S>::~Vector()
	{
	}

	template<class T, unsigned short int S>
	Vector<T, S> & Vector<T, S>::operator=(Vector<T, S> && value)
	{
		std::array<T, S>::operator=(value);
		return *this;
	}

	template<class T, unsigned short int S>
	Vector<T, S> & Vector<T, S>::operator=(const std::initializer_list<T> values)
	{
		std::array<T, S>::operator=(values);
		return *this;
	}

	template<class T, unsigned short int S>
	Vector<T, S> Vector<T, S>::operator+(const Vector & rightOperand)
	{
		int size = rightOperand.size();
		if (this.size() == size) {
			Vector<T, S> result(rightOperand);
			for (int i = 0; i < size; ++i) {
				result[i] += (*this)[i];
			}
			return result;
		}
		else {
			throw std::exception("Two vector of different sizes cannot be added.");
		}
	}

	template<class T, unsigned short int S>
	Vector<T, S> Vector<T, S>::operator-(const Vector & rightOperand)
	{
		int size = rightOperand.size();
		if (this.size() == size) {
			Vector<T, S> result(rightOperand);
			for (int i = 0; i < size; ++i) {
				result[i] -= (*this)[i];
			}
			return result;
		}
		else {
			throw std::exception("Two vector of different sizes cannot be added.");
		}
	}

	template<class T, unsigned short int S>
	Vector<T, S> Vector<T, S>::operator-() const
	{
		int size = this->size();
		Vector<T, S> result;
		for (int i = 0; i < size; ++i) {
			result[i] = -(*this)[i];
		}
		return result;
	}

	template<class T, unsigned short int S>
	Vector<T, S> Vector<T, S>::operator*(const Vector & rightOperand)
	{
		if (this->size() == rightOperand.size()) {
			switch (this->size()) {
			case 3:
				Vector<T, 3> result;
				result[0] = (*this)[1] * rightOperand[2] - (*this)[2] * rightOperand[1];
				result[1] = (*this)[2] * rightOperand[0] - (*this)[0] * rightOperand[2];
				result[2] = (*this)[0] * rightOperand[1] - (*this)[1] * rightOperand[0];
				return result;
				break;
			case 7:
				Vector<T, 7> result;
				result[0] = (*this)[1] * rightOperand[3] - (*this)[3] * rightOperand[1]
					+ (*this)[2] * rightOperand[6] - (*this)[6] * rightOperand[2]
					+ (*this)[4] * rightOperand[5] - (*this)[5] * rightOperand[4];
				result[1] = (*this)[2] * rightOperand[4] - (*this)[4] * rightOperand[2]
					+ (*this)[3] * rightOperand[0] - (*this)[0] * rightOperand[3]
					+ (*this)[5] * rightOperand[6] - (*this)[6] * rightOperand[5];
				result[2] = (*this)[3] * rightOperand[5] - (*this)[5] * rightOperand[3]
					+ (*this)[4] * rightOperand[1] - (*this)[1] * rightOperand[4]
					+ (*this)[6] * rightOperand[0] - (*this)[0] * rightOperand[6];
				result[3] = (*this)[4] * rightOperand[6] - (*this)[6] * rightOperand[4]
					+ (*this)[5] * rightOperand[2] - (*this)[2] * rightOperand[5]
					+ (*this)[0] * rightOperand[1] - (*this)[1] * rightOperand[0];
				result[4] = (*this)[5] * rightOperand[0] - (*this)[0] * rightOperand[5]
					+ (*this)[6] * rightOperand[3] - (*this)[3] * rightOperand[6]
					+ (*this)[1] * rightOperand[2] - (*this)[2] * rightOperand[1];
				result[5] = (*this)[6] * rightOperand[1] - (*this)[1] * rightOperand[6]
					+ (*this)[0] * rightOperand[4] - (*this)[4] * rightOperand[0]
					+ (*this)[2] * rightOperand[3] - (*this)[3] * rightOperand[2];
				result[6] = (*this)[0] * rightOperand[2] - (*this)[2] * rightOperand[0]
					+ (*this)[1] * rightOperand[5] - (*this)[5] * rightOperand[1]
					+ (*this)[3] * rightOperand[4] - (*this)[4] * rightOperand[3];
				return result;
				break;
			default:
				throw std::exception("A vector of this size cannot be used in a cross product, as demonstrated by Hurwitz theorem.");
				break;
			}
		}
		else {
			throw std::exception("Two vector of different sizes cannot be multiplicated.");
		}
	}

	template<class T, unsigned short int S>
	Vector<T, S> Vector<T, S>::operator*(const T & rightOperand)
	{
		Vector<T, S> result(*this);
		for (auto it = result.begin(); it != result.end(); ++it) {
			(*it) *= rightOperand;
		}
		return result;
	}

	template<class T, unsigned short int S>
	Vector<T, S> & Vector<T, S>::operator++()
	{
		for (auto it = this->begin(); it != this->end(); ++it) {
			++(*it);
		}
		return *this;
	}

	template<class T, unsigned short int S>
	Vector<T, S> Vector<T, S>::operator++(int)
	{
		Vector<T, S> copy(*this);
		for (auto it = this->begin(); it != this->end(); ++it) {
			(*it)++;
		}
		return copy;
	}

	template<class T, unsigned short int S>
	Vector<T, S> & Vector<T, S>::operator--()
	{
		for (auto it = this->begin(); it != this->end(); ++it) {
			--(*it);
		}
		return *this;
	}

	template<class T, unsigned short int S>
	Vector<T, S> Vector<T, S>::operator--(int)
	{
		Vector<T, S> copy(*this);
		for (auto it = this->begin(); it != this->end(); ++it) {
			(*it)--;
		}
		return copy;
	}

	template<class T, unsigned short int S>
	Vector<T, S> operator* (const T & t, Vector<T, S> & v)
	{
		return v * t;
	}

	template<class T, unsigned short int S>
	std::ostream & operator<< <>(std::ostream & os, const Vector<T, S> & v)
	{
		if (S > 0) {
			std::size_t i;
			for (i = 0; i < S; ++i) os << v[i] << " ";
			os << std::endl;
		}
		else
		{
			os << "Vector is empty." << std::endl;
		}
		return os;
	}

	template<class T, unsigned short int S>
	double Vector<T, S>::norm(const unsigned short int base) const
	{
		unsigned double norm = std::accumulate(this->begin(), this->end(), 0);

		return std::pow(norm, 1.0 / base);
	}

	template<class T, unsigned short int S>
	double Vector<T, S>::uniform_norm() const
	{
		return *std::max_element(this->begin(), this->end(), [](const T element1, const T element2) -> T {
			double value1 = abs(element1);
			double value2 = abs(element2);
			if (value1 > value2) {
				return value1;
			}
			else {
				return value2;
			}
		});
	}

	template<class T, unsigned short int S>
	double Vector<T, S>::dot(const Vector<T, S> rightOperand) const
	{
		double result = 0.0;
		for (auto i = 0; i < rightOperand.size(); ++i) {
			result += (*this)[i] * rightOperand[i];
		}
		return result;
	}
}