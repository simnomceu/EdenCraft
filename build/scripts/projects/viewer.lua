#!lua

-- viewer.lua

local settings = Project:new()

settings:setName("viewer")
settings:setType("ConsoleApp")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}

return settings
