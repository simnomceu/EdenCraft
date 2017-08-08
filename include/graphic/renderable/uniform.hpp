#ifndef UNIFORM_HPP
#define UNIFORM_HPP

#include "renderable\base_uniform.hpp"

namespace ece
{
	template <class T>
	class Uniform: public BaseUniform
	{
	public:
		Uniform(const std::string & location, const T & data);
		Uniform() = default;
		Uniform(const Uniform<T> & copy) = default;
		Uniform(Uniform<T> && move) = default;

		~Uniform() = default;

		Uniform<T> & operator=(const Uniform<T> & copy) = default;
		Uniform<T> & operator=(Uniform<T> && move) = default;

		virtual std::string getLocation() const override;
		virtual UniformType getType() const override;
		T getData() const;

		void setLocation(const std::string & location);
		void setData(const T & data);

	private:
		std::string location;
		T data;
	};

	template <> UniformType Uniform<int>::getType() const;
}

#include "renderable\uniform.inl"

#endif // UNIFORM_HPP