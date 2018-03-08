#!lua

-- window_testing.lua

settings = {
        name = "window_testing",
        type = "ConsoleApp",
        dependencies = {"window", "core", "utility"},
        extlibs = {
            unix = {"xcb", "X11"}
        }
}

return settings
