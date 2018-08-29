echo off
if "%1" NEQ "" GOTO DOER
  echo Usage: graphics file.wld r1.pth r2.pth ...
GOTO FINISHED
:DOER
if not exist %1 GOTO BADFILE
set filename=%1
copy %filename% "test.wld"
kpp2k %filename% > output.wol
set pathfiles=
:BUILD
SHIFT
if "%1"=="" GOTO CONVERT
set pathfiles=%pathfiles% %1
echo %pathfiles%
GOTO BUILD
:CONVERT
  kpp2ps output.wol %pathfiles% output.eps
echo  kpp2ps output.wol %pathfiles% output.eps
GOTO FINISHED
:BADFILE
  echo File %1 does not exist
:FINISHED
