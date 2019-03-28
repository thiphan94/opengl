#include <GL/glut.h>
#include <stdlib.h>

int animate=1;

void display(void);


void init(void) 
{
   glClearColor (0.0, 0.0, 1.0, 0.0);
   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();
   gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void my_timer(int v)
{
   if (animate)
       glutTimerFunc(40, my_timer, 1);

   glutPostRedisplay();
}



void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      case 'a':
         animate=!animate;
	 if (animate)
   		glutTimerFunc(40, my_timer, 1);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH|GLUT_DOUBLE| GLUT_RGB);
   glutInitWindowSize (300, 300); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(40, my_timer, 1);

   glutMainLoop();
   return 0;
}



