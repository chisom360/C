#     FILE: arith2.mak

# ***********************************************************
# *** A	make file to build the arithmetic array files    ****
# *** into a "current" executable.                       ****
# ***********************************************************
arith2.exe: arith2.o safe_ar.o 
		g++ -o arith2 arith2.o safe_ar.o
arith2.o: arith2.cpp safe_ar.h
		g++ -c arith2.cpp
safe_ar.o: safe_ar.cpp	safe_ar.h
		g++ -c safe_ar.cpp
