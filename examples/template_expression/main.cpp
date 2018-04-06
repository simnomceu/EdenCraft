#include "utility/log.hpp"
#include "utility/template_expression/vector.hpp"
#include "utility/template_expression/vector_operator.hpp"

int main()
{
	ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());

	ece::Vector<int, 3> a = { 1, 5, 3 };
	a *= 2;
	ece::Vector<float, 3> b = { 2.1f, 4.5f, 7.2f };
	ece::Vector<int, 3> c = 1;

	ece::Vector<int, 3> d = { 1, -1, 2 };
	d[d > 0 && d < 2] += 1;
	d[{0, 1}] *= 10;

	std::cout << "d: { ";
	for (unsigned int i = 0; i < d.size(); ++i) {
		std::cout << d[i] << " ";
	}
	std::cout << "}" << std::endl;

	auto && result = ece::abs(-(7 + a + 1 + ece::Vector<int, 3>{ 1, 1, 1 }  + b - ece::Vector<int, 3>(1)));
	auto resultBis = +a + c;

	std::cout << "result: { ";
	for (unsigned int i = 0; i < result.size(); ++i) {
		std::cout << result[i] << " ";
	}
	std::cout << "}" << std::endl;

	return EXIT_SUCCESS;
}