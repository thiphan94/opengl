#include <GL/glut.h>
#include <stdlib.h>


float xRotation = 0.0;



void display(void) {

   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   xRotation = xRotation+2;
   glRotatef(xRotation, 1, 0, 0);

   glColor3f (1, 0, 0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 1, 0);
      glVertex3f (0, 1, 0);
   glEnd();

   glutSwapBuffers();
}



