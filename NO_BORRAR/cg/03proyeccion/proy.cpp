#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) 
{
     glClearColor (0.0, 0.0, 0.0, 0.0);
        glShadeModel (GL_FLAT);
}

void display(void)
{
     glClear (GL_COLOR_BUFFER_BIT);
      glColor3f (1.0, 1.0, 1.0);
      glLoadIdentity ();             /* clear the matrix */
      
      /* viewing transformation  */
      gluLookAt(0.0, 6.0,-3.0, 0.0, -6.0, 2.0, 0.0, 1.0, 0.0);//Posición de la camara
     //gluLookAt(eyeX,eyeY,eyeZ,  centerX, centerY,centerZ,  upX,upY,upZ
      glScalef (1.0, 0.8, 1.0);      /* modeling transformation */ 
     glutWireCube (1.0);
     glFlush ();
}

void reshape (int w, int h)
{
     glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
       glMatrixMode (GL_PROJECTION);
       glLoadIdentity ();
       // glFrustum( left, right, bottom,top,near,far
       glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
       //Alternativa: gluPerspective(angulo,aspect, near,far);
       glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize (500, 500); 
     glutInitWindowPosition (200, 100);
     glutCreateWindow (argv[0]);
     
     init ();

     glutDisplayFunc(display); 
     glutReshapeFunc(reshape);
     glutMainLoop();

     return 0;
}
