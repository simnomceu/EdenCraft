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

	includedirs { "../include" }
	libdirs { "../lib" }

project "App"
	kind "ConsoleApp"
	location ""
	files {
		"../src/App/**.cpp",
		"../include/App/**.hpp",
		"../include/App/**.inl"
	}
	links { "Core", "glew32s", "glfw3", "freeglut" }
	linkoptions { "/NODEFAULTLIB:libcmt.lib"}


project "Core"
	kind "StaticLib"
	location ""
	files {
		"../src/Core/**.cpp",
		"../include/Core/**.hpp",
		"../include/Core/**.inl"
	}
	links { "glew32s", "glfw3", "freeglut" }

project "CoreTest"
	kind "ConsoleApp"
	location ""
	files {
		"../src/CoreTest/**.cpp",
		"../include/CoreTest/**.hpp",
		"../include/CoreTest/**.inl"
	}
	links { "Core", "glew32s", "glfw3", "freeglut" }
