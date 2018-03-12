#!lua

-- window_testing.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("window_testing")
settings:setType("ConsoleApp")
settings:addDependencies{"window", "core", "utility"}

return settings
