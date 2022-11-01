@rem NT command script to automate building Nuget packages for nuget.org
@rem Copyright (c) 2022, Samuel Gomes
@rem
@echo off

rem Enable cmd extensions and exit if not present
setlocal enableextensions
if errorlevel 1 (
    echo Error: Command Prompt extensions not available!
    goto end
)

rem Change to the correct drive letter
%~d0

rem Change to the correct path
cd %~dp0

rem Check if we have the staging directory
if not exist ".\staging\" (
    echo Error: Staging directory missing!
    goto end
)

rem Check if we have nuget.exe
if not exist ".\nuget.exe" (
    echo Error: nuget.exe missing!
    goto end
)

rem Update nuget.exe
nuget update -self

rem Delete old packages
del *.nupkg

rem Change to the staging directory
cd staging

rem Now build the package
..\nuget pack raylib.nuspec

rem Move the package to the parent directory
move *.nupkg ..

rem Go back to the parent directory
cd ..

:end
endlocal
