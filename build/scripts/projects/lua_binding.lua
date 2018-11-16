#!lua

-- lua_binding.lua

local settings = Project:new()

settings:setName("lua_binding")
settings:setType("ConsoleApp")
settings:addDependencies{"lua", "graphic", "renderer", "window", "core", "utility"}

return settings
