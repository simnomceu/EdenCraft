#pragma once

#pragma warning( push )
#pragma warning( disable: 4251 )

#ifdef COMPILE_MYLIBRARY
	#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
	#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <string>

namespace cmp
{
	class MYLIBRARY_EXPORT AbstractComponent
	{
	public:
		AbstractComponent(const int ownerIn, const std::string& typeIn);
		virtual ~AbstractComponent() = 0;
		const std::string& type() const;
		const int owner() const;

	private:
		int pOwner;
		std::string pType;
	};
}

#pragma warning( pop )