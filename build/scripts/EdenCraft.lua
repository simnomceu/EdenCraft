#!lua

-- eROMA.lua

local resource = Solution:new()

resource:setName("EdenCraft")
resource:setProjectsDir("scripts/projects")
resource:setOptionsDir("scripts/options")
resource:addHeaderDir{"../extlibs/OpenGL-Registry/api", "../extlibs/Catch2/single_include"}

return resource
