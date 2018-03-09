#!lua

-- @module extlib.lua

local test = require 'scripts.helpers.table'

Extlib = { id = "Extlib"}
Extlib.__index = Extlib

function Extlib:new(obj)
    if obj then
        assert(type(obj) == "userdata" and obj.id == "Extlib", "Extlib:new expects a prototype of Extlib.")
    end

    local this = obj or {
        _common = {},
        _unix = {},
        _windows = {}
    }
    setmetatable(this, Extlib)
    self.__index = self

    return this
end

function Extlib:addCommonLibs(list)
    assert(type(list) == "table", "Extlib:addCommonLibs expects a table.")
    test.concatene(self._common, list)
end

function Extlib:addUnixLibs(list)
    assert(type(list) == "table", "Extlib:addUnixLibs expects a table.")
    test.concatene(self._unix, list)
end

function Extlib:addWindowsLibs(list)
    assert(type(list) == "table", "Extlib:addWindowsLibs expects a table.")
    test.append(self._windows, list)
end

function Extlib:getLibraries()
    local result = self._common
    filter {"system:windows"}
        Table.append(result, self._windows)
    filter {"system:linux or macosx"}
        Table.append(result, self._unix)
    filter {}
    return result
end

return Extlib
