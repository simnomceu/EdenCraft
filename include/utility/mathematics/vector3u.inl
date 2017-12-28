namespace ece
{
	template <>
	inline Vector<int, 3> Vector<int, 3>::cross(const Vector<int, 3> & rightOperand) const
	{
		return Vector<int, 3>{(*this)[1] * rightOperand[2] - (*this)[2] * rightOperand[1],
								(*this)[2] * rightOperand[0] - (*this)[0] * rightOperand[2],
								(*this)[0] * rightOperand[1] - (*this)[1] * rightOperand[0]};
	}

	template <>
	inline Vector<unsigned int, 3> Vector<unsigned int, 3>::cross(const Vector<unsigned int, 3> & rightOperand) const
	{
		return Vector<unsigned int, 3>{(*this)[1] * rightOperand[2] - (*this)[2] * rightOperand[1],
			(*this)[2] * rightOperand[0] - (*this)[0] * rightOperand[2],
			(*this)[0] * rightOperand[1] - (*this)[1] * rightOperand[0]};
	}

	template <>
	inline Vector<float, 3> Vector<float, 3>::cross(const Vector<float, 3> & rightOperand) const
	{
		return Vector<float, 3>{(*this)[1] * rightOperand[2] - (*this)[2] * rightOperand[1],
			(*this)[2] * rightOperand[0] - (*this)[0] * rightOperand[2],
			(*this)[0] * rightOperand[1] - (*this)[1] * rightOperand[0]};
	}

	template <>
	inline Vector<double, 3> Vector<double, 3>::cross(const Vector<double, 3> & rightOperand) const
	{
		return Vector<double, 3>{(*this)[1] * rightOperand[2] - (*this)[2] * rightOperand[1],
			(*this)[2] * rightOperand[0] - (*this)[0] * rightOperand[2],
			(*this)[0] * rightOperand[1] - (*this)[1] * rightOperand[0]};
	}
}
