#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define pi 3.142857
// Face rouge
//
glColor3f(1, 0, 0);
glBegin(GL_QUADS);
glVertex3f(0, 0, 0);
glVertex3f(1, 0, 0);
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
glVertex3f(1, 1, 0);
glEnd();
