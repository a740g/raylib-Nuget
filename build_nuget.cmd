@echo off
nuget update -self
cd staging
..\nuget pack raylib.nuspec
cd ..
