#!lua

-- option_loader.lua

local Option = require "scripts.helpers.option"

local OptionLoader = {options = {}}

function OptionLoader:loadOptions()
    local files = os.matchfiles("scripts/options/*.lua")
    for key,file in pairs(files) do
        local name = string.gsub(string.sub(file, 1, -5), '/', '.')
        local f = require(name)
        if not f then
            print("Error while loading "..file)
        else
            OptionLoader:processOption(f)
        end
    end
end

function OptionLoader:processOption(option)
    local opt = {
        trigger = option:getTrigger(),
        description = option:getDescription(),
    }

    if option:getValue() ~= "" then
        opt.value = option:getValue()
    end

    if option:getDefault() ~= "" then
        opt.value = option:getDefault()
    end

    if option:getAllowed() ~= {} then
        opt.allowed = option:getAllowed()
    end

    newoption(opt)
end


return OptionLoader
