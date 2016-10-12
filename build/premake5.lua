#!lua

--premake5.lua
workspace "EdenCraft"
	configurations { "Debug", "Release" }
	platforms { "Win64", "Lnx64" }
	location ""
	architecture "x86_64"
	language "c++"

	filter { "configurations:Debug" }
		symbols "On"

	filter { "configurations:Release" }
		optimize "On"

	filter { "platforms:Win64" }
		system "Windows"
	
	filter { "platforms:Lnx64" }
		system "Linux"

	filter { }

project "App"
	kind "ConsoleApp"
	location ""
	files {
		"../src/App/**.cpp",
		"../include/App/**.hpp",
		"../include/App/**.inl"
	}


project "Core"
	kind "StaticLib"
	location ""
	files {
		"../src/Core/**.cpp",
		"../include/Core/**.hpp",
		"../include/Core/**.inl"
	}
