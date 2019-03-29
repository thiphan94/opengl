#include <GL/glut.h>
#include <stdbool.h>
#include <stdlib.h>
float i = 1.0;
bool go_up = true; /*or false*/

void draw_cube() {
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
}

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  /*PROGRAMME A COMPLETER  */

  if (i < 4) {
    glScalef(i, i, i);
    draw_cube();
    i = i + 0.1;
  }
  if (i >= 4) {
    i = 1.0;
  }

  /*version  extension (go up and go down)*/

  // if (!go_up) {
  //   glScalef(i, i, i);
  //   draw_cube();
  //   i = i - 0.1;
  // }
  // if ((i <= 1) && (!go_up)) {
  //   go_up = true;
  // }
  // if (go_up) {
  //   glScalef(i, i, i);
  //   draw_cube();
  //   i = i + 0.1;
  // }
  // if ((i >= 4) && (go_up)) {
  //   go_up = false;
  // }
  glPopMatrix();

  glutSwapBuffers();
}
