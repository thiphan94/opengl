
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "ppm.c"

#define BLANC 0 
#define BLEU 1
#define ROUGE 2
#define JAUNE 3 
#define ORANGE 4
#define VERT 5

/*************Guide d'utilisation**********
x/X pour déplacer en x la position du point de vue
y/Y pour déplacer en y la position du point de vue
z/Z pour déplacer en z la position du point de vue
/*****************************************/

// Projet CC OPENGL (version de fonctionnement de callbacks)
// PHAN Nu Uyen Thi
// MOUCHNINO Elie
float ex=5;
float ey=5;
float ez=3;

GLuint texName[10];
static GLubyte *data;
int width;
int height;

void init_texture(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glEnable (GL_DEPTH_TEST);


   // Chargement des textures 
   //
   glGenTextures(6, texName);
   glEnable(GL_TEXTURE_2D);


   // face blanche
   data=glmReadPPM("rubik_cube_white_texture.ppm", &width , &height);
   glBindTexture(GL_TEXTURE_2D, texName[0]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                data);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   // face bleue
   data=glmReadPPM("blue.ppm", &width , &height);
   glBindTexture(GL_TEXTURE_2D, texName[1]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                data);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   // face rouge
   data=glmReadPPM("red.ppm", &width , &height);
   glBindTexture(GL_TEXTURE_2D, texName[2]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                data);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   // face jaune
   data=glmReadPPM("yellow.ppm", &width , &height);
   glBindTexture(GL_TEXTURE_2D, texName[3]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                data);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   // face orange
   data=glmReadPPM("orange.ppm", &width , &height);
   glBindTexture(GL_TEXTURE_2D, texName[4]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                data);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   // face verte
   data=glmReadPPM("green.ppm", &width , &height);
   glBindTexture(GL_TEXTURE_2D, texName[5]);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                data);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

}



void draw_cube() {
	
  // Face rouge
  //
  glBindTexture(GL_TEXTURE_2D, texName[ROUGE]);
  glPushMatrix();
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
      glTexCoord2f(0.0, 1.0); glVertex3f(1,0,0);
      glTexCoord2f(1.0, 1.0); glVertex3f(1,1,0);
      glTexCoord2f(1.0, 0.0); glVertex3f(0,1,0);
  glEnd();
  glPopMatrix();

  // Face bleue
  //
  glBindTexture(GL_TEXTURE_2D, texName[BLEU]);
  glPushMatrix();
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
      glTexCoord2f(0.0, 1.0); glVertex3f(0,1,0);
      glTexCoord2f(1.0, 1.0); glVertex3f(0,1,1);
      glTexCoord2f(1.0, 0.0); glVertex3f(0,0,1);
  glEnd();
  glPopMatrix();

  // Face jaune
  //
  glBindTexture(GL_TEXTURE_2D, texName[JAUNE]);
  glPushMatrix();
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
      glTexCoord2f(0.0, 1.0); glVertex3f(0,0,1);
      glTexCoord2f(1.0, 1.0); glVertex3f(1,0,1);
      glTexCoord2f(1.0, 0.0); glVertex3f(1,0,0);
  glEnd();
  glPopMatrix();

  // Face blanche
  //
  glBindTexture(GL_TEXTURE_2D, texName[BLANC]);
  glPushMatrix();
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(1,0,1);
      glTexCoord2f(0.0, 1.0); glVertex3f(1,1,1);
      glTexCoord2f(1.0, 1.0); glVertex3f(1,1,0);
      glTexCoord2f(1.0, 0.0); glVertex3f(1,0,0);
  glEnd();
  glPopMatrix();

  // Face verte
  //
  glBindTexture(GL_TEXTURE_2D, texName[VERT]);
  glPushMatrix();
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(0,0,1);
      glTexCoord2f(0.0, 1.0); glVertex3f(0,1,1);
      glTexCoord2f(1.0, 1.0); glVertex3f(1,1,1);
      glTexCoord2f(1.0, 0.0); glVertex3f(1,0,1);
  glEnd();
  glPopMatrix();

  // Face orange
  //
  glBindTexture(GL_TEXTURE_2D, texName[ORANGE]);
  glPushMatrix();
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(0,1,0);
      glTexCoord2f(0.0, 1.0); glVertex3f(0,1,1);
      glTexCoord2f(1.0, 1.0); glVertex3f(1,1,1);
      glTexCoord2f(1.0, 0.0); glVertex3f(1,1,0);
  glEnd();
  glPopMatrix();
}



void display(void) {
// Caméra
	glLoadIdentity ();
  gluLookAt (ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  int i = 0;
  int j = 0;
  int k = 0;
  
   for (k = 0; k < 3; k++) {
  
     for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
           glTranslatef(1.0, 0.0, 0.0);
           draw_cube();
           glTranslatef(1.0, 0.0, 0.0);
           draw_cube();
           glTranslatef(1.0, 0.0, 0.0);
           draw_cube();
        }
       	glTranslatef(-3.0, 0.0, -1.0);
     }
  
     glTranslatef(0.0, 1.0, 3.0);
   }


  glPopMatrix();
  glutSwapBuffers();
}
