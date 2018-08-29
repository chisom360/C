#     FILE: array11.mak

# ***********************************************************
# *** A make file to build the array.cpp file and the   ****
# *** files it depends on into a "current" executable.   ****
# ***********************************************************
array11.exe:         array11.o safe_ar.o 
		g++ -o array11 array11.o safe_ar.o
array11.o: array11.cpp safe_ar.h
		g++ -c array11.cpp
safe_ar.o: safe_ar.cpp  safe_ar.h
		g++ -c safe_ar.cpp
