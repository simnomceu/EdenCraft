#!lua

-- network_test.lua

local settings = Project:new()

settings:setName("network_test")
settings:setType("ConsoleApp")
settings:addDependencies{"network", "core", "utility"}


return settings
