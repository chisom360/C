#     FILE: mult2.mak

# ***********************************************************
# *** A	make file to build the mult2.cpp file and the	****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
mult2.exe: mult2.o safe_array.o index_array.o
		g++ -o mult2 mult2.o safe_array.o index_array.o
mult2.o: mult2.cpp safe_array.h
		g++ -c mult2.cpp
safe_array.o: safe_array.cpp safe_array.h
		g++ -c safe_array.cpp
index_array.o: index_array.cpp index_array.h safe_array.o
		g++ -c index_array.cpp
