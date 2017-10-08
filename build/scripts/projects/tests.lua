#!lua

-- tests.lua

settings = {
        name = "Tests",
        type = "Test",
        dependencies = {"Utility", "Core", "Window", "Graphic", "Renderer"},
        extlibs = {"opengl32", "glew32s", "glfw3"}
}

return settings
