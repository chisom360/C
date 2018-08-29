#     FILE: List3.mak

# ***********************************************************
# *** A	make file to build the List3.cpp file and the	 ****
# *** files it depends on into a "current" executable.	 ****
# ***********************************************************
List3.exe: List3.o Student8.o 
		g++ -o List3 List3.o Student8.o
List3.o: List3.cpp Student8.h
		g++ -c List3.cpp -Wno-write-strings
Student8.o: Student8.cpp	Student8.h
		g++ -c Student8.cpp 
