function hasValue(table, value)
    for key, val in pairs(table) do
        if val == value then
            return true
        end
    end
    return false
end
