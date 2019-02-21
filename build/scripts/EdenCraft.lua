#!lua

-- EdenCraft.lua

local resource = Solution:new()

resource:setName("EdenCraft")
resource:setProjectsDir("scripts/projects")
resource:setOptionsDir("scripts/options")
resource:addHeaderDir{"../extlibs/OpenGL-Registry/api", "../extlibs/Catch2/single_include"}
resource:addPreprocessorsIn({"ECE_DEBUG"}, "Debug")
resource:addPreprocessorsIn({"ECE_RELEASE"}, "Release")
resource:addPreprocessorsIn({"ECE_X64"}, "x64")
resource:addPreprocessorsIn({"ECE_X86"}, "x86")

return resource
