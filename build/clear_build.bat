REM Visual Studio project
rd "./vs2015/" /s /q
rd "./vs2017/" /s /q
rd "./vs2019/" /s /q

REM CodeLite project
rd "./codelite/" /s /q

REM Compilation files
rd "../bin/" /s /q
rd "../obj/" /s /q

REM Gmake project
rd "./gmake2/" /s /q

timeout /t 5
