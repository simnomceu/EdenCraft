#!lua

--premake5.lua
workspace "EdenCraft"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	location ""
	architecture "x86_64"
	language "C++"

	filter { "configurations:Debug" }
		symbols "Default"

	filter { "configurations:Release" }
		optimize "On"
		symbols "Off"

	filter { "x64" }
		system "Windows"
		linkoptions { "/NODEFAULTLIB:libcmt.lib", "/NODEFAULTLIB:msvcrt.lib" }

	filter { }

	includedirs { "../extlibs/include" }
	libdirs { "../extlibs/lib" }

project "App"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/App/**.cpp",
		"../examples/App/**.hpp",
		"../examples/App/**.inl"
	}
	links { "Core", "glew32s", "glfw3", "freeglut" }
	linkoptions { "/NODEFAULTLIB:libcmt.lib"}

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
	
project "Window"
	kind "StaticLib"
	location ""
	files {
		"../src/Window/**.cpp",
		"../include/Window/**.inl",
		"../include/Window/**.hpp"
	}
	includedirs { "../include/Window", "../include/Core" }
	links { "Core" }
	
project "Graphic"
	kind "StaticLib"
	location ""
	files {
		"../src/Graphic/**.cpp",
		"../include/Graphic/**.inl",
		"../include/Graphic/**.hpp"
	}
	includedirs { "../include/Graphic", "../include/Core", "../include/Window" }
	links { "Core", "Window" }
		
project "Test"
	kind "ConsoleApp"
	location ""
	files {
		"../tests/**.cpp",
		"../tests/**.hpp",
		"../tests/**.inl"
	}
	links { "Core", "glew32s", "glfw3", "freeglut" }
