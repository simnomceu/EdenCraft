#!lua

-- crytek_sponza.lua

local settings = Project:new()

settings:setName("crytek_sponza")
settings:setType("ConsoleApp")
settings:addDependencies{"graphic", "renderer", "window", "core", "utility"}


return settings
