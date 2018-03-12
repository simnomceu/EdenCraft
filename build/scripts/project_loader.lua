#!lua

-- project_loader.lua

local Table = require "scripts.helpers.table"
local Project = require "scripts.helpers.project"

local ProjectLoader = {projects = {}}

function ProjectLoader:loadProjects()
    local projects = os.matchfiles("scripts/projects/*.lua")
    for key,file in pairs(projects) do
        local name = string.gsub(string.sub(file, 1, -5), '/', '.')
        local f = require(name)
        if not f then
            print("Error while loading "..file)
        else
            print(string.lower(f:getName()));
            ProjectLoader.projects[string.lower(f:getName())] = f
        end
    end
end

function ProjectLoader:process()
    for key,proj in pairs(ProjectLoader.projects) do
        ProjectLoader:processProject(proj)
    end
end

function ProjectLoader:processProject(proj)
    local includePath, srcPath
    local projectName = string.lower(proj:getName())

    if proj:getType() == "StaticLib" then
        includePath = "../include/"..projectName
        srcPath = "../src/"..projectName
    elseif proj:getType() == "ConsoleApp" then
        includePath = "../examples/"..projectName
        srcPath = "../examples/"..projectName
	else
		includePath = "../"..projectName
		srcPath = "../"..projectName
		proj:setType("ConsoleApp")
    end

    local dependencies = ProjectLoader:GetDependencies(proj)

    project(proj:getName())
        kind(proj:getType())
        location("")
        files {
            includePath.."/**.inl",
            includePath.."/**.hpp",
            srcPath.."/**.cpp",
			srcPath.."/**.frag",
			srcPath.."/**.vert",
			srcPath.."/**.geom",
        }
		filter { "system:windows", "files:**/cocoa/** or **/x11/**" }
			flags {"ExcludeFromBuild"}
		filter { "system:linux", "files:**/cocoa/** or **/win32/**" }
			flags {"ExcludeFromBuild"}
		filter { "system:macosx", "files:**/x11/** or **/win32/**" }
			flags {"ExcludeFromBuild"}
		filter {}

        links(dependencies)

        if proj.linkOptions then
            filter {"system:windows"}
                if proj.linkOptions.windows then
                    linkoptions { proj.linkOptions.windows }
                end
            filter {"system:linux or macosx"}
                if proj.linkOptions.unix then
                    linkoptions { proj.linkOptions.unix }
                end
            filter {}
        end

	if proj.preprocessor then
		defines(proj.preprocessor)
	end
end

function ProjectLoader:GetDependencies(proj)
    local dependencies = {}
    Table:append(dependencies, proj:getExtlibs())

    Table:append(dependencies, proj:getDependencies())
    for key,dependency in pairs(proj:getDependencies()) do
        local subdependencies = ProjectLoader:GetDependencies(ProjectLoader.projects[dependency])
        for subkey,subdependency in pairs(subdependencies) do
           if not TableHelper:hasValue(dependencies, subdependency) then
                table.insert(dependencies, subdependency)
            end
        end
    end

    return dependencies
end

return ProjectLoader
