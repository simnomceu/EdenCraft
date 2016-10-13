#!lua
--premake4.lua
solution "EdenCraft"
	configurations { "Debug", "Release" }
	platforms { "Universal64" }
	location ""
	language "c++"

	configuration  "Debug"
		flags { "Symbols" }

	configuration "Release"
		flags { "Optimize" }

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
	links { "core", "glew32", "glfw3", "freeglut" }


project "Core"
	kind "StaticLib"
	location ""
	files {
		"../src/Core/**.cpp",
		"../include/Core/**.hpp",
		"../include/Core/**.inl"
	}
	links { "glew32", "glfw3", "freeglut" }
