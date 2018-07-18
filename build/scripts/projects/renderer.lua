#!lua

-- renderer.lua

local settings = Project:new()

settings:setName("renderer")
settings:setType("Lib")
settings:addDependencies{"window", "core", "utility"}
settings:addExtlibs("Windows", {"opengl32"})
settings:addExtlibs("Linux", {"GL"})
settings:addExtlibs("MacOSX", {"GL"})

return settings
