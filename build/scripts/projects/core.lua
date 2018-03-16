#!lua

-- core.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("core")
settings:setType("StaticLib")
settings:addDependencies{"utility"}

return settings
