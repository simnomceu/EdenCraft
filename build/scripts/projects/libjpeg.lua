#!lua

-- libjpeg.lua

local settings = Project:new()

settings:setName("libjpeg")
settings:setType("Lib")
settings:addDependencies{"utility", "core", "renderer"}
settings:setGroup("Plugins")

return settings
