#include "ppm.c"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static GLuint texName[1];
GLubyte *data;
int width, height;

void init_texture(void) {
  data = glmReadPPM("rubik_cube_white_texture.ppm", &width, &height);
  glGenTextures(1, texName);

  glBindTexture(GL_TEXTURE_2D, texName[0]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, data);

  glEnable(GL_TEXTURE_2D);
}

// void cube(float r, float g, float b) {
void cube() {
  glEnable(GL_DEPTH_TEST);
  glPushMatrix();

  glBegin(GL_QUADS);
  glColor3f(.2, .2, .2);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(1, 1, 0);
  glVertex3f(0, 1, 0);
  glEnd();
  // glColor3f(.6, .6, .6);
  glBindTexture(GL_TEXTURE_2D, texName[0]);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

  glBegin(GL_QUADS);

  glTexCoord2f(0.0, 0.0);
  glVertex3f(0, 0, 1);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(1, 0, 1);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1, 1, 1);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(0, 1, 1);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(.7, .7, .7);
  // glColor3f(r, g, b);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 0, 1);
  glVertex3f(0, 1, 1);
  glVertex3f(0, 1, 0);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(.9, .9, .9);
  glVertex3f(1, 0, 0);
  glVertex3f(1, 0, 1);
  glVertex3f(1, 1, 1);
  glVertex3f(1, 1, 0);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(.3, .3, .3);
  glVertex3f(0, 1, 0);
  glVertex3f(0, 1, 1);
  glVertex3f(1, 1, 1);
  glVertex3f(1, 1, 0);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(.5, .5, .5);
  glVertex3f(0, 0, 1);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(1, 0, 1);
  glEnd();

  glPopMatrix();
}

// Variable pour modifier le systeme de coordonnees
float s = 1.0;

void display(void) {
  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  //
  // int i = 0;
  // int j = 0;
  // int k = 0;
  //
  // for (k = 0; k < 3; k++) {
  //
  //   for (i = 0; i < 3; i++) {
  //     if (i % 2 == 0) {
  //       for (j = 0; j < 1; j++) {
  //         glTranslatef(1.0, 0.0, 0.0);
  //         cube(0.0, 1.0, 0.0);
  //         glTranslatef(1.0, 0.0, 0.0);
  //         cube(1.0, 0.0, 1.0);
  //         glTranslatef(1.0, 0.0, 0.0);
  //         cube(0.0, 1.0, 0.0);
  //       }
  //     }
  //     if (i % 2 == 1) {
  //       for (j = 0; j < 1; j++) {
  //         glTranslatef(1.0, 0.0, 0.0);
  //         cube(1.0, 0.0, 1.0);
  //         glTranslatef(1.0, 0.0, 0.0);
  //         cube(0.0, 1.0, 0.0);
  //         glTranslatef(1.0, 0.0, 0.0);
  //         cube(1.0, 0.0, 1.0);
  //       }
  //     }
  //     glTranslatef(-3.0, 0.0, -1.0);
  //   }
  //
  //   glTranslatef(0.0, 1.0, 3.0);
  // }

  cube();

  glPopMatrix();
  glutSwapBuffers();
}
