#ifndef LOCALE_HPP
#define LOCALE_HPP

#include "Util\Locale\Language.hpp"
#include "Util\Locale\Country.hpp"

namespace ece
{
	class Locale
	{
	public:
		Locale() = default;
		inline Locale(const Language & language, const Country & country);
		Locale(const Locale & copy) = default;
		Locale(Locale && move) = default;

		~Locale() = default;

		Locale & operator=(const Locale & copy) = default;
		Locale & operator=(Locale && move) = default;

		inline const Language & getLanguage() const;
		inline const Country & getCountry() const;

		inline void setLanguage(const Language & language);
		inline void setCountry(const Country & country);

	private:
		Language language;
		Country country;
	};
}

#include "Util\Locale\Locale.inl"

#endif // LOCALE_HPP