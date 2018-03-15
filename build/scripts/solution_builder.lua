#!lua

-- solution_builder.lua

local SolutionBuilder = {}

function SolutionBuilder.build()
    workspace "EdenCraft"
        location ""
        includedirs { "../extlibs/include", "../include", "../extlibs" }
        configurations {"Debug", "Release"}
        platforms {"x86", "x64"}
    	warnings 'Extra'
        language "C++"
    	cppdialect 'C++17'

        filter {"platforms:x86"}
            architecture "x86"

        filter {"platforms:x64"}
            architecture "x86_64"

        filter {"action:vs*"}
            buildoptions {"/MP", "/W4"}

        filter {"action:gmake"}
            buildoptions {"-pedantic", "-Wall"}

        filter {"action:vs*", "platforms:x86"}
            libdirs {"../extlibs/lib/msvc/x86"}

        filter {"action:vs*", "platforms:x64"}
            libdirs {"../extlibs/lib/msvc/x64"}

        filter {}

        filter {"configurations:Debug"}
            symbols "Default"

        filter {"configurations:Release"}
    		optimize "On"
    		symbols "Off"

        filter {}
end

return SolutionBuilder
