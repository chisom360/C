h:
cd \
REM start C:\"Program Files\Mozilla Firefox"\firefox "http://otto.normandale.edu/index.html"
start chrome http://otto.normandale.edu/index.html &

start Y:\Dept\MATHCSCI\POLZIN\Lang\Dev-Cpp\devcpp

xcopy/Y Y:\dept\mathcsci\polzin\1202\notes\*.* "h:\C++\*.*" /s

start H:\C++\C++.pdf
start H:\C++\Appendix.pdf

cd \
md C++\examples
cd C++\examples
xcopy/Y "Y:\dept\mathcsci\polzin\1202\examples\*.*" h:\C++\examples /e
call setpaths.bat
call gccpath.bat
cmd.exe
