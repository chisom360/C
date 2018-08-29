/*  File name: makeWorld.c

    Purpose: This program creates a Karel++ World file from
             a text description of what should be in the 
             world.
    
             Karel++ Worlds are binary files stored as
             big-endian data.
             
             Format:
               <Number of horizontal walls>
               <street> <avenue>
                    ...
               <Number of vertical walls>
               <street> <avenue>
                    ...
               <Number of beeper corners>
               <street> <avenue>
               <beeper count>
                    ...
             
      Notes: The name of the Karel++ World description file 
             is expected as a command-line argument, and it 
             is also expected to end in ".txt"
                         
*/

#include <stdio.h>
#include <string.h>

unsigned int bigEndian(unsigned int x);

int main(int argc, char **argv)
{
  char outfile[128];
  
  FILE *fin, *fout;
  
  if (argc != 2)
    fprintf(stderr,"Usage: %s <worldPattern.txt>\n    - One .txt file name required\n", argv[0]);
  else if(strlen(argv[1]) < 4 || strcmp(argv[1]+strlen(argv[1])-4, ".txt") != 0) 
    fprintf(stderr,"Usage: %s <worldPattern.txt>\n    - .txt extension required\n", argv[0]);
  else{
    if(fin = fopen(argv[1], "r")){
      strncpy(outfile, argv[1], strlen(argv[1])-4);
     // printf("File: %s\n", outfile);
      strcpy(outfile+strlen(argv[1])-4, ".wld");
     // printf("File: %s\n", outfile);
      if(fout = fopen(outfile, "wb"))
        buildFile(fin, fout);
    }  
    else{
    fprintf(stderr,"Error: Unable to open file %s \n ", argv[1]);
    }
  }
  
  return 0;
}

int buildFile(FILE * fin, FILE * fout)
{
  int count;
  int st, ave, beepers;
  int i, temp[3];
  
 // printf("In buildFile\n");
  
  fscanf(fin,"%d", &count);
 // printf("Count: %d \n", count);
  temp[0] = bigEndian(count);
  fwrite(&temp,sizeof(temp[0]),1,fout);
  
  for(i=0; i<count; i++){
    fscanf(fin,"%d %d", &st, &ave);
   // printf("Read: %d %d \n", st, ave);
    temp[0] = bigEndian(ave);
    temp[1] = bigEndian(st);
    fwrite(&temp,sizeof(temp[0]),2,fout);
  }
  
  fscanf(fin,"%d", &count);
 // printf("Count: %d \n", count);
  temp[0] = bigEndian(count);
  fwrite(&temp,sizeof(temp[0]),1,fout);
  
  for(i=0; i<count; i++){
    fscanf(fin,"%d %d", &st, &ave);
   // printf("Read: %d %d \n", st, ave);
    temp[0] = bigEndian(ave);
    temp[1] = bigEndian(st);
    fwrite(&temp,sizeof(temp[0]),2,fout);
  }
  
  fscanf(fin,"%d", &count);
 // printf("Count: %d \n", count);
  temp[0] = bigEndian(count);
  fwrite(&temp,sizeof(temp[0]),1,fout);
  
  for(i=0; i<count; i++){
    fscanf(fin,"%d %d %d", &st, &ave, &beepers);
   // printf("Read: %d %d : %d\n", st, ave, beepers);
    temp[0] = bigEndian(ave);
    temp[1] = bigEndian(st);
    temp[2] = bigEndian(beepers);
    fwrite(&temp,sizeof(temp[0]),3,fout);
  }
  
  return 0;
}

unsigned int bigEndian(unsigned int x)
{
  unsigned char temp; 
  
  union{
    unsigned int x;
    unsigned char bytes[4];
  } map;
  
  map.x = x;
 // printf("Before swap: %8.8X|%2.2X%2.2X%2.2X%2.2X\n", map.x, map.bytes[0], map.bytes[1], map.bytes[2], map.bytes[3]);
  
  temp = map.bytes[0];
  map.bytes[0] = map.bytes[3];
  map.bytes[3] = temp;
  
  temp = map.bytes[1];
  map.bytes[1] = map.bytes[2];
  map.bytes[2] = temp;
  
 // printf("After swap: %8.8X\n", map.x);
  return map.x;
}