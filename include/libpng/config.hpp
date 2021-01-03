#ifndef LIBPNG_CONFIG_HPP
#define LIBPNG_CONFIG_HPP

#include "utility/api/dll_api.hpp"

#	ifdef ECE_libpng_SHARED
#		ifdef ECE_libpng_BUILD
#			define ECE_LIBPNG_API ECE_EXPORT
#			define ECE_LIBPNG_EXTERN
#		else
#			define ECE_LIBPNG_API ECE_IMPORT
#			define ECE_LIBPNG_EXTERN extern
#		endif
#		define ECE_LIBPNG_INTERNAL ECE_INTERNAL
#	else
#		define ECE_LIBPNG_API
#		define ECE_LIBPNG_INTERNAL
#		define ECE_LIBPNG_EXTERN
#	endif

#endif // LIBPNG_CONFIG_HPP