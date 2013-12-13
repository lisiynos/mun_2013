@echo off
if "%1"=="" goto Error
set TASKNAME=cord
..\run.exe /p=%1 /d=jury /i=%TASKNAME%.in /o=%TASKNAME%.out /a=a /score=true /z=2 /m=0 /r /n /y /v=check.exe
erase %TASKNAME%.in
erase %TASKNAME%.out
goto End1
:Error
echo Usage: "test <solution>.exe"
goto End1
:End1
