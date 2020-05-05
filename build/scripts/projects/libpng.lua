#!lua

-- libpng.lua

local settings = Project:new()

settings:setName("libpng")
settings:setType("Lib")
settings:addDependencies{"utility", "core", "renderer"}
settings:setGroup("Plugins")

return settings
