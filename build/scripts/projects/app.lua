#!lua

-- app.lua

settings = {
        name = "app",
        type = "ConsoleApp",
        dependencies = {"utility", "core", "window", "graphic", "renderer"},
        extlibs = {"opengl32", "glew32s"},
        linkOptions = {
            windows = "/NODEFAULTLIB:libcmt.lib"
        }
}

return settings
