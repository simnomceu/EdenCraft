#!lua

-- project_loader.lua

local Table = require "scripts.helpers.table"
local Project = require "scripts.helpers.project"

local ProjectLoader = {projects = {}}

function ProjectLoader:loadProjects()
    local files = os.matchfiles("scripts/projects/*.lua")
    for key,file in pairs(files) do
        local name = string.gsub(string.sub(file, 1, -5), '/', '.')
        local f = require(name)
        if not f then
            print("Error while loading "..file)
        else
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

    if proj:getType() == "Lib" then
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

    project(proj:getName())
        if proj:getType() == "Lib" then
            if _OPTIONS["libs"] == "static" then
                kind "StaticLib"
            elseif _OPTIONS["libs"] == "shared" then
                kind "SharedLib"
            end
        else
            kind(proj:getType())
        end
        location("./" .. _ACTION)
        objdir "../obj/%{cfg.system}/%{cfg.buildcfg}"
        targetdir "../bin/%{cfg.system}/%{cfg.buildcfg}"
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

        links(ProjectLoader:GetDependencies(proj))

        linkoptions { proj:getLinkOptions() }
        defines { proj:getPreprocessors() }
end

function ProjectLoader:GetDependencies(proj)
    local tmpDep = proj:getExtlibs()
    tmpDep = Table.append(tmpDep, proj:getDependencies())

    for key,dependency in pairs(proj:getDependencies()) do
        if Table.hasKey(ProjectLoader.projects, dependency) == true then
            local subdependencies = ProjectLoader:GetDependencies(ProjectLoader.projects[dependency])
            for subkey,subdependency in pairs(subdependencies) do
                if not Table.hasValue(tmpDep, subdependency) then
                    table.insert(tmpDep, subdependency)
                end
            end
        end
    end

    return tmpDep
end

return ProjectLoader
