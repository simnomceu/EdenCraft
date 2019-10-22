#!lua

-- imgui_test.lua

local settings = Project:new()

settings:setName("imgui_test")
settings:setType("ConsoleApp")
settings:addDependencies{"gui", "imgui", "renderer", "window", "core", "utility"}

return settings
