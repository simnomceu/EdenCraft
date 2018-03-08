#!lua

-- project_loader.lua

TableHelper = require("scripts/helpers/table")

ProjectLoader = {projects = {}}

function ProjectLoader:loadProjects()
    local projects = os.matchfiles("scripts/projects/*.lua")
    for key,file in pairs(projects) do
        local f = require(string.sub(file, 1, -5))
        local err = false
        if not f then
            print("Error while loading "..file)
            err = true
        end
        if f.name == nil then
          print("the project name field is not correct in "..file)
          err = true
        end
        if f.type == nil or (f.type ~= "StaticLib" and f.type ~= "ConsoleApp" and f.type ~= "Test") then
          print("the project type field is not correct in "..file)
          err = true
        end
        if not err then
            print(string.lower(f.name));
            ProjectLoader.projects[string.lower(f.name)] = f
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
    local projectName = string.lower(proj.name)

    if proj.type == "StaticLib" then
        includePath = "../include/"..projectName
        srcPath = "../src/"..projectName
    elseif proj.type == "ConsoleApp" then
        includePath = "../examples/"..projectName
        srcPath = "../examples/"..projectName
	else
		includePath = "../"..projectName
		srcPath = "../"..projectName
		proj.type = "ConsoleApp"
    end

    local dependencies = GetDependencies(proj)

    project(proj.name)
        kind(proj.type)
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

function GetDependencies(proj)
    local dependencies = {}
    if proj.extlibs then
        if proj.extlibs.common then
            for key,extlib in pairs(proj.extlibs.common) do
                table.insert(dependencies, extlib)
            end
        end
        filter {"system:windows"}
            if proj.extlibs.windows then
                for key,extlib in pairs(proj.extlibs.windows) do
                    table.insert(dependencies, extlib)
                end
            end
        filter {"system:linux or macosx"}
            if proj.extlibs.unix then
                for key,extlib in pairs(proj.extlibs.unix) do
                    table.insert(dependencies, extlib)
                end
            end
        filter {}
    end
    if proj.dependencies then
        for key,dependency in pairs(proj.dependencies) do
            table.insert(dependencies, dependency)
            local subdependencies = GetDependencies(ProjectLoader.projects[dependency])
            for subkey,subdependency in pairs(subdependencies) do
               if not hasValue(dependencies, subdependency) then
                    table.insert(dependencies, subdependency)
                end
            end
        end
    end
    return dependencies
end

return ProjectLoader
