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


   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(0.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 0.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, 0.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(0.5f, 1.0f, 0.5f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(1.0f, 0.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, 0.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(0.5f, 1.0f, 0.5f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(1.0f, 0.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(0.0f, 0.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(0.5f, 1.0f, 0.5f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 0.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(0.0f,0.0f,1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(0.5f, 1.0f, 0.5f);
   glEnd();   // Done drawing the pyramid
   
   


   glPopMatrix();

   glutSwapBuffers();
}




