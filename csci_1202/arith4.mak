#     FILE: arith4.mak

# ***********************************************************
# *** A	make file to build the arithmetic array files    ****
# *** into a "current" executable.                       ****
# ***********************************************************
arith4.exe: arith4.o arith_ar.o safe_ar.o
		g++ -o arith4 arith4.o arith_ar.o safe_ar.o
arith4.o: arith4.cpp arith_ar.h
		g++ -c arith4.cpp
arith_ar.o: arith_ar.cpp arith_ar.h safe_ar.h
		g++ -c arith_ar.cpp
safe_ar.o: safe_ar.cpp safe_ar.h
		g++ -c safe_ar.cpp
