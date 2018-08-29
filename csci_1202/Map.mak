#     FILE: Map.mak

# ***********************************************************
# *** A	make file to build the Map.cpp file and the	****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
Map.exe: Map.o Student8.o 
		g++ -o Map Map.o Student8.o
Map.o: Map.cpp Student8.h
		g++ -c Map.cpp
Student8.o: Student8.cpp	Student8.h
		g++ -c Student8.cpp
