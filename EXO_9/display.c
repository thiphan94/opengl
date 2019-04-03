#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#include "ppm.c"


static GLuint texName[1];
GLubyte* data;
int width, height;


void init_texture(void)
{
   data=glmReadPPM("brick10.ppm", &width , &height); 
   glGenTextures(1, texName);

   glBindTexture(GL_TEXTURE_2D, texName[0]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                data);

   glEnable(GL_TEXTURE_2D);
}



void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glPushMatrix();

   glEnable(GL_DEPTH_TEST);
   
  

   glBindTexture(GL_TEXTURE_2D, texName[0]);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glColor3f(1,1,0);


   glTranslatef(-0.5,-0.5,0);
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
   glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 0.0, 0.0);
   glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
   glTexCoord2f(1.0, 0.0); glVertex3f(0.0, 1.0, 0.0);
   glEnd();


   glPopMatrix();

   glutSwapBuffers();
}




