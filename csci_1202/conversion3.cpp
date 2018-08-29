/*     FILE: conversion3.cpp     */

/* conditional - check range 
               - less redundant code */
#include <iostream>

using namespace std;

int main( )
{
  int i;
  
  int start, end;
  
  cout << "Enter a starting integer: " << flush;
  cin >> start;

  cout << "Enter an ending integer: " << flush;
  cin >> end;

  if(start > end){  
    i = start;
    start = end;
    end = i;  
  }
  
  for(i=start; i<=end ; i++)
    cout << i << " dec " << " = " << hex 
         << i << " hex " << dec << endl;

  return 0;
}


/*    OUTPUT: conversion3.cpp

	Enter a starting integer: 10
	Enter an ending integer: 25
	10 dec  = a hex 
	11 dec  = b hex 
	12 dec  = c hex 
	13 dec  = d hex 
	14 dec  = e hex 
	15 dec  = f hex 
	16 dec  = 10 hex 
	17 dec  = 11 hex 
	18 dec  = 12 hex 
	19 dec  = 13 hex 
	20 dec  = 14 hex 
	21 dec  = 15 hex 
	22 dec  = 16 hex 
	23 dec  = 17 hex 
	24 dec  = 18 hex 
	25 dec  = 19 hex 

	Enter a starting integer: 25
	Enter an ending integer: 10
	10 dec  = a hex 
	11 dec  = b hex 
	12 dec  = c hex 
	13 dec  = d hex 
	14 dec  = e hex 
	15 dec  = f hex 
	16 dec  = 10 hex 
	17 dec  = 11 hex 
	18 dec  = 12 hex 
	19 dec  = 13 hex 
	20 dec  = 14 hex 
	21 dec  = 15 hex 
	22 dec  = 16 hex 
	23 dec  = 17 hex 
	24 dec  = 18 hex 
	25 dec  = 19 hex 

*/
