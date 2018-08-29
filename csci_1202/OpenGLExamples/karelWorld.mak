#     FILE: ./OpenGLExamples/karelWorld.mak

# ***********************************************************
# *** A make file to build the opengl, GLUT files and    ****
# *** display a graphical representation of a Karel++    ****
# *** world.                                             ****
# ***********************************************************
karelWorld.exe: karelWorld.o
		g++ -o karelWorld karelWorld.o  -L..\OpenGL\lib -lfreeglut -lglu32 -lopengl32 -mwindows
karelWorld.o: karelWorld.cpp
		g++ -c -I..\OpenGL\include karelWorld.cpp

