#ifndef LOCALERESOURCE_HPP
#define LOCALERESOURCE_HPP

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

#endif // LOCALERESOURCE_HPP