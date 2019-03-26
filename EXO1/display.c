#include <stdlib.h>
#include <GL/glut.h>


/* 
  Dessine la scene 
*/
void display(void)
{
/* Vide l'ecran */
   glClear (GL_COLOR_BUFFER_BIT);

/* Dessine le polygone */
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.5, 0.0, 0.0);
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.0, 0.5, 0.0);
   glEnd();
   glColor3f (1.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.5, 0.0);
      glVertex3f (0.5, 0.25, 0.0);
   glEnd();
   

/* Force le rendu maintenant */
   glutSwapBuffers();
}

