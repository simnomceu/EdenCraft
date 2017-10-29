#!lua

-- internationalization.lua

settings = {
        name = "internationalization",
        type = "ConsoleApp",
        dependencies = {"utility"},
        linkOptions = {
            windows = "/NODEFAULTLIB:libcmt.lib"
        }
}

return settings
