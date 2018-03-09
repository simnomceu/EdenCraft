#!lua

-- @module table.lua

local Table = {}

 Table.hasValue = function (table, value)
    for key, val in pairs(table) do
        if val == value then
            return true
        end
    end
    return false
end

Table.append = function (table1, table2)
    assert(type(table1) == "table", "concatene expects a table as first parameter.")
    assert(type(table2) == "table", "concatene expects a table as second parameter.")
    for key, value in pairs(table2) do
        if type(key) == "number" then
            table.insert(table1, value)
        elseif not table1[key] then
            table1[key] = value
        end
    end
end

return Table
