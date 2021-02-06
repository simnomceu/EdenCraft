#!lua

-- imgui.lua

local settings = Project:new()

settings:setName("imgui")
settings:setType("Lib")
settings:addAdditionalSources { "../extlibs/imgui/*.cpp" }
settings:addAdditionalHeaders { "../extlibs/imgui/*.h" }
settings:addPreprocessors("Common", { "IMGUI_DISABLE_OBSOLETE_FUNCTIONS", "IMGUI_USER_CONFIG=\"imgui/imgui_config.hpp\"" })
settings:enablePCH(false)
settings:setGroup("Plugins")

return settings
