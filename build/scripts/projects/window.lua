#!lua

-- window.lua

settings = {
        name = "window",
        type = "StaticLib",
        dependencies = {"core", "utility"},
        extlibs = {
            unix = {"xcb", "X11"}
        }
}

return settings
