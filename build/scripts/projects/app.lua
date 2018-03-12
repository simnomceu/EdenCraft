#!lua

-- app.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("app")
settings:setType("ConsoleApp")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}
settings:addExtlibs("Common", {"opengl32"})

return settings
