#!lua

-- graphic.lua

local settings = Project:new()

settings:setName("graphic")
settings:setType("Lib")
settings:addDependencies{"renderer", "window", "core", "utility"}
settings:setGroup("Engine")

return settings
