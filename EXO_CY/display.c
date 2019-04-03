#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

float xRotation = 0.0, yRotation = 0.0;
float zTranslate = -3.0;

//*****fonction draw_circle****//
void draw_circle(int numSegments, GLfloat ballRadius, double z) {
  GLfloat angle;
  glBegin(GL_POLYGON);
  for (int i = 0; i <= numSegments; i++) {
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
}

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  xRotation += .75;
  yRotation += .375;

  glTranslatef(0.0, 0.0, zTranslate);
  glRotatef(xRotation, 1, 0, 0);
  glRotatef(yRotation, 0, 1, 0);
  glScalef(2.0, 2.0, 2.0);

  // Declaration
  GLfloat ballRadius = 0.5f; // Radius of the bouncing ball

  int numSegments = 1000;
  GLfloat angle;
  for (int k = 0; k <= numSegments; k++) {
    // Last vertex same as first vertex

    glColor3f(0.0f, 0.0f, 1.0f); // Blue

    angle = k * 2.0f * PI / numSegments; // 360 deg for all segments
    double a, b;
    a = cos(angle) * ballRadius;
    b = sin(angle) * ballRadius;
    glBegin(GL_LINES);
    glVertex3f(a, b, 0.0);
    glVertex3f(a, b, 1.0);
    glEnd();
  }

  draw_circle(numSegments, ballRadius, 0.0);
  draw_circle(numSegments, ballRadius, 1.0);
  glPopMatrix();

  glutSwapBuffers();
}
