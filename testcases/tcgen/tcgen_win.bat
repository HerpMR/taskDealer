
@echo off
cd /d %~dp0

rem TestCaseGenerator for Windows
rem from HerpMR

if not exist a.exe (
	gcc tcgen.c
)
a.exe
for /l %%i in (1,1,4) do (
	if not exist case_no%%i.txt (
		a.exe case_no%%i.txt
		sleep 0.75
	)
)
rm a.exe
echo Generation Completed..

