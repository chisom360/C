#     FILE: array10.mak

# ***********************************************************
# *** A make file to build the array.cpp file and the   ****
# *** files it depends on into a "current" executable.   ****
# ***********************************************************
array10.exe:         array10.o safe_ar.o 
		g++ -o array10 array10.o safe_ar.o
array10.o: array10.cpp safe_ar.h
		g++ -c array10.cpp
safe_ar.o: safe_ar.cpp  safe_ar.h
		g++ -c safe_ar.cpp
