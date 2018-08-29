/*     FILE: ./OpenGLExamples/karelWorld.cpp     */

/* Program that draws a "Karel-like" grid 
  
   With streets and avenues labeled and numbered. */

#include <stdio.h>
#include <GL/glut.h>

int scrWidth = 500, scrHeight = 500;   /* Initial screen size */
void myinit( );           /* <- Functions written by the programmer to */
void display( );          /* ... produce the graphics they desire.     */
void reshape(int, int);  /* ... myinit( ) is called once. Display( )    */
                         /* ... and reshape( ) are called as needed.   */
              
void border( );           /* ... border( ) and drawGrid( ) are called by */
void drawGrid( );         /* ... display.                              */

/* Labels each of the streets and avenues */
void numberStreetsAvenues(void *font, int pts, int st, int ave, int shift)
{
  int i, len;
  char buf[128];

  for(i=0;i<ave;i++){
    sprintf(buf,"%d",i+1);
    glRasterPos2i((i+1)*shift,-(pts+3));
    for(len=0;len<strlen(buf);len++)
      glutBitmapCharacter(font,buf[len]);
  }
  
  for(i=0;i<st;i++){
    sprintf(buf,"%d",i+1);
    glRasterPos2i(-(pts+3),(i+1)*shift);
    for(len=0;len<strlen(buf);len++)
      glutBitmapCharacter(font,buf[len]);
  }
}

/* Writes a string vertically from (x,y) down */
void verticalPrintString(void *font, char *str, int pts, int x, int y)
{
  int i, len;
  
  len=strlen(str);

  for(i=0;i<len;i++){
    glRasterPos2i(x,y-i*(pts+3));
    glutBitmapCharacter(font,*str++);
  }
}

/* Writes each character in a string */
void printString(void *font,char *str)
{
  int i, len;
  
  len=strlen(str);

  for(i=0;i<len;i++)
    glutBitmapCharacter(font,*str++);
}

/* Function to initialize OpenGL parameters and
   prepare for drawing.                          */
void myinit( )
{
  glClearColor(1.,1.,1.,1.);         /* white background */
  glColor3f(0.,0.,0.);               /* black foreground */
  glShadeModel(GL_FLAT);
  /* set up viewing scrWidth x scrHeight window with origin shifted
     up and to the right 25 pixels.                                 */
  glViewport(0,0,scrWidth,scrHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity( );
  gluOrtho2D(-25.,(GLdouble)scrWidth-25,-25.,(GLdouble)scrHeight-25);
  glMatrixMode(GL_MODELVIEW);
}
                  
/* Function registered with OpenGL for producing display */
void display( )
{
  char buf[128];
  
  glClear(GL_COLOR_BUFFER_BIT);
                 
  glLineWidth(3.0);   /* Width line-width for boundary */
  glBegin(GL_LINES);
                 
  border( );
                 
  glEnd( );
                 
  glLineWidth(1.0);   /* Small line-width for St. & Ave. */
  glBegin(GL_LINES);
                 
  drawGrid( );
                 
  glEnd( );
                 
  strcpy(buf,"Karel's World");
  glRasterPos2i(2,scrHeight-40);
  printString(GLUT_BITMAP_HELVETICA_12,buf);
  
  strcpy(buf,"Avenues");
  glRasterPos2i(scrWidth/4,-25);
  printString(GLUT_BITMAP_HELVETICA_12,buf);
  
  strcpy(buf,"Streets");
  verticalPrintString(GLUT_BITMAP_HELVETICA_12,buf,12,-25,scrHeight/2);
  
  numberStreetsAvenues(GLUT_BITMAP_HELVETICA_12,12,
                         (scrHeight-50)/25, (scrWidth-50)/25, 25);
  glFlush( );
}

/* Draw the world boundaries */
/* ... Called by display( ) to allow display( ) to be
   ... more succinct.                               */
void border( )
{
  glVertex2i(0,0);
  glVertex2i(0,scrHeight - 50);

  glVertex2i(0,0);
  glVertex2i(scrWidth - 50,0);
}

/* Draw the world boundaries */
/* ... Called by display( ) to allow display( ) to be
   ... more succinct.                               */
void drawRobot( )
{
  glVertex2i(50,150);
  glVertex2i(50 - 12,150-12);

  glVertex2i(50,150);
  glVertex2i(50 + 12,150-12);
}

/* Draw the streets and avenues */
/* ... Called by display( ) to allow display( ) to be
   ... more succinct.                               */
void drawGrid( )
{
  int i;
  
  for(i=25; i < scrHeight - 50; i+=25){
    glVertex2i(0,i);
    glVertex2i(scrWidth - 50,i);
  }
  for(i=25; i < scrWidth - 50; i+=25){
    glVertex2i(i,0);
    glVertex2i(i,scrHeight - 50);
  }
}

/* Function called when the window is reshaped. */
void reshape(int nescrWidth, int nescrHeight)
{
  scrHeight = nescrHeight;
  scrWidth = nescrWidth;
  glViewport(0,0,scrWidth,scrHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity( );
  gluOrtho2D(-25.,(GLdouble)scrWidth-25,-25.,(GLdouble)scrHeight-25);
  glMatrixMode(GL_MODELVIEW);
  display( );
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);                          /* These 1st four function   */
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  /* ... calls are OpenGL/GLUT */
  glutInitWindowSize(scrWidth,scrHeight);        /* ... preparatory calls     */
  glutCreateWindow(argv[0]);
  
  glutDisplayFunc(display);    /* <- Registers the programmers drawing code  */
                               /* ... so that the graphics can be displayed  */
                               /* ... in the window.                         */
  
  myinit( );             /* This is a local function to establish the    */
                        /* ... current state desired by the programmer. */
  
  glutReshapeFunc(reshape);     /* <- Registers the programmers drawing code  */
                                /* ... with OpenGL/GLUT so that if window is  */
                                /* ... reshaped, the graphics can be redrawn. */
                                
  glutMainLoop( );       /* Starts the event-loop for the graphics environment. */
                  
  return 0;
}



/*    OUTPUT: ./OpenGLExamples/karelWorld.cpp

	'.' is not recognized as an internal or external command,
	operable program or batch file.

*/
