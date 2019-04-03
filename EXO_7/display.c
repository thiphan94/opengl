#include <GL/glut.h>
#include <stdlib.h>


void carre(float r, float g, float b)
{
   glPushMatrix();
   glTranslatef(-6.0, 4.0, 0.0);
	 glColor3f (r, g, b);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (1, 0, 0);
      glVertex3f (1, 1, 0);
      glVertex3f (0, 1, 0);
   glEnd();
	 glPopMatrix();
}


void display(void) {

   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
	 glPushMatrix();

   int i=0;
	 int j=0;	
	 for(i=0; i <10; i++){
			if(i%2==0){
				for(j=0; j<5; j++){
					glTranslatef(1.0,0.0,0.0);
					carre(1.0,1.0,1.0);
		   		glTranslatef(1.0,0.0,0.0);
     	 		carre(0.0,0.0,0.0);
	      }
			}
			if(i%2==1){
				for(j=0; j<5; j++){
					glTranslatef(1.0,0.0,0.0);
     	 		carre(0.0,0.0,0.0);
					glTranslatef(1.0,0.0,0.0);
					carre(1.0,1.0,1.0);
				}
			}
			glTranslatef(-10.0,-1.0,0.0);
		
		}
 	 glPopMatrix();

   glutSwapBuffers();
}



