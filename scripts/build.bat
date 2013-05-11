:: Build script for greebles project
:: Accepts arguments describing what is to be built and/or executed.
::
:: Options: Build All Projects
::          Build greebles
::          Build setup
::          Build custom
::          Build greebles and execute
::          Build setup and execute
::          Build custom and execute
::
:: Usage: build.bat [Game|Setup|Custom]
::                  [Debug|Release]
::                  [run] Execute if build is successful
::
:: - No arguments indicate to Build all projects in current solution configuration, no execution.

@ECHO OFF

:: Setup the visual studio environment
SET ENV_SCRIPT="C:\Program Files (x86)\Microsoft Visual Studio 11.0\Common7\Tools\VsDevCmd.bat"
CALL %ENV_SCRIPT%

:: Setup some locations for our project
SET PROJECT_DIR=C:\Users\Ben\Documents\GitHub\greebles
SET MSVC_PROJECT_DIR=%PROJECT_DIR%\msvc-projects\Greebles

SET SLN_FILE=%MSVC_PROJECT_DIR%\Greebles.sln

SET GAME_PROJECT="Game\Game.vcxproj"
SET SETUP_PROJECT="Setup\Setup.vcxproj"
SET CUSTOM_PROJECT="Custom\Custom.vcxproj"

IF "%1"=="" devenv %SLN_FILE% /Build

IF "%1"=="Game" (
    IF "%2"=="" ECHO MUST SPECIFY BUILD TARGET
    IF NOT "%2"=="" devenv %SLN_FILE% /Build %2 /Project %GAME_PROJECT%
)

IF "%1"=="Setup" (
    IF "%2"=="" ECHO MUST SPECIFY BUILD TARGET
    IF NOT "%2"=="" devenv %SLN_FILE% /Build %2 /Project %SETUP_PROJECT%
)

IF "%1"=="Custom" (
    IF "%2"=="" ECHO MUST SPECIFY BUILD TARGET
    IF NOT "%2"=="" devenv %SLN_FILE% /Build %2 /Project %CUSTOM_PROJECT%
)

IF "%3"=="run" (
    IF %ERRORLEVEL%==0 %MSVC_PROJECT_DIR%\%2\%1.exe
)
