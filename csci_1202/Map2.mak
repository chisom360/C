#     FILE: Map2.mak

# ***********************************************************
# *** A	make file to build the Map2.cpp file and the	****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
Map2.exe: Map2.o Student8.o 
		g++ -o Map2 Map2.o Student8.o
Map2.o: Map2.cpp Student8.h
		g++ -c Map2.cpp
Student8.o: Student8.cpp	Student8.h
		g++ -c Student8.cpp
