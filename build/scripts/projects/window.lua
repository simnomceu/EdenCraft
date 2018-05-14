#!lua

-- window.lua

local settings = Project:new()

settings:setName("window")
settings:setType("Lib")
settings:addDependencies{"core", "utility"}
settings:addExtlibs("Linux", {"xcb", "X11"})
settings:addPreprocessors("Windows", {"X11_API", "DWM_API"})
settings:addPreprocessors("Linux", {"X11_API"})
settings:addPreprocessors("MacOSX", {"X11_API"})

return settings
