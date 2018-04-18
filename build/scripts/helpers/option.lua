#!lua

-- option.lua

local Pair = { id = "Pair" }
Pair.__index = Pair

function Pair:new(obj)
    if obj then
        assert(type(obj) == "userdata" and obj.id == "Pair", "Pair:new expects a prototype of Pair.")
    end

    local this = obj or {
        _value = "",
        _description = ""
    }
    setmetatable(this, Pair)
    self.__index = self

    return this
end

function Pair:make(value, description)
    assert(type(value) == "string", "First parameter of Pair:make has to be a string.")
    assert(type(description) == "string", "Second parameter of Pair:make has to be a string.")

    local obj = Pair:new()
    obj._value = value
    obj._description = description

    return obj
end



local Option = { id = "Option" }
Option.__index = Option

function Option:new(obj)
    if obj then
        assert(type(obj) == "userdata" and obj.id == "Option", "Option:new expects a prototype of Option.")
    end

    local this = obj or {
        _trigger = "",
        _value = "",
        _description = "",
        _default = "",
        _allowed = {}
    }
    setmetatable(this, Option)
    self.__index = self

    return this
end

function Option:setTrigger(trigger)
    assert(type(trigger) == "string", "Option:setTrigger expects a string parameter.")
    self._trigger = trigger
end

function Option:getTrigger()
    return self._trigger
end

function Option:setValue(value)
    assert(type(value) == "string", "Option:setValue expects a string parameter.")
    self._trigger = trigger
end

function Option:getValue()
    return self._value
end

function Option:setDescription(description)
    assert(type(description) == "string", "Option:setDescription expects a string parameter.")
    self._description = description
end

function Option:getDescription()
    return self._description
end

function Option:setDefault(default)
    assert(type(default) == "string", "Option:setDefault expects a string parameter.")
    self._default = default
end

function Option:getDefault()
    return self._default
end

function Option:addAllowed(pair)
    assert(type(default) == "userdata" and pair.id == "Pair", "Option:setDefault expects a Pair parameter.")
    table.insert(self._allowed, pair)
end

function Option:getAllowed()
    return self._allowed
end

return Pair, Option
