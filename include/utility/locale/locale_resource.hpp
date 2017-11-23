#ifndef LOCALE_RESOURCE_HPP
#define LOCALE_RESOURCE_HPP

#include <map>
#include <string>

namespace ece
{
	class LocaleResource: protected std::map<std::string, std::string>
	{
	public:
		using std::map<std::string, std::string>::operator[];
	};
}

#endif // LOCALE_RESOURCE_HPP