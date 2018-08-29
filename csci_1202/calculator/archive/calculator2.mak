# ***********************************************************
# *** A	make file that links the opengl, GLUT files and  ****
# *** GLUI files an application depends on.              ****
# ***********************************************************
calculator2.exe:	calculator2.o
		g++ -o calculator2.exe -L..\OpenGL\lib calculator2.o -lglui -lfreeglut -lglu32 -lopengl32 -mwindows
calculator2.o:	calculator2.cpp 
		g++ -I..\OpenGL\include -Wno-write-strings -c calculator2.cpp
