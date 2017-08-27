#!lua

-- internationalization.lua

settings = {
        name = "Internationalization",
        type = "ConsoleApp",
        dependencies = {"Utility"},
        linkOptions = {
            windows = "/NODEFAULTLIB:libcmt.lib"
        }
}

return settings
