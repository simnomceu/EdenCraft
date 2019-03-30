#!lua

-- window_testing.lua

local settings = Project:new()

settings:setName("window_testing")
settings:setType("ConsoleApp")
settings:addDependencies{"window", "core", "utility"}

return settings
