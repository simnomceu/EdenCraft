#!lua

-- more_cube.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("more_cube")
settings:setType("ConsoleApp")
settings:addDependencies{"renderer", "window", "core", "utility"}
settings:addExtlibs("Windows", {"opengl32"})


return settings
