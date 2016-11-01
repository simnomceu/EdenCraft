REM Makefile project
del "./*.make"
del "./Makefile"

REM Visual Studio 2015 project
del "./*.vcxproj"
del "./*.vcxproj.filters"
del "./*.vcxproj.user"
del "./*.sln"
del "./*.VC.db"
del "./*.VC.opendb"
rd "./UxTheme.pdb/" /s /q
rd "./.vs/" /s /q

REM Code::Blocks project
del "./*.cbp"
del "./*.workspace"


timeout /t 5
