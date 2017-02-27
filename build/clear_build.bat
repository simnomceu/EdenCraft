REM Visual Studio 2015 project
del "./*.vcxproj"
del "./*.vcxproj.filters"
del "./*.vcxproj.user"
del "./*.sln"
del "./*.VC.db"
del "./*.VC.opendb"
rd "./UxTheme.pdb/" /s /q
rd "./.vs/" /s /q

REM CodeLite project
del "./*.project"
del "./*.workspace"

REM Compilation files
rd "./bin/" /s /q
rd "./obj/" /s /q

timeout /t 5
