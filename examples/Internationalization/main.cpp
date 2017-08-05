#include <iostream>
#include "Locale\LocaleLoader.hpp"
#include "Locale\Country.hpp"
#include "Locale\Language.hpp"

auto main() -> int
{
	ece::LocaleLoader::setPath("../examples/Internationalization/");

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