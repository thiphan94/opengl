#include <GL/glut.h>
#include <stdbool.h>
#include <stdlib.h>
float i = 0.0;
bool go_up = true; /*or false*/

float xRotation = 0.0;

void draw_cube() {
	glPushMatrix();
  glTranslatef(-0.5, -0.5, -0.5);
	xRotation = xRotation+1;
	glRotatef(xRotation, 1.0 ,0.0, 0.0);
  // Face rouge
  //
  glColor3f(1, 0, 0);
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0);
	glColor3f(1, 0.6, 0.6);
  glVertex3f(1, 1, 0);
  glVertex3f(0, 1, 0);
  glEnd();
  // Face bleue
  //
  glColor3f(0, 0, 1);
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 1, 0);
  glVertex3f(0, 1, 1);
  glVertex3f(0, 0, 1);
  glEnd();
  // Face jaune
  //
  glColor3f(1, 1, 0);
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 0, 1);
	glColor3f(1, 1, 1);
  glVertex3f(1, 0, 1);
  glVertex3f(1, 0, 0);
  glEnd();
  // Face blanc
  //
  glColor3f(1, 1, 1);
  glBegin(GL_QUADS);
  glVertex3f(1, 0, 1);
  glVertex3f(1, 1, 1);
  glVertex3f(1, 1, 0);
  glVertex3f(1, 0, 0);
  glEnd();
  // Face vert
  //
  glColor3f(0, 1, 0);
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 1);
  glVertex3f(0, 1, 1);
	glColor3f(1, 1, 0);
  glVertex3f(1, 1, 1);
  glVertex3f(1, 0, 1);
  glEnd();
  // Face gris
  //
  glColor3f(0.3, 0.3, 0.3);
  glBegin(GL_QUADS);
  glVertex3f(0, 1, 0);
  glVertex3f(0, 1, 1);
  glVertex3f(1, 1, 1);
  glVertex3f(1, 1, 0);glRotatef(xRotation, 1.0 ,0.0, 0.0);
  glEnd();

	glPopMatrix();
}

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

  glPushMatrix();

  /*PROGRAMME A COMPLETER  */


  if (!go_up) {
    glTranslatef(0,0,i);
    draw_cube();
     i = i - 0.3;
   }
   if ((i <= 0) && (!go_up)) {
     go_up = true;
   }
   if (go_up) {
     glTranslatef(0,0,i);
     draw_cube();
     i = i + 0.3;
   }
   if ((i >= 10) && (go_up)) {
     go_up = false;
   }

	

  glPopMatrix();

  glutSwapBuffers();
}
