REM Makefile project
del "./*.make"
del "./Makefile"

REM Visual Studio 2015 project
del "./*.vcxproj"
del "./*vcxproj.filters"
del "./*.sln"

REM Code::Blocks project
del "./*.cbp"
del "./*.workspace"


timeout /t 5
