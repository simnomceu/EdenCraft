#ifndef TEACHER_HPP
#define TEACHER_HPP

#include <array>
#include <vector>
#include <string>

#include "ia/neural/perceptron.hpp"

namespace ece
{
	struct Pattern
	{
		std::vector<double> inputs;
		double result;
	};

	struct Epoch
	{
		std::vector<Pattern> patterns;
		std::string name;
	};

	class Teacher
	{
	public:
		inline Teacher(const double thresholdError);
		Teacher() = delete;
		Teacher(const Teacher & copy) = default;
		Teacher(Teacher && move) = default;

		~Teacher() = default;

		Teacher & operator=(const Teacher & copy) = default;
		Teacher & operator=(Teacher && move) = default;

		void teachTo(const Epoch & epoch, Perceptron & perceptron);

	private:
		double thresholdError;
	};
}

#include "ia/learning/teacher.inl"

#endif // TEACHER_HPP
