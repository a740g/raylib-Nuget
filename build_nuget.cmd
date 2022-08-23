@echo off
rem Change to the correct drive letter
%~d0
rem Change to the correct path
cd %~dp0
nuget update -self
cd staging
..\nuget pack raylib.nuspec
cd ..
