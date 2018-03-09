#!lua

-- project.lua

local Extlib = require "scripts/helpers/extlib"
local Table = require "scripts/helpers/table"

Project = { id = "Project"}
Project.__index = Project

function Project:new(obj)
    if(obj) then
        assert(type(obj) == "userdata" and obj.id == "Project", "Project:new expects a prototype of Project.")
    end

    local this = obj or {
        _name = "",
        _type = "",
        _dependencies = {},
        _extlibs = Extlib:new()
    }
    setmetatable(this, Project)
    self.__index = self

    return this
end

function Project:setName(name)
    assert(type(name) == "string", "Project:setName expects a string parameter.")
    self._name = name
end

function Project:getName()
    return self._name
end

function Project:setType(projectType)
    assert(type(projectType) == "string", "Project:setType expects a string parameter.")
    assert(projectType == "StaticLib" or projectType == "SharedLib" or projectType == "ConsoleApp" or projectType == "WindowedApp", "A project type expects to be one of the following: 'ConsoleApp', 'WindowedApp', 'SharedLib', 'StaticLib'.")
    self._type = projectType
end

function Project:addDependencies(dependencies)
    assert(type(dependencies) == "table", "Project:addDependencies expects a table parameter.")
    Table.append(self._dependencies, dependencies)
end

function Project:getDependencies()
    return self._dependencies
end

function Project:addExtlibs(target, extlibs)
    assert(type(target) == "string", "Project:addExtlibs expects a string parameter.")
    assert(target == "Windows" or target == "Unix" or target == "Common", "Extlibs can only be for 'Common', 'Windows', or 'Unix'.")
    assert(type(projectType) == "string", "Project:addExtlibs expects a table parameter.")
    if target == "Common" then
        self._extlibs:addCommonLibs(extlibs)
    elseif target == "Unix" then
        self._extlibs:addUnixLibs(extlibs)
    else
        self._extlibs:addWindowsLibs(extlibs)
    end
end

function Project:getExtlibs()
    return self._extlibs:getLibraries()
end

return Project
