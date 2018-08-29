# ***********************************************************
# *** A	make file that links the opengl, GLUT files and  ****
# *** GLUI files an application depends on.              ****
# ***********************************************************
calculatorC.exe:	calculatorC.o COMPLEX.o
		g++ -o calculatorC.exe -L..\OpenGL\lib calculatorC.o COMPLEX.o -lglui -lfreeglut -lglu32 -lopengl32 -mwindows
calculatorC.o:	calculatorC.cpp  COMPLEX.h
		g++ -I..\OpenGL\include -Wno-write-strings -c calculatorC.cpp
COMPLEX.o:	COMPLEX.cpp COMPLEX.h
		g++ -c COMPLEX.cpp
