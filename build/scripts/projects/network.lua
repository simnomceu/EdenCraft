#!lua

-- network.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("network")
settings:setType("Lib")
settings:addDependencies{"core", "utility"}

return settings
