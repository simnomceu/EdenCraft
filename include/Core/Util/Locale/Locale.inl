namespace ece
{
	inline Locale::Locale(const Language & language, const Country & country) : language(language), country(country) {}

	inline const Language & Locale::getLanguage() const { return this->language; }

	inline const Country & Locale::getCountry() const { return this->country; }

	inline void Locale::setLanguage(const Language & language) { this->language = language; }

	inline void Locale::setCountry(const Country & country) { this->country = country; }
}