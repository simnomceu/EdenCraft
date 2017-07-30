#ifndef LOCALELOADER_HPP
#define LOCALELOADER_HPP

#include <string>
#include <utility>

#include "Locale\Locale.hpp"
#include "Locale\ResourceContainer.hpp"

namespace ece
{
	class LocaleLoader
	{
	public:
		static void setPath(const std::string & path);

		LocaleLoader() = delete;
		LocaleLoader(const std::string & filename, const Locale & locale = Locale(ENGLISH, USA));
		LocaleLoader(const LocaleLoader & copy) = default;
		LocaleLoader(LocaleLoader && move) = default;

		~LocaleLoader() = default;

		LocaleLoader & operator=(const LocaleLoader & copy) = default;
		LocaleLoader & operator=(LocaleLoader && move) = default;

		LocaleResource & getResource();

		void changeLocale(const Locale & locale);

	private:
		static std::string path;

		Locale locale;
		ResourceContainer resource;
		std::string filename;

		void generateResource(const std::string & file);
	};
}


#endif // LOCALELOADER_HPP