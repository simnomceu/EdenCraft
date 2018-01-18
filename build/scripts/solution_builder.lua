#!lua

-- solution_builder.lua

SolutionBuilder = {}

function SolutionBuilder:build()
    workspace "EdenCraft"
        language "C++"
        location ""
        includedirs { "../extlibs/include", "../include", "../extlibs" }
        configurations {"Debug", "Release"}
        platforms {"Win32", "Win64", "Unix32", "Unix64", "OSX"}
		warnings 'Extra'
		cppdialect 'C++17'

        filter {"platforms:Win32"}
            architecture "x86"
            system "windows"
            libdirs {"../extlibs/lib/msvc/x86"}
			buildoptions {"/MP"}

        filter {"platforms:Win64"}
            architecture "x86_64"
            system "windows"
            libdirs {"../extlibs/lib/msvc/x64"}
			buildoptions {"/MP"}

        filter {"platforms:Unix32"}
            architecture "x86"
            system "linux"
            libdirs {"../extlibs/lib/gmake/x32"}
			buildoptions {"-ansi", "-pedantic"}

        filter {"platforms:Unix64"}
            architecture "x86_64"
            system "linux"
            libdirs {"../extlibs/lib/gmake/x64"}
			buildoptions {"-ansi", "-pedantic"}

        filter {"platforms:OSX"}
            architecture "x86_64"
            system "macosx"
            libdirs {"../extlibs/lib/gmake/x64"}
			buildoptions {"-std=c++17", "-ansi", "-pedantic"}

        filter {"configurations:Debug"}
            symbols "Default"

        filter {"configurations:Release"}
    		optimize "On"
    		symbols "Off"

        filter {}
end

return SolutionBuilder
