#!lua

-- @module table.lua

local Table = {}

function Table.hasKey(tab, key)
    assert(type(tab) == "table", "Table.hasKey expects a table as first parameter.")
    for tmpKey, val in pairs(tab) do
        if tmpKey == key then
            return true
        end
    end
    return false
end

function Table.hasValue (tab, value)
    assert(type(tab) == "table", "Table.hasValue expects a table as first parameter.")
    for key, val in pairs(tab) do
        if val == value then
            return true
        end
    end
    return false
end

function Table.append (table1, table2)
    assert(type(table1) == "table", "Table.append expects a table as first parameter.")
    assert(type(table2) == "table", "Table.append expects a table as second parameter.")
    result = table1
    for key, value in pairs(table2) do
        if type(key) == "number" then
            table.insert(result, value)
        elseif not result[key] then
            result[key] = value
        end
    end
    return result
end

function Table.size(tab)
    assert(type(tab) == "table", "Table.size expects a table parameter.")
    local count = 0
    for key, val in pairs(tab) do
        print(val)
        count = count + 1
    end
    return count
end

function Table.print(tab)
    assert(type(tab) == "table", "Table.print expects a table parameter.")
    for key,val in pairs(tab) do
        if type(val) == "table" then
            print(key,": ")
            Table.print(val)
        else
            print(key, ": ", val)
        end
    end
end

return Table
