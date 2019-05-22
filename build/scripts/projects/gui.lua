#!lua

-- gui.lua

local settings = Project:new()

settings:setName("gui")
settings:setType("Lib")
settings:addDependencies{"imgui", "renderer", "window", "core", "utility"}

return settings
