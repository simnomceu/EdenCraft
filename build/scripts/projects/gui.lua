#!lua

-- gui.lua

local settings = Project:new()

settings:setName("gui")
settings:setType("Lib")
settings:addDependencies{"imgui", "graphic", "renderer", "window", "core", "utility"}
settings:setGroup("Engine")

return settings
