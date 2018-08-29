#     FILE: mult3.mak

# ***********************************************************
# *** A	make file to build the mult3.cpp file and the	****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
mult3.exe: mult3.o combo_array.o index_array.o arith_array.o
		g++ -o mult3 mult3.o combo_array.o index_array.o arith_array.o safe_array.o
mult3.o: mult3.cpp combo_array.o
		g++ -c mult3.cpp
combo_array.o: combo_array.cpp combo_array.h
		g++ -c combo_array.cpp
index_array.o: index_array.cpp index_array.h safe_array.o
		g++ -c index_array.cpp
arith_array.o: arith_array.cpp arith_array.h safe_array.o
		g++ -c arith_array.cpp
