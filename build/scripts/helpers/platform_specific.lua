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

function PlatformSpecific:addToCommon(list)
    assert(type(list) == "table", "PlatformSpecific:addToCommon expects a table.")
    self._common = Table.append(self._common, list)
end

function PlatformSpecific:addToUnix(list)
    assert(type(list) == "table", "PlatformSpecific:addToUnix expects a table.")
    self._unix = Table.append(self._unix, list)
end

function PlatformSpecific:addToWindows(list)
    assert(type(list) == "table", "PlatformSpecific:addToWindows expects a table.")
    self._windows = Table.append(self._windows, list)
end

function PlatformSpecific:getAll()
    local result = self._common
    if os.target() == "windows" then
        result = Table.append(result, self._windows)
    elseif os.target() == "linux" or os.target() == "macosx" then
        result = Table.append(result, self._unix)
    end
    return result
end

return PlatformSpecific
