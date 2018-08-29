/*  File name: dumpWorld.c

    Purpose: This program processes a Karel++ World file.
    
             It reads the integers representing the walls
             and beepers in a world and displays a listing
             of that information.
             
             The actual data is stored as big-endian data
             and is translated to little-endian by a 
             function.
             
      Notes: The name of the Karel++ World file is expected 
             as a command-line argument.
             
*/

#include <stdio.h>

unsigned int transpose(unsigned int value);

int main(int argc, char *argv[])
{
  unsigned int st, ave, beepers;
  unsigned int value, count, i;
  
  FILE* fp;
  
  if(argc == 2){   // Check for file on command line
    fp = fopen(argv[1], "rb");
    
    if (fp != NULL){   // Check for file open

      // Dump walls to north/horizontal
      fread(&value, 1, sizeof(value), fp);  
      
      count = transpose(value);    
      printf("Horizontal walls: %8.8X\n", count);
     
      for(i=0; i<count; i++){
        fread(&value, 1, sizeof(value), fp);  
        ave = transpose(value);    

        fread(&value, 1, sizeof(value), fp);  
        st = transpose(value);    
        printf("Street: %8.8X ", st);
        printf("Avenue: %8.8X ", ave);
        printf("\n");
      }

      // Dump walls to east/vertical
      fread(&value, 1, sizeof(value), fp);  
      
      count = transpose(value);    
      printf("Vertical walls: %8.8X\n", count);
      
      for(i=0; i<count; i++){
        fread(&value, 1, sizeof(value), fp);  
        ave = transpose(value);    

        fread(&value, 1, sizeof(value), fp);  
        st = transpose(value);    
        printf("Street: %8.8X ", st);
        printf("Avenue: %8.8X ", ave);
        printf("\n");
      }

      // Dump beeper corners with # on that corner
      fread(&value, 1, sizeof(value), fp);  
      
      count = transpose(value);    
      printf("Beeper corners: %8.8X\n", count);
      
      for(i=0; i<count; i++){
        fread(&value, 1, sizeof(value), fp);  
        ave = transpose(value);    

        fread(&value, 1, sizeof(value), fp);  
        st = transpose(value);    
        printf("Street: %8.8X ", st);
        printf("Avenue: %8.8X ", ave);

        fread(&value, 1, sizeof(value), fp);  
        value = transpose(value);    
        printf(" beepers: %8.8X  ", value);
        printf("\n");
      }

      fclose(fp);
    }
    else{
     printf("Unable to open file: %s\n", argv[1]);
   }
  }
  else{
    printf("Error: %s <file.wld>\n", argv[0]);
  }
}

unsigned int transpose(unsigned int value)
{
  union translate{
    unsigned int big;
    unsigned char bytes[4];
  } original, result;
  
  int i;

  original.big = value;
  
  for(i=0; i<4; i++)
    result.bytes[i] = original.bytes[3-i];
  
  return result.big;
}
