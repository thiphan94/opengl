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
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glBegin(GL_POINTS);
  for (int i = 0; i < 1000; i = i + 1) {
    float a = cos(2 * 3.14159 * i / 1000.0);
    float b = sin(2 * 3.14159 * i / 1000.0);
    glVertex3f(a, b, 0);
  }
  glEnd();

  glPopMatrix();

  glutSwapBuffers();
}
