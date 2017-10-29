#!lua

-- tests.lua

settings = {
        name = "tests",
        type = "Test",
        dependencies = {"utility", "core", "window", "graphic", "renderer"},
        extlibs = {"opengl32", "glew32s", "glfw3"}
}

return settings
