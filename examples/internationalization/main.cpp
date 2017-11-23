#include <iostream>
#include "utility/locale/locale_loader.hpp"
#include "utility/locale/country.hpp"
#include "utility/locale/language.hpp"

auto main() -> int
{
	ece::LocaleLoader::setPath("../examples/internationalization/");

	ece::LocaleLoader loader("test");
	auto & resource = loader.getResource();
	std::cout << "########## Default Locale en_US ##########" << std::endl;
	std::cout << resource["helloworld"] << std::endl;
	std::cout << resource["example"] << std::endl;

	std::cout << std::endl;

	loader.changeLocale(ece::Locale(ece::FRENCH, ece::FRANCE));
	std::cout << "########## Locale fr_FR ##########" << std::endl;
	std::cout << resource["helloworld"] << std::endl;
	std::cout << resource["example"] << std::endl;

	return EXIT_SUCCESS;
}
