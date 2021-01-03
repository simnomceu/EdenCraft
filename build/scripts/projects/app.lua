#!lua

-- app.lua

local settings = Project:new()

settings:setName("app")
settings:setType("ConsoleApp")
settings:addDependencies{"ia", "core", "utility"}

return settings
