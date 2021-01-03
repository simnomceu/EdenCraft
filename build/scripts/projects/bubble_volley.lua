#!lua

-- bubble_volley.lua

local settings = Project:new()

settings:setName("bubble_volley")
settings:setType("ConsoleApp")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}


return settings
