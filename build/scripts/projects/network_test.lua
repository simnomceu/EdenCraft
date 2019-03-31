#!lua

-- network_test.lua

local settings = Project:new()

settings:setName("network_test")
settings:setType("ConsoleApp")
settings:addDependencies{"core", "utility"}


return settings
