/*     FILE: Student8.cpp     */

/*     FILE: Student8.cpp     */

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include "Student8.h"

long Student::count = 0;
  
Student::Student( )  // default constructor
{
  sprintf(id,"%09ld", ++count);
}

Student::Student(char * n, double g)
{
  name = new char[strlen(n)+1];
  strcpy(name,n);
  gpa = g;
  setGrade( );
  sprintf(id,"%09ld", ++count);
}
  
long Student::getCount( )
{
  return count;
}
  
const char * Student::getName( ) const
{
  return name;
}
  
char * Student::setName(const char * const name)
{  // Exercising this 
  strcpy(this->name,name);
  return this->name;
}
  
double Student::getGpa( ) const
{
  return gpa;
}
  
double Student::setGpa(double gpa)
{
  this->gpa = gpa;
  setGrade( );
  return this->gpa;
}
  
long Student::getId( ) const
{
  return atol(id);
}
  
char Student::getGrade( ) const
{
  return grade;
}
  
void Student::setGrade( )
{
  if (gpa >= 3.5)
    grade = 'A';
  else if (gpa >= 2.5)
    grade = 'B';
  else if (gpa >= 1.5)
    grade = 'C';
  else if (gpa >= 0.5)
      grade = 'D';
  else
    grade = 'F';
}

void Student::display( ) const
{
  cout << "Student name = "  << name << endl;
  cout << "Student gpa = " << gpa << endl;
  cout << "Student id = " << id << endl;
}

void Student::print( ) const
{
  cout << name << ", " << gpa << ", " << id;
}
