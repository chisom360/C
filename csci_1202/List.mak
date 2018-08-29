#     FILE: List.mak

# ***********************************************************
# *** A	make file to build the List.cpp file and the	 ****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
List.exe: List.o Student8.o 
		g++ -o List List.o Student8.o
List.o: List.cpp Student8.h
		g++ -c List.cpp -Wno-write-strings
Student8.o: Student8.cpp	Student8.h
		g++ -c Student8.cpp 
