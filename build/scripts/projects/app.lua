#!lua

-- app.lua

settings = {
        name = "app",
        type = "ConsoleApp",
        dependencies = {"graphic", "renderer", "window", "core", "utility"},
        extlibs = {"opengl32",}
}

return settings
