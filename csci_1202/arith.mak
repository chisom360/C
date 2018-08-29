#     FILE: arith.mak

# ***********************************************************
# *** A	make file to build the arithmetic array files    ****
# *** into a "current" executable.                       ****
# ***********************************************************
arith.exe: arith.o safe_ar.o 
		g++ -o arith arith.o safe_ar.o
arith.o: arith.cpp safe_ar.h
		g++ -c arith.cpp
safe_ar.o: safe_ar.cpp	safe_ar.h
		g++ -c safe_ar.cpp
