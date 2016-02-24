#pragma once

#pragma warning( push )
#pragma warning( disable: 4251 )

#ifdef COMPILE_MYLIBRARY
	#define MYLIBRARY_EXPORT __declspec(dllexport)
#else   
	#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <string>
#include <set>

namespace cmp
{
	class MYLIBRARY_EXPORT TypeComponentIndex
	{
	public:
		TypeComponentIndex();
		~TypeComponentIndex();

		void registerType(const std::string& typeIn);
		const bool contains(const std::string& typeIn) const;

	private:
		std::set<std::string> index;
	};
}

#pragma warning( pop )