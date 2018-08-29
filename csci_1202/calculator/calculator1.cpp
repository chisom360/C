


/****************************************************************************

  calculator1.cpp

  A GLUI program with some controls to create a COMPLEX calculator
  
  Manually does only addition

  03/11/08  - Jim Polzin started it...

****************************************************************************/

#include <string.h>
#include <math.h>
#include <GL\glut.h>
#include <GL\glui.h>

#define INITIALWIDTH 465
#define INITIALHEIGHT 200


int scrWidth = INITIALWIDTH, scrHeight = INITIALHEIGHT;   /* Initial screen size */
/** These are the live variables passed into GLUI ***/
int main_window;

/** Pointers to the windows and some of the controls we'll create **/
GLUI *glui;
GLUI_EditText *real1;
GLUI_EditText *real2;
GLUI_EditText *imag1;
GLUI_EditText *imag2;

GLUI_EditText *resultReal;
GLUI_EditText *resultImag;

/********** User IDs for callbacks ********/
#define ADD_ID               201
#define SUBTRACT_ID          202
#define MULTIPLY_ID          203
#define DIVIDE_ID            204


void myinit( );          /* <- Functions written by the programmer to */
void display( );         /* ... produce the graphics they desire.     */
void reshape(int, int);  /* ... myinit( ) is called once. Display( )  */
                         /* ... and reshape( ) are called as needed.  */
              
/* Function to initialize OpenGL parameters and
   prepare for drawing as the programmer sees fit.  */
void myinit( )
{
  int tx, ty, tw, th;

  GLUI_Master.auto_set_viewport();
}
/**************************************** control_cb() *******************/
/* GLUI control callback                                                 */

void control_cb( int control )
{
  if ( control == ADD_ID )     // Manually does the addition of the COMPLEXs
  {
    resultReal->set_float_val(real1->get_float_val()+real2->get_float_val());
    resultImag->set_float_val(imag1->get_float_val()+imag2->get_float_val());
  }
}

/***************************************** display() *****************/

void display( )
{
}

void reshape( int x, int y )
{
  int tx, ty, tw, th;
  GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
  glViewport( tx, ty, tw, th );

  glutReshapeWindow(INITIALWIDTH, INITIALHEIGHT);

  glutPostRedisplay();
}

/**************************************** main() ********************/

int main(int argc, char* argv[])
{
  /****************************************/
  /*   Initialize GLUT and create window  */
  /****************************************/

  glutInit(&argc,argv);                          /* These 1st four function   */
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  /* ... calls are OpenGL/GLUT */
  glutInitWindowSize(scrWidth,scrHeight);        /* ... preparatory calls     */
  glutInitWindowPosition( 50, 50 );
 
  main_window = glutCreateWindow( "Calculator" );
  glutDisplayFunc( display );
  GLUI_Master.set_glutReshapeFunc( reshape );  
  GLUI_Master.set_glutSpecialFunc( NULL );

  myinit( );                   /* This is a local function to establish the   */

  /****************************************/
  /*         Here's the GLUI code         */
  /****************************************/

  printf( "GLUI version: %3.2f\n", GLUI_Master.get_version() );

  /*** Create the side subwindow ***/
  glui = GLUI_Master.create_glui_subwindow( main_window);

  /*** Add inputs panel w/ buttons ***/
  GLUI_Panel *panel = glui->add_panel("Inputs");
  real1 = glui->add_edittext_to_panel( panel, "real", GLUI_EDITTEXT_FLOAT);
  real2 = glui->add_edittext_to_panel( panel, "real", GLUI_EDITTEXT_FLOAT);

  glui->add_column_to_panel(panel, true );
  imag1 = glui->add_edittext_to_panel( panel, "imag", GLUI_EDITTEXT_FLOAT);
  imag2 = glui->add_edittext_to_panel( panel, "imag", GLUI_EDITTEXT_FLOAT);

  /*** Add operation panel w/ buttons ***/
  GLUI_Panel *panelC = glui->add_panel("Operations");
  glui->add_button_to_panel( panelC, "Add", ADD_ID, control_cb );
  glui->add_column_to_panel( panelC, false );
  glui->add_button_to_panel( panelC, "Subtract", SUBTRACT_ID, control_cb );
  glui->add_column_to_panel( panelC, false );
  glui->add_button_to_panel( panelC, "Multiply", MULTIPLY_ID, control_cb );
  glui->add_column_to_panel( panelC, false );
  glui->add_button_to_panel( panelC, "Divide", DIVIDE_ID, control_cb );

  /*** Add result panel ***/
  GLUI_Panel *panelR = glui->add_panel("Result:");
  resultReal = glui->add_edittext_to_panel( panelR, "real", GLUI_EDITTEXT_FLOAT);
  glui->add_column_to_panel( panelR, false );
  resultImag = glui->add_edittext_to_panel( panelR, "imag", GLUI_EDITTEXT_FLOAT);

  /****** A 'quit' button *****/
  glui->add_button( "Quit", 0,(GLUI_Update_CB)exit );


  /**** Link windows to GLUI, and register idle callback ******/
  
  glui->set_main_gfx_window( main_window );


  /**** We register the idle callback with GLUI, *not* with GLUT ****/
//  GLUI_Master.set_glutIdleFunc( myGlutIdle );

  /**** Regular GLUT main loop ****/
  
  glutMainLoop();
}

