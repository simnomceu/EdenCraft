#!lua

-- lib_option.lua

local Pair, Option = require "scripts.helpers.option"

local settings = Option:new()

settings:setTrigger("libs")
settings:setValue("Type")
settings:setDescription("Choose to compile static or shared libraries for the engine.")
settings:setDefault("static")
settings:addAllowed(Pair:make("static", "Static libraries"))
settings:addAllowed(Pair:make("Shared", "Shared libraries"))

return settings
