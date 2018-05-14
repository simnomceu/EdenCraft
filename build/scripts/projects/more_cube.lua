#!lua

-- more_cube.lua

local settings = Project:new()

settings:setName("more_cube")
settings:setType("ConsoleApp")
settings:addDependencies{"renderer", "window", "core", "utility"}


return settings
