#!lua

-- core.lua

local settings = Project:new()

settings:setName("core")
settings:setType("Lib")
settings:addDependencies{"utility"}

return settings
