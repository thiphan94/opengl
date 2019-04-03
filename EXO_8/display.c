#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

float xRotation = 0.0, yRotation = 0.0;
float zTranslate = -3.0;
float i = 0.0;
float x =0.0;
float y =0.0;

//*****fonction draw_circle****//
void draw_circle(int numSegments, GLfloat ballRadius, double z) {
  GLfloat angle;
  int i;
	glPushMatrix();
  glTranslatef(0.0, 5.0, -0.5);
  glBegin(GL_POLYGON);
  for (i = 0; i <= numSegments; i++) {
    // Last vertex same as first vertex
    if (z == 0.0) {
      glColor3f(1.0f, 1.0f, 1.0f); // blanc
    } else {
      glColor3f(1.0f, 1.0f, 0.0f); // JAUNE
    }

    angle = i * 2.0f * PI / numSegments; // 360 deg for all segments
    double a, b;
    a = cos(angle) * ballRadius;
    b = sin(angle) * ballRadius;
    glVertex3f(a, b, z);
  }
  glEnd();
	glPopMatrix();
}


//*****fonction draw_polygon****//
void draw_polygon() {
		glPushMatrix();
  	glTranslatef(-6.0, -6.0, -0.5);

	 	glColor3f (1, 1, 1);
   	glBegin(GL_LINE_LOOP);
      glVertex3f (0, 0, 0);
      glVertex3f (12, 0, 0);
      glVertex3f (12 ,12, 0);
      glVertex3f (0, 12, 0);
   		glEnd();
		glPopMatrix();

}


void display(void) {

   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
		

   glPushMatrix();

	 draw_polygon();

  if (i < 5) {
		x = i;
		y = i;
    glTranslatef(-x,-y,0.0);
	 
   draw_circle(100, 0.1*PI, 1);
	 
	 
	 i=i+0.2;
  }
	
	if (i >= 5) {
	x= 
    glTranslatef(x,-y,0.0);
	 
   draw_circle(100, 0.1*PI, 1);
	 
	 
	 i=i+0.2;
  } 
	
   glPopMatrix();


   glutSwapBuffers();
}



