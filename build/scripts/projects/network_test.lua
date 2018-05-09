#!lua

-- network_test.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("network_test")
settings:setType("ConsoleApp")
settings:addDependencies{"core", "utility"}
settings:addExtlibs("Windows", {"Ws2_32"})


return settings
