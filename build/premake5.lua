#!lua

-- premake5.lua

SolutionBuilder = require("scripts/solution_builder")
ProjectLoader = require("scripts/project_loader")

SolutionBuilder:build()

ProjectLoader:loadProjects()
ProjectLoader:process()
