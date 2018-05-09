#!lua

-- resources.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("resources")
settings:setType("ConsoleApp")
settings:addDependencies{"core", "utility"}

return settings
