#     FILE: mult1.mak

# ***********************************************************
# *** A	make file to build the mult1.cpp file and the	****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
mult1.exe: mult1.o safe_array.o
		g++ -o mult1 mult1.o safe_array.o
mult1.o: mult1.cpp safe_array.h
		g++ -c mult1.cpp
safe_array.o: safe_array.cpp safe_array.h
		g++ -c safe_array.cpp
