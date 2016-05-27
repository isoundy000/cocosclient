@echo off
dir *.cpp /s/b >file.txt
echo Start to replace 1...


::Cho nay la thay the chuoi lan 1
echo.
echo Start to replace 1...
set "search=%CD%"
set "replace="
set "textfile=file.txt"
set "newfile=new1.txt"

(for /f "delims=" %%i in ('findstr "^" "%textfile%"') do (
    set line=%%i
    setlocal enabledelayedexpansion
    set "line=!line:%search%=%replace%!"
    echo(!line!
    endlocal
))>"%newfile%"
type "%newfile%"


::Cho nay la thay the chuoi lan 2
echo.
echo Start to replace 2...
set "search=\"
set "replace=/"
set "textfile=new1.txt"
set "newfile=new2.txt"

(for /f "delims=" %%i in ('findstr "^" "%textfile%"') do (
    set line=%%i
    setlocal enabledelayedexpansion
    set "line=!line:%search%=%replace%!"
    echo(!line!
    endlocal
))>"%newfile%"
type "%newfile%"


::Cho nay la thay the chuoi lan 3
echo.
echo Start to replace 3...
set "search=.cpp"
set "replace=.cpp \"
set "textfile=new2.txt"
set "newfile=file.txt"

(for /f "delims=" %%i in ('findstr "^" "%textfile%"') do (
    set line=%%i
    setlocal enabledelayedexpansion
    set "line=!line:%search%=%replace%!"
    echo(!line!
    endlocal
))>"%newfile%"
type "%newfile%"
del new1.txt
del new2.txt
pause