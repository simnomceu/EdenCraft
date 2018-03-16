#!lua

-- argumentalization.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("argumentalization")
settings:setType("ConsoleApp")
settings:addDependencies{"core", "utility"}

return settings
