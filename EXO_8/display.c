#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

float xRotation = 0.0, yRotation = 0.0;
float zTranslate = -3.0;
float i = 0.0;
float j = 0.0;
float k = 0.0;
float x = 0.0;
float y = 0.0;
bool go_up = true;
//*****fonction draw_circle****//
void draw_circle(int numSegments, GLfloat ballRadius, double z) {
  GLfloat angle;
  int i;
  glTranslatef(0.0, 5.0, -0.5);
  glPushMatrix();
  glBegin(GL_POLYGON);
  for (i = 0; i <= numSegments; i++) {
    if (z == 0.0) {
      glColor3f(1.0f, 1.0f, 1.0f); // blanc
    } else {
      glColor3f(1.0f, 1.0f, 0.0f); // jaune
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

  glColor3f(1, 1, 1);
  glBegin(GL_LINE_LOOP);
  glVertex3f(0, 0, 0);
  glVertex3f(12, 0, 0);
  glVertex3f(12, 12, 0);
  glVertex3f(0, 12, 0);
  glEnd();
  glPopMatrix();
}

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

  draw_polygon();

  if (k < 5) {
    x = j;
    y = i;
    glTranslatef(x, y, -0.5);
    draw_circle(100, 0.1 * PI, 1);
    j = j - 0.1;
    k = k + 0.1;
    i = i - 0.1;
    // printf("%lf     %lf\n", i, j);
  }

  if (k >= 5) {

    x = j;
    y = i;
    glTranslatef(x, y, -0.5);
    draw_circle(100, 0.1 * PI, 1);
    j = j + 0.2;
    i = i - 0.2;
    k = k + 0.2;
    // printf("%lf     %lf\n", j, i);
  }

  if (k >= 10) {
    x = j;
    y = i;
    glTranslatef(x, y, -0.0);
    draw_circle(100, 0.1 * PI, 1);
    j = j + 0.2;
    i = i + 0.5;
    k = k + 0.2;
    // printf("%lf    %lf    %lf\n", j, i, k);
  }

  if (k >= 15) {
    x = j;
    y = i;
    glTranslatef(x, y, 0.0);
    draw_circle(100, 0.1 * PI, 1);
    j = j - 0.6;
    i = i + 0.2;
    k = k + 0.2;
    // printf("%lf    %lf    %lf\n", j, i, k);
  }
  if (k >= 20) {
    k = 0.0;
    i = 0.0;
    j = 0.0;
  }
  glPopMatrix();

  glutSwapBuffers();
}
