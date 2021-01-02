#!lua

-- more_cube.lua

local settings = Project:new()

settings:setName("particles_forever")
settings:setType("ConsoleApp")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}


return settings
