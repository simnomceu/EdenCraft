#!lua

-- solution_builder.lua

local SolutionBuilder = {}

function SolutionBuilder.build()
    workspace "EdenCraft"
        location("./" .. _ACTION)
        includedirs { "../extlibs/OpenGL-Registry/api", "../include", "../extlibs" }
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
            buildoptions {"/MP"}

        filter {"action:gmake"}
            buildoptions {"-pedantic"}

        filter {"action:vs*", "platforms:x86"}

        filter {"action:vs*", "platforms:x64"}

        filter {}

        filter {"configurations:Debug"}
            symbols "Default"
            warnings "Extra"
            flags { "FatalWarnings" }

        filter {"configurations:Release"}
    		optimize "On"
    		symbols "Off"
            warnings "Off"

        filter {}
end

return SolutionBuilder
