#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <string>
#include <utility>

#include "Util\Locale\Locale.hpp"
#include "Util\Locale\ResourceContainer.hpp"

namespace ece
{
	class ResourceLoader
	{
	public:
		static void setPath(const std::string & path);

		ResourceLoader() = delete;
		ResourceLoader(const std::string & filename, const Locale & locale = Locale(ENGLISH, US));
		ResourceLoader(const ResourceLoader & copy) = default;
		ResourceLoader(ResourceLoader && move) = default;

		~ResourceLoader() = default;

		ResourceLoader & operator=(const ResourceLoader & copy) = default;
		ResourceLoader & operator=(ResourceLoader && move) = default;

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


#endif // RESOURCELOADER_HPP