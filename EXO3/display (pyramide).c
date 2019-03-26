#include <GL/glut.h>
#include <stdlib.h>


float xRotation = 0.0, yRotation = 0.0;
float zTranslate = -3.0;



void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glPushMatrix();


   xRotation += .75;
   yRotation += .375;


   glTranslatef(0.0, 0.0, zTranslate);
   glRotatef(xRotation, 1, 0, 0);
   glRotatef(yRotation, 0, 1, 0);
   glScalef(2.0,2.0,2.0);


   // Face rouge
   //
   glColor3f (1, 0, 0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 1, 0);
      glVertex3f (0, 1, 0);
   glEnd();
   // Face bleue
   //
   glColor3f (0, 0, 1);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (0, 0, 1);
      glVertex3f (0.5, 1, 0.5);
   glEnd();
   // Face jaune
   //
   glColor3f (1, 1, 0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 1);
      glVertex3f (1, 0, 1);
      glVertex3f (0.5, 1, 0.5);
   glEnd();
   // Face blanc
   //
   glColor3f (1, 1, 1);
   glBegin(GL_QUADS);
      glVertex3f (1, 0, 1);
      glVertex3f (1, 0, 0);
      glVertex3f (0.5, 1, 0.5);
   glEnd();
   // Face vert
   //
   glColor3f (0, 1, 0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (0.5, 1, 0.5);
   glEnd();
   
   glPopMatrix();

   glutSwapBuffers();
}




