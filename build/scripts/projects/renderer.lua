#!lua

-- renderer.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("renderer")
settings:setType("StaticLib")
settings:addDependencies{"window", "core", "utility"}

return settings
