#ifndef LIBJPEG_CONFIG_HPP
#define LIBJPEG_CONFIG_HPP

#include "utility/api/dll_api.hpp"

#	ifdef ECE_libjpeg_SHARED
#		ifdef ECE_libjpeg_BUILD
#			define ECE_LIBJPEG_API ECE_EXPORT
#			define ECE_LIBJPEG_EXTERN
#		else
#			define ECE_LIBJPEG_API ECE_IMPORT
#			define ECE_LIBJPEG_EXTERN extern
#		endif
#		define ECE_LIBJPEG_INTERNAL ECE_INTERNAL
#	else
#		define ECE_LIBJEG_API
#		define ECE_LIBJEG_INTERNAL
#		define ECE_LIBJEG_EXTERN
#	endif

#endif // LIBJPEG_CONFIG_HPP