#     FILE: List4.mak

# ***********************************************************
# *** A	make file to build the List4.cpp file and the	 ****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
List4.exe: List4.o Student8.o 
		g++ -o List4 List4.o Student8.o
List4.o: List4.cpp Student8.h
		g++ -c List4.cpp -Wno-write-strings
Student8.o: Student8.cpp	Student8.h
		g++ -c Student8.cpp 
