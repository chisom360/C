#     FILE: arith3.mak

# ***********************************************************
# *** A	make file to build the arithmetic array files    ****
# *** into a "current" executable.                       ****
# ***********************************************************
arith3.exe: arith3.o safe_ar.o 
		g++ -o arith3 arith3.o safe_ar.o
arith3.o: arith3.cpp safe_ar.h
		g++ -c arith3.cpp
safe_ar.o: safe_ar.cpp	safe_ar.h
		g++ -c safe_ar.cpp
