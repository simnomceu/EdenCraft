#include <iostream>
#include "locale/locale_loader.hpp"
#include "locale/country.hpp"
#include "locale/language.hpp"

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
