#     FILE: ./OpenGLExamples/hatch.mak

# ***********************************************************
# *** A make file to build the opengl, GLUT files and    ****
# *** shapes7 files they depend on.                      ****
# ***********************************************************
hatch.exe: hatch.o shapes7/point.o shapes7/triangle.o shapes7/circle.o shapes7/shape.o
		g++ -o hatch -L..\OpenGL\lib hatch.o  shapes7/point.o shapes7/triangle.o shapes7/circle.o shapes7/shape.o -lfreeglut -lglu32 -lopengl32 -mwindows
hatch.o: hatch.cpp shapes7/shape.h shapes7/point.h shapes7/triangle.h shapes7/circle.h
		g++ -I..\OpenGL\include -c hatch.cpp

shapes7/shape.o: shapes7/shape.cpp shapes7/shape.h
		g++ -I..\OpenGL\include -c shapes7/shape.cpp -o shapes7/shape.o

shapes7/point.o: shapes7/point.cpp shapes7/point.h shapes7/shape.o
		g++ -I..\OpenGL\include -c shapes7/point.cpp -o shapes7/point.o

shapes7/circle.o: shapes7/circle.cpp shapes7/circle.h shapes7/shape.o shapes7/point.o 
		g++ -I..\OpenGL\include -c shapes7/circle.cpp -o shapes7/circle.o

shapes7/triangle.o: shapes7/triangle.cpp shapes7/triangle.h shapes7/point.o 
		g++ -I..\OpenGL\include -c shapes7/triangle.cpp -o shapes7/triangle.o
