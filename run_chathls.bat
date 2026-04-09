@echo off
setlocal

set "ROOT_DIR=%~dp0"
if "%ROOT_DIR:~-1%"=="\" set "ROOT_DIR=%ROOT_DIR:~0,-1%"

if defined PYTHONPATH (
    set "PYTHONPATH=%ROOT_DIR%\src;%PYTHONPATH%"
) else (
    set "PYTHONPATH=%ROOT_DIR%\src"
)

python -m chathls workflow %*
set "EXIT_CODE=%ERRORLEVEL%"

endlocal & exit /b %EXIT_CODE%
