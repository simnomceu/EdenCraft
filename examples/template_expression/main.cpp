#include "utility/log.hpp"
#include "utility/template_expression/vector.hpp"
#include "utility/template_expression/vector_operator.hpp"

int main()
{
	ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());

	ece::Vector<float, 3> a = { 1, 5, 3 };
	ece::Vector<float, 3> b = { 2, 4, 7 };

	auto result = a + b;
	auto resultBis = result + a;

	/*for (unsigned int i = 0; i < result.size(); ++i) {
		std::cout << result[i] << " " << std::endl;
	}*/

	return EXIT_SUCCESS;
}