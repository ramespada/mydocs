#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;

/*
static GLfloat mi_cubo = {0.0,0.0,0.0,
                            1.0,0.0,0.0,
                                      }
*/                         

void init(void){
   glClearColor (0.95, 0.95, 0.8, 1.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();

   glRotatef(spin, 0.3, 1.0, 0.0);
   //glTranslatef(0.01,0.0,0.0);

//Puntos:
  glBegin(GL_POINTS);
       glPointSize(5.0);
       glColor3f(1.0,0.0,0.0);
    glVertex3f(5.0,0.5,0.0);
  glEnd();
//Lineas: 
  glBegin(GL_LINES);
      glColor3f(0.4,0.0,1.0); 
      glLineWidth(1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(10.0,0.0,0.0);
  glEnd();
//Poligono 1 (Forma predefinida)
    glColor3f(1.0, 0.0, 0.0);
   glRectf(-15.0, -15.0, 15.0, 15.0);

//Poligono 2 (manual)
  glBegin(GL_POLYGON);
      glColor3f(0.3,1.0,0.5);
    glVertex3f( 5.0,-20.0,0.0);
    glVertex3f(-5.0, 15.0,0.0);
    glVertex3f( 0.0,-10.0,0.0);
  glEnd();
//Poligono 3 (hecho con arrays)
   GLfloat nodos[] = {1.2, 13.0,0.0,
                      2.0, 22.0,0.0,
                     10.0,  8.0,0.0,
                      5.0,-10.0,0.0};
   GLfloat colores[] = {0.3,0.4,0.8};
   
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);

  glVertexPointer(3,GL_FLOAT,0,nodos);
  glColorPointer(3,GL_FLOAT,0,colores);

  glBegin(GL_POLYGON);
  int i;
  for (int i=0; i<12; i++){
    glArrayElement(i);
  }
  glEnd();  
  //  glArrayElement(3);
  //  glDrawArrays();
  //glEnd();

  // glFlush();
   glPopMatrix();
   glutSwapBuffers();
}

void spinDisplay(void)
{
   spin = spin + 1; 
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-50.0, 50.0, -50.0, 50.0, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

//Interacción mouse/teclado: -------------------------//
void keyboard(unsigned char key, int x, int y){
  if(key==27) exit(0);
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}
// --------------------------------------------------//
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   
   glutInitWindowSize (250, 250); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   
   init ();
   
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 

   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   
   glutMainLoop();

   return 0;
}
