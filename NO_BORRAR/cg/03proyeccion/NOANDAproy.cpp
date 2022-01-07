#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>


static int win_height=200;
static int win_width=200;
static float Angle=30;
void object(void){
  glColor3f(1.0,0.0,0.0);
  glutSolidTeapot(10);

}


void draw(){

  glClearColor( 100, 100,50, 0 );
  glClear ( GL_COLOR_BUFFER_BIT);
 
  GLfloat object[] ={1.0,0.2,3.0,5.0,1.1,2.0,-10,-20,-5.0,1.0};// glutSolidTeapot(10);

 //top left: top view
 glViewport(0, win_height/2, win_width/2, win_height/2);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0);
 gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glCallList(object);
 // top right: right view
 glViewport(win_width/2, win_height/2, win_width/2, win_height/2);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0);
 gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glCallList(object);
 // bottom left: front view
 glViewport(0, 0, win_width/2, win_height/2);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0);
 gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glCallList(object);
 // bottom right: rotating perspective view
 glViewport(win_width/2, 0, win_width/2, win_height/2);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(70.0, 1.0, 1, 50);
 gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glRotatef(30.0, 1.0, 0.0, 0.0);
 glRotatef(Angle, 0.0, 1.0, 0.0);
 glCallList(object);
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInit();

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(500,500);
  glutCreateWindow("Proyecciones");
  glutDisplayFunc(draw);

  glutMainLoop();
  
  return 0;
}
