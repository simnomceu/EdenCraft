#!lua

-- javaquarium.lua

local settings = Project:new()

settings:setName("javaquarium")
settings:setType("ConsoleApp")
settings:addDependencies{"core", "utility"}


return settings
