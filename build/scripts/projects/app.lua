#!lua

-- app.lua

local settings = Project:new()

settings:setName("app")
settings:setType("ConsoleApp")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}

return settings
