@echo off

setlocal

set "_THIS_DIR=%~dp0"
set "_CORE_BUILD_DIR=%_THIS_DIR%..\build"
set "_PLATFORM=x64"

rem rmdir /S /Q %_CORE_BUILD_DIR%
mkdir %_CORE_BUILD_DIR%

pushd %_CORE_BUILD_DIR%

cmake .. -A %_PLATFORM%
msbuild /p:Configuration=Release ALL_BUILD.vcxproj

popd

endlocal
