#     FILE: mult4.mak

# ***********************************************************
# *** A	make file to build the mult4.cpp file and the	****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
mult4.exe: mult4.o combov_array.o indexv_array.o arithv_array.o
		g++ -o mult4 mult4.o combov_array.o indexv_array.o arithv_array.o safe_array.o
mult4.o: mult4.cpp combov_array.o
		g++ -c mult4.cpp
combov_array.o: combov_array.cpp combov_array.h
		g++ -c combov_array.cpp
indexv_array.o: indexv_array.cpp indexv_array.h safe_array.o
		g++ -c indexv_array.cpp
arithv_array.o: arithv_array.cpp arithv_array.h safe_array.o
		g++ -c arithv_array.cpp
