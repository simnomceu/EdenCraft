#!lua

-- app.lua

settings = {
        name = "app",
        type = "ConsoleApp",
        dependencies = {"utility", "core", "window", "renderer", "graphic"},
        extlibs = {"opengl32",}
}

return settings
