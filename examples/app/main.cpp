// TODO: create another project in the solution to analize the code smell
// it could be to check if there is no more than 8-10 methods in a class (with steps: green level (? < 6), orange(6 < ? < 10) and red(? > 10)
// number of parameters by method (no more than 2-3 parameters)
// etc ....
// this could be developped using qt module at the beginning, and then, be replaced by ece designer in the future.

#include <iostream>

#include "ia/learning/teacher.hpp"

int main()
{
	ece::Epoch and{ { { {0.0, 0.0}, 0.0},
	{ {0.0, 1.0}, 0.0 },
	{ {1.0, 0.0}, 0.0 },
	{ {1.0, 1.0}, 1.0 } },
		"AND"};

	ece::Epoch or { { { {0.0, 0.0}, 0.0},
	{ { 0.0, 1.0 }, 1.0 },
	{ { 1.0, 0.0 }, 1.0 },
	{ { 1.0, 1.0 }, 1.0 } },
		"OR" };

	ece::Epoch nand{ { { {0.0, 0.0}, 1.0},
	{ { 0.0, 1.0 }, 1.0 },
	{ { 1.0, 0.0 }, 1.0 },
	{ { 1.0, 1.0 }, 0.0 } },
		"NAND"};

	ece::Epoch nor { { { {0.0, 0.0}, 1.0},
	{ { 0.0, 1.0 }, 0.0 },
	{ { 1.0, 0.0 }, 0.0 },
	{ { 1.0, 1.0 }, 0.0 } },
		"NOR" };

	ece::Epoch xor { { { {0.0, 0.0}, 0.0},
	{ { 0.0, 1.0 }, 1.0 },
	{ { 1.0, 0.0 }, 1.0 },
	{ { 1.0, 1.0 }, 0.0 } },
		"XOR" };

	ece::Epoch nxor{ { { { 0.0, 0.0 }, 1.0 },
	{ { 0.0, 1.0 }, 0.0 },
	{ { 1.0, 0.0 }, 0.0 },
	{ { 1.0, 1.0 }, 1.0 } },
		"NXOR" };

	ece::Perceptron neurone(2, 1.0, 0.5);
	ece::Teacher teacher(0.01);

	teacher.teachTo(and, neurone);
	//teacher.teachTo(or, neurone);
	//teacher.teachTo(nand, neurone);
	//teacher.teachTo(nor, neurone);
	//teacher.teachTo(xor, neurone);
	//teacher.teachTo(nxor, neurone);

	while (1) {
		std::vector<double> inputs(2);
		std::cin >> inputs[0] >> inputs[1];
		auto output = neurone.evaluate(inputs);
		std::cout << "Perceptron has evaluate the answer is :" << std::endl;
		std::cout << ">>>>>| " << std::round(output) << " |<<<<<" << std::endl;
	}

	return 0;
}