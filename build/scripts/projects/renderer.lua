#!lua

-- renderer.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("renderer")
settings:setType("StaticLib")
settings:addDependencies{"window", "core", "utility"}
settings:addExtlibs("Windows", {"opengl32"})
settings:addExtlibs("Unix", {"GL"})

return settings
