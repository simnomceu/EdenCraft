#!lua

-- template_expression.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("template_expression")
settings:setType("ConsoleApp")
settings:addDependencies{"utility"}

return settings