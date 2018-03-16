#!lua

-- premake5.lua

local Table = require "scripts.helpers.table"
local PlatformSpecific = require "scripts.helpers.platform_specific"
local Project = require "scripts.helpers.project"

local SolutionBuilder = require "scripts.solution_builder"
local ProjectLoader = require "scripts.project_loader"

print("Start building solution ...")
SolutionBuilder.build()
print("Start loading projects ...")
ProjectLoader:loadProjects()
print("Start processing projects ...")
ProjectLoader:process()
print("Building solution completed ...")
