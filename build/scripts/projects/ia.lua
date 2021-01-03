#!lua

-- ia.lua

local settings = Project:new()

settings:setName("ia")
settings:setType("Lib")
settings:addDependencies{"core", "utility"}
settings:setGroup("Engine")

return settings
