#!lua

-- internationalization.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("internationalization")
settings:setType("ConsoleApp")
settings:addDependencies{"utility"}

return settings
