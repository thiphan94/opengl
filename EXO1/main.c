#include <stdlib.h>
#include <GL/glut.h>


void display(void);


void mon_timer(int val)
{
   glutTimerFunc(40,mon_timer,1);
   glutPostRedisplay();
}


/* 
  Initialisation de l'etat OpenGl
*/ 
void init (void)
{
/* Choisir la couleur d'effacement */
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* Selectionner la matrice de projection */
   glMatrixMode(GL_PROJECTION);

/* Initilialise la matrice de projection */
   glLoadIdentity();

/* Clipping de cadrage */
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}





/* Sortie de l'application : touche ESC */
static void key(unsigned char k, int x, int y)
{
  switch (k) {
  case 27:  /* Escape */
    exit(0);
    break;
  default:
    return;
  }
  glutPostRedisplay();
}



int main(int argc, char** argv)
{

/* Initialisation de la GLUT */
   glutInit(&argc, argv);


/* Choix du mode d'affichage */
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);


/* Creation de la fenetre puis choix de  
   sa taille et de sa position
*/
   glutInitWindowSize (250, 250);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("exo2");

   init ();

/* Connexion callbacks puis boucle d'evenements */
   glutDisplayFunc(display);
   glutKeyboardFunc(key);
   glutTimerFunc(40, mon_timer, 1); 
   glutMainLoop();


   return 0;  
}
