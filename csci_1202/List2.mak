#     FILE: List2.mak

# ***********************************************************
# *** A	make file to build the List2.cpp file and the	 ****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
List2.exe: List2.o Student8.o 
		g++ -o List2 List2.o Student8.o
List2.o: List2.cpp Student8.h
		g++ -c List2.cpp -Wno-write-strings
Student8.o: Student8.cpp	Student8.h
		g++ -c Student8.cpp 
