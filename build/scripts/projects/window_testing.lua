#!lua

-- window_testing.lua

settings = {
        name = "window_testing",
        type = "ConsoleApp",
        dependencies = {"utility", "core", "window"},
        extlibs = {"opengl32", "glew32s"},
        linkOptions = {
            windows = "/NODEFAULTLIB:libcmt.lib"
        }
}

return settings
