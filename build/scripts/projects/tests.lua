#!lua

-- tests.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("tests")
settings:setType("Test")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}

return settings
