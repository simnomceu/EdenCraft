#ifndef BASE_UNIFORM_HPP
#define BASE_UNIFORM_HPP

namespace ece
{
	enum UniformType : unsigned short int
	{
		OTHER = 0,
		NUMERICAL = 1,
		VERTEX3 = 2,
		VERTEX4 = 3,
		MATRIX3X3 = 4,
		MATRIX4x4 = 5
	};

	class BaseUniform
	{
	public:
		BaseUniform() = default;
		BaseUniform(const BaseUniform & copy) = default;
		BaseUniform(BaseUniform && move) = default;

		~BaseUniform() = default;

		BaseUniform & operator=(const BaseUniform & copy) = default;
		BaseUniform & operator=(BaseUniform && move) = default;

		virtual std::string getLocation() const = 0;
		virtual UniformType getType() const = 0;
	};
}

#endif // BASE_UNIFORM_HPP