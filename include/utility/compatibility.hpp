#ifndef UTILITY_CONFIGURATIONS_HPP
#define UTILITY_CONFIGURATIONS_HPP

#if __cplusplus >= 199711L || _MSC_VER > 1200 // C++98
#endif
#if __cplusplus >= 201103L  || _MSC_VER >= 1700  // C++11
#	define CONSTEXPR_SPECIFIER
#	define POINTER_LITERAL
#	define NOEXCEPT_SPECIFIER
#	define DEFAULT_INIT
#	define AUTO_SPECIFIER
#	define UNORDERED_CONTAINER
#endif
#if __cplusplus >= 201402L || _MSC_VER >= 1900 // C++14
#endif
#if __cplusplus >= 201703L || _MSC_VER >= 1900 // C++17
#endif
#if __cplusplus > 201703L || _MSC_VER >= 1910 // experimental
#endif

#ifndef CONSTEXPR_SPECIFIER
#	define constexpr 
#endif

#ifndef POINTER_LITERAL
#	define nullptr NULL
#endif

#ifndef NOEXCEPT_SPECIFIER
#	define noexcept throw()
#endif

#ifndef DEFAULT_INIT
#endif

#ifndef AUTO_SPECIFIER
#endif

#ifndef UNORDERED_CONTAINER
#	define unordered_map map
#	define unordered_set set
#	define unordered_multimap multimap
#	define unordered_multiset multiset
#endif




#ifdef _MSC_VER
#	undef min
#	undef max
#endif

#endif // UTILITY_CONFIGURATIONS_HPP