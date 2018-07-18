#!lua

-- lib_option.lua

local settings = Option:new()

settings:setName("Libs")
settings:setTrigger("libs")
settings:setValue("Type")
settings:setDescription("Choose to compile static or shared libraries for the engine.")
settings:setDefault("Static")
settings:addAllowed(Pair:make("Static", "Static libraries"))
settings:addAllowed(Pair:make("Shared", "Shared libraries"))

return settings
