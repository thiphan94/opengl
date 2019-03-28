#include <GL/glut.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void display(void) {

   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glEnable (GL_DEPTH_TEST);
   glPushMatrix();

 
   glPopMatrix();
   glutSwapBuffers();
}




