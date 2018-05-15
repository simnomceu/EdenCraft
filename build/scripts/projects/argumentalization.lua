#!lua

-- argumentalization.lua

local settings = Project:new()

settings:setName("argumentalization")
settings:setType("ConsoleApp")
settings:addDependencies{"core", "utility"}

return settings
