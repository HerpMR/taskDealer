
@echo off
cd /d %~dp0

rem TestCaseGenerator for Windows
rem from herpMR

for /l %%i in (1,1,4) do (
	if not exist case_no%%i.txt (
		tcgen.exe case_no%%i.txt
		sleep 0.75
	)
)
echo Generation Completed..
