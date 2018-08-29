# ***********************************************************
# *** A	make file that links the opengl, GLUT files and  ****
# *** GLUI files an application depends on.              ****
# ***********************************************************
calculator1:	calculator1.o
		g++ -o calculator1.exe -L..\OpenGL\lib calculator1.o -lglui -lfreeglut -lglu32 -lopengl32 -mwindows
calculator1.o:	calculator1.cpp 
		g++ -I..\OpenGL\include -Wno-write-strings -c calculator1.cpp
