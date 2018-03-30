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

//	auto && result = -(7 + a + 1 + ece::Vector<int, 3>{ 1, 1, 1 }  + b - ece::Vector<int, 3>(1));
	auto resultBis = +a + c;

	ece::Vector<int, 5> test = { 1, 2, 3, 4, 5 };
	test = test.shift(3);

	std::cout << "{ ";
	for (unsigned int i = 0; i < test.size(); ++i) {
		std::cout << test[i] << " ";
	}
	std::cout << "}" << std::endl;

	return EXIT_SUCCESS;
}