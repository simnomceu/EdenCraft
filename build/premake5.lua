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
		"../examples/app/**.cpp",
		"../examples/app/**.hpp",
		"../examples/app/**.inl"
	}
	linkoptions { "/NODEFAULTLIB:libcmt.lib" }
	links { "opengl32", "glew32s", "Utility", "Core", "Window", "Graphic", "Renderer" }
	includedirs { "../include/utility", "../include/core", "../include/window", "../include/graphic", "../include/renderer", "../examples/app" } 
	
project "Internationalization"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/internationalization/**.cpp",
		"../examples/internationalization/**.hpp",
		"../examples/internationalization/**.inl"
	}
	linkoptions { "/NODEFAULTLIB:libcmt.lib" }
	links { "Utility" }
	includedirs { "../include/utility", "../include/examples/internationalization" }
	
project "Argumentalization"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/argumentalization/**.cpp",
		"../examples/argumentalization/**.hpp",
		"../examples/argumentalization/**.inl"
	}
	links { "Core", "Utility" }
	includedirs { "../include/core", "../include/utility", "../examples/argumentalization" }
	
project "Resources"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/resources/**.cpp",
		"../examples/resources/**.hpp",
		"../examples/resources/**.inl"
	}
	links { "Core", "Utility" }
	includedirs { "../include/core", "../include/utility", "../examples/resources" }

project "Core"
	kind "StaticLib"
	location ""
	files {
		"../src/core/**.cpp",
		"../include/core/**.inl",
		"../include/core/**.hpp"
	}
	includedirs { "../include/core", "../include/utility" }
	links { "Utility" }
	
project "Utility"
	kind "StaticLib"
	location ""
	files {
		"../src/utility/**.cpp",
		"../include/utility/**.inl",
		"../include/utility/**.hpp"
	}
	includedirs { "../include/utility" }
	links { }
	
project "Window"
	kind "StaticLib"
	location ""
	files {
		"../src/window/**.cpp",
		"../include/window/**.inl",
		"../include/window/**.hpp"
	}
	includedirs { "../include/window", "../include/utility", "../include/core" }
	links { "Utility", "Core" }
	defines { "GLEW_STATIC" }
	
project "Graphic"
	kind "StaticLib"
	location ""
	files {
		"../src/graphic/**.cpp",
		"../include/graphic/**.inl",
		"../include/graphic/**.hpp"
	}
	includedirs { "../include/graphic", "../include/utility", "../include/core", "../include/window" }
	links { "Utility", "Core", "Window" }
	
project "Renderer"
	kind "StaticLib"
	location ""
	files {
		"../src/renderer/**.cpp",
		"../include/renderer/**.inl",
		"../include/renderer/**.hpp"
	}
	includedirs { "../include/renderer", "../include/utility", "../include/core", "../include/graphic", "../include/window" }
	links { "Utility", "Core", "Graphic", "Window" }
		
project "Test"
	kind "ConsoleApp"
	location ""
	files {
		"../tests/**.cpp",
		"../tests/**.hpp",
		"../tests/**.inl"
	}
	includedirs { "../include/utility", "../include/core", "../include/graphic", "../include/window", "../include/renderer" }
	links { "Utility", "Core", "Graphic", "Window", "Renderer" }
