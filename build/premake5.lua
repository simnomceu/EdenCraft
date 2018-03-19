#!lua

-- premake5.lua

local Table = require "scripts.helpers.table"
local PlatformSpecific = require "scripts.helpers.platform_specific"
local Project = require "scripts.helpers.project"
-- local Pair, Option = require "scripts.helpers.option"

local SolutionBuilder = require "scripts.solution_builder"
local ProjectLoader = require "scripts.project_loader"
--local OptionLoader = require "scripts.option_loader"

print("Load CLI options ...")
--OptionLoader:loadOptions()
newoption {
    trigger = "libs",
    value = "Type",
    description = "Choose to compile static or shared libraries for the engine",
    default = "static",
    allowed = {
        { "static", "Static libraries" },
        { "Shared", "Shared libraries" }
    }
}

print("Start building solution ...")
SolutionBuilder.build()
print("Start loading projects ...")
ProjectLoader:loadProjects()
print("Start processing projects ...")
ProjectLoader:process()
print("Building solution completed ...")
