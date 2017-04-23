#ifndef UNIFORM_HPP
#define UNIFORM_HPP

#include "Renderable\BaseUniform.hpp"

namespace ece
{
	template <class T>
	class Uniform: public BaseUniform
	{
	public:
		Uniform(const std::string & location, const T & data);
		Uniform() = default;
		Uniform(const Uniform & copy) = default;
		Uniform(Uniform && move) = default;

		~Uniform() = default;

		Uniform & operator=(const Uniform & copy) = default;
		Uniform & operator=(Uniform & move) = default;

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

#include "Renderable\Uniform.inl"

#endif // UNIFORM_HPP