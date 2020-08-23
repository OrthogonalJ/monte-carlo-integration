@echo off

setlocal

set "_THIS_DIR=%~dp0"
set "PROJECT_ROOT=%_THIS_DIR%.."

call %_THIS_DIR%build_cpp.bat

pushd %PROJECT_ROOT%\python
python setup.py build_ext --inplace
popd

endlocal
