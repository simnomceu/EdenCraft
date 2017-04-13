#!lua

--premake5.lua
workspace "EdenCraft"
	configurations { "Debug", "Release" }
	platforms { "x86", "x64" }
	location ""
	language "C++"

	filter{ "platforms:x86" }
		architecture "x86"
		libdirs { "../extlibs/lib/msvc/x86" }
		
	filter { "platforms:x64" }
		architecture "x86_64"
		libdirs { "../extlibs/lib/msvc/x64" }
	
	filter { "configurations:Debug" }
		symbols "Default"

	filter { "configurations:Release" }
		optimize "On"
		symbols "Off"

	filter { "x64" }
		system "Windows"

	filter { }

	includedirs { "../extlibs/include" }

project "App"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/App/**.cpp",
		"../examples/App/**.hpp",
		"../examples/App/**.inl"
	}
	linkoptions { "/NODEFAULTLIB:libcmt.lib" }
	links { "Core", "Window", "Graphic", "opengl32", "glew32s", "glfw3" }
	includedirs { "../include/Graphic", "../include/Core", "../include/Window", "../examples/App" }
	
project "Internationalization"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/Internationalization/**.cpp",
		"../examples/Internationalization/**.hpp",
		"../examples/Internationalization/**.inl"
	}
	linkoptions { "/NODEFAULTLIB:libcmt.lib" }
	links { "Utility" }
	includedirs { "../include/Utility", "../include/examples/Internationalization" }

project "Core"
	kind "StaticLib"
	location ""
	files {
		"../src/Core/**.cpp",
		"../include/Core/**.inl",
		"../include/Core/**.hpp"
	}
	includedirs { "../include/Core" }
	links { }
	
project "Utility"
	kind "StaticLib"
	location ""
	files {
		"../src/Utility/**.cpp",
		"../include/Utility/**.inl",
		"../include/Utility/**.hpp"
	}
	includedirs { "../include/Utility" }
	links { }
	
project "Window"
	kind "StaticLib"
	location ""
	files {
		"../src/Window/**.cpp",
		"../include/Window/**.inl",
		"../include/Window/**.hpp"
	}
	includedirs { "../include/Window", "../include/Core" }
	links { }
	
project "Graphic"
	kind "StaticLib"
	location ""
	files {
		"../src/Graphic/**.cpp",
		"../include/Graphic/**.inl",
		"../include/Graphic/**.hpp"
	}
	includedirs { "../include/Graphic", "../include/Core", "../include/Window" }
	links { }
	
project "Renderer"
	kind "StaticLib"
	location ""
	files {
		"../src/Renderer/**.cpp",
		"../include/Randerer/**.inl",
		"../include/Renderer/**.hpp"
	}
	includedirs { "../include/Rendering", "../include/Core" }
	links { }
	defines { "GLEW_STATIC" }
		
project "Test"
	kind "ConsoleApp"
	location ""
	files {
		"../tests/**.cpp",
		"../tests/**.hpp",
		"../tests/**.inl"
	}
	links { }
