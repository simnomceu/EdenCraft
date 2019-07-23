#!lua

-- bmp_loader.lua

local settings = Project:new()

settings:setName("bmp_loader")
settings:setType("ConsoleApp")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}


return settings
