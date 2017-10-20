#!lua

-- app.lua

settings = {
        name = "App",
        type = "ConsoleApp",
        dependencies = {"Utility", "Core", "Window", "Graphic", "Renderer"},
        extlibs = {"opengl32", "glew32s", "glfw3"},
        linkOptions = {
            windows = "/NODEFAULTLIB:libcmt.lib"
        }
}

return settings
