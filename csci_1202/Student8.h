/*     FILE: Student8.h     */

/*     FILE: Student8.h     */

/*
   A class to model "Student" objects.

*/
#ifndef _Student8_h
#define _Student8_h
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class Student{
    static long count;  // Keeps count of Student objects
                      // ... and generates id numbers.
    char * name;
    double gpa;
    char id[10];
    char grade;
    void setGrade( );
    
  public:
    Student( ); 
    Student(char * n, double g);

    static long getCount( );

    const char * getName( ) const;
    char * setName(char const * const);
    double getGpa( ) const;
    double setGpa(double);
    long getId( ) const;
    char getGrade( ) const;
    void display( ) const;
    void print( ) const;
};
#endif
