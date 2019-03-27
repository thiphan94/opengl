#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

float xRotation = 0.0, yRotation = 0.0;
float zTranslate = -3.0;

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
  //
  // glBegin(GL_POLYGON);
  // for (int i = 0; i < 1000; i = i + 1) {
  //   glColor3f(1.0f, 0.0f, 0.0f); // Red
  //   float a = cos(2 * 3.14159 * i / 1000.0);
  //   float b = sin(2 * 3.14159 * i / 1000.0);
  //   glBegin(GL_LINES);
  //   glColor3f(0.0f, 1.0f, 0.0f);
  //   glVertex3f(a, b, 0);
  //   glVertex3f(a, b, 1);
  //   glEnd();
  // }
  // glEnd();

  // ex

  GLfloat ballRadius = 0.5f; // Radius of the bouncing ball
  // glBegin(GL_TRIANGLE_FAN);
  // glColor3f(0.0f, 0.0f, 1.0f);  // Blue
  // glVertex3f(0.0f, 0.0f, 0.0f); // Center of circle
  int numSegments = 10;
  GLfloat angle;
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
    glColor3f(1.0f, 0.0f, 0.0f);           // Red
    // glBegin(GL_LINES);

    glColor3f(0.0f, 1.0f, 0.0f);         // Green
    angle = i * 2.0f * PI / numSegments; // 360 deg for all segments
    double a, b;
    a = cos(angle) * ballRadius;
    b = sin(angle) * ballRadius;
    glVertex3f(a, b, 0.0);
    glVertex3f(a, b, 1.0);
  }
  glEnd();
  // glEnd();

  glPopMatrix();

  glutSwapBuffers();
}
