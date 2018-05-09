#!lua

-- graphic.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("graphic")
settings:setType("Lib")
settings:addDependencies{"renderer", "window", "core", "utility"}

return settings
