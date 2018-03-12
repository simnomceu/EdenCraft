#!lua

-- @module extlib.lua

local Table = require "scripts.helpers.table"

local PlatformSpecific = { id = "PlatformSpecific"}
PlatformSpecific.__index = PlatformSpecific

function PlatformSpecific:new(obj)
    if obj then
        assert(type(obj) == "userdata" and obj.id == "PlatformSpecific", "PlatformSpecific:new expects a prototype of PlatformSpecific.")
    end

    local this = obj or {
        _common = {},
        _unix = {},
        _windows = {}
    }
    setmetatable(this, PlatformSpecific)
    self.__index = self

    return this
end

function PlatformSpecific:addCommonLibs(list)
    assert(type(list) == "table", "PlatformSpecific:addCommonLibs expects a table.")
    Table.append(self._common, list)
end

function PlatformSpecific:addUnixLibs(list)
    assert(type(list) == "table", "PlatformSpecific:addUnixLibs expects a table.")
    Table.append(self._unix, list)
end

function PlatformSpecific:addWindowsLibs(list)
    assert(type(list) == "table", "PlatformSpecific:addWindowsLibs expects a table.")
    Table.append(self._windows, list)
end

function PlatformSpecific:getLibraries()
    local result = self._common
    filter {"system:windows"}
        Table.append(result, self._windows)
    filter {"system:linux or macosx"}
        Table.append(result, self._unix)
    filter {}
    return result
end

return PlatformSpecific
