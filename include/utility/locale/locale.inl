#include <algorithm>

namespace ece
{
	inline Locale::Locale(const Language & language, const Country & country) : language(language), country(country) 
	{
		std::transform(this->country.begin(), this->country.end(), this->country.begin(), ::tolower);
	}

	inline const Language & Locale::getLanguage() const { return this->language; }

	inline const Country & Locale::getCountry() const { return this->country; }

	inline void Locale::setLanguage(const Language & language)
	{
		this->language = language;
		std::transform(this->country.begin(), this->country.end(), this->country.begin(), ::tolower);
	}

	inline void Locale::setCountry(const Country & country) { this->country = country; }
}