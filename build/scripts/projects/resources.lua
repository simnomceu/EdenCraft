#!lua

-- resources.lua

local settings = Project:new()

settings:setName("resources")
settings:setType("ConsoleApp")
settings:addDependencies{"core", "utility"}

return settings
