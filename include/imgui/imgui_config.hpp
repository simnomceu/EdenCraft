#ifndef IMGUI_CONFIG_HPP
#define IMGUI_CONFIG_HPP

#include "utility/api/dll_api.hpp"

#	ifdef ECE_imgui_SHARED
#		ifdef ECE_imgui_BUILD
#			define ECE_IMGUI_API ECE_EXPORT
#			define ECE_IMGUI_EXTERN
#		else
#			define ECE_IMGUI_API ECE_IMPORT
#			define ECE_IMGUI_EXTERN extern
#		endif
#		define ECE_IMGUI_INTERNAL ECE_INTERNAL
#	else
#		define ECE_IMGUI_API
#		define ECE_IMGUI_INTERNAL
#		define ECE_IMGUI_EXTERN
#	endif

#define IMGUI_API ECE_IMGUI_API

#endif // IMGUI_CONFIG_HPP