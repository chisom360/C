Notes on building the COMPLEX calculator:  (readme1202.txt)
-----------------------------------------------------------
Files:
  - All the files you need are in the 
            \calculator 
    and  
            \OpenGL
    directories
  - There is are 3 example files: calculator1.cpp, 
    calculator2.cpp, calculatorC.cpp. {calculatorC.cpp
    requires two other files: COMPLEX.cpp and COMPLEX.h}
    calculatorC.cpp is the file you will modify. 
    Make your changes and add your code to calculatorC.cpp.  
    {There are make files to build all 3 
     calculator*.cpp files} 
  - There is a subdirectory called archive, it contains a 
    backup copy of the examples in case you wreck the 
    originals

Building:
  - run make in the \calculator directory to 
    build each of the examples
    - Run make as:
               make  -f calculator1.mak
         or//  make  -f calculator2.mak
               make  -f calculatorC.mak
               
      (Be sure the search paths are set; run gccpaths.bat)
               
    - The executables will be calculator*.exe in the 
      calculator subdirectory

    - You can also build and run the first two examples in 
      the Dev-C++ IDE by:
       - adding the following under:
              Tools > Compiler options > 
              
          "Add the following commands when calling the compiler":
           -I..\OpenGL\include -Wno-write-strings 

          "Add the following commands when calling the linker":
           -L..\OpenGL\lib -lglui -lfreeglut -lglu32 -lopengl32 -mwindows 

Executing:
  - in the \calculator directory you can 
    run using:
              calculator1.exe
       or //  calculator2.exe
       or //  calculatorC.exe
              
  - There is a file in the \calculator directory 
    named freeglut.dll; it is required to run the 
    GLUT based programs we have written. 
        
Note:
----
  - Your work should take place in calculatorC.cpp
  - If you wreck the files there are backups in the archive
    subdirectory. And, you can always get new copies of all
    this code from otto.
