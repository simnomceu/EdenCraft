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
	links { "opengl32", "glew32s", "glfw3", "Utility", "Core", "Window", "Graphic", "Renderer" }
	includedirs { "../include/Utility", "../include/Core", "../include/Window", "../include/Graphic", "../include/Renderer", "../examples/App" } 
	
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
	
project "Argumentalization"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/Argumentalization/**.cpp",
		"../examples/Argumentalization/**.hpp",
		"../examples/Argumentalization/**.inl"
	}
	links { "Core", "Utility" }
	includedirs { "../include/Core", "../include/Utility", "../examples/Argumentalization" }
	
project "Resources"
	kind "ConsoleApp"
	location ""
	files {
		"../examples/Resources/**.cpp",
		"../examples/Resources/**.hpp",
		"../examples/Resources/**.inl"
	}
	links { "Core", "Utility" }
	includedirs { "../include/Core", "../include/Utility", "../examples/Resources" }

project "Core"
	kind "StaticLib"
	location ""
	files {
		"../src/Core/**.cpp",
		"../include/Core/**.inl",
		"../include/Core/**.hpp"
	}
	includedirs { "../include/Core", "../include/Utility" }
	links { "Utility" }
	defines { "GLEW_STATIC" }
	
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
	includedirs { "../include/Window", "../include/Utility", "../include/Core" }
	links { "Utility", "Core" }
	
project "Graphic"
	kind "StaticLib"
	location ""
	files {
		"../src/Graphic/**.cpp",
		"../include/Graphic/**.inl",
		"../include/Graphic/**.hpp"
	}
	includedirs { "../include/Graphic", "../include/Utility", "../include/Core", "../include/Window" }
	links { "Utility", "Core", "Window" }
	
project "Renderer"
	kind "StaticLib"
	location ""
	files {
		"../src/Renderer/**.cpp",
		"../include/Renderer/**.inl",
		"../include/Renderer/**.hpp"
	}
	includedirs { "../include/Renderer", "../include/Utility", "../include/Core", "../include/Graphic", "../include/Window" }
	links { "Utility", "Core", "Graphic", "Window" }
		
project "Test"
	kind "ConsoleApp"
	location ""
	files {
		"../tests/**.cpp",
		"../tests/**.hpp",
		"../tests/**.inl"
	}
	links { }
