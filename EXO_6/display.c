#include <GL/glut.h>
#include <stdlib.h>

void draw_cube(){
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
      glVertex3f (0, 1, 0);
      glVertex3f (0, 1, 1);
      glVertex3f (0, 0, 1);
   glEnd();
   // Face jaune
   //
   glColor3f (1, 1, 0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (0, 0, 1);
      glVertex3f (1, 0, 1);
      glVertex3f (1, 0, 0);
   glEnd();
   // Face blanc
   //
   glColor3f (1, 1, 1);
   glBegin(GL_QUADS);
      glVertex3f (1, 0, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (1, 1, 0);
      glVertex3f (1, 0, 0);
   glEnd();
   // Face vert
   //
   glColor3f (0, 1, 0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 1);
      glVertex3f (0, 1, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (1, 0, 1);
   glEnd();
   // Face gris
   //
   glColor3f (0.3, 0.3, 0.3);
   glBegin(GL_QUADS);
      glVertex3f (0, 1, 0);
      glVertex3f (0, 1, 1);
      glVertex3f (1, 1, 1);
      glVertex3f (1, 1, 0);
   glEnd();
	
}


float xRotation = 0.0;

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glPushMatrix();

   
/* PROGRAMME A COMPLETER */   

		xRotation = xRotation+1;
		glRotatef(xRotation, 1, 0, 0);
		//glTranslatef(10,0,0);
		draw_cube();


   glPopMatrix();

   glutSwapBuffers();
}




