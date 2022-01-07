#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

static GLfloat t=0.1;      //Tiempo
static GLfloat dt=0.1;     //dt
static GLfloat v[]={0.2,0.3,0.0};       //Vel. lineal
static GLfloat omega=5.0; //Vel. angular

//Preparo ambiente
void init(void){
  glClearColor(1.0,1.0,1.0,1.0);
  glShadeModel(GL_FLAT);

}
void bodies(void){
    glColor3f(0.4,1.0,0.6);
    glRectf(-10.0,-10.0,10.0,10.0);//,-1.0,1.0);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();


  //Traslación:
  glTranslatef(v[0]*t,v[1]*t,v[2]*t);
  
  //Rotación:
  glRotatef(omega*t,1.0,1.0,0.0);
  
  //Alargamiento:
  glScalef(cos(t*0.01),sin(t*0.005)+1.0,0.0);

   bodies();
    glColor3f(0.7,0.3,0.3);
  glRectf(-5.0,-5.0,5.0,5.0);

  glPopMatrix();
  glutSwapBuffers();
}

void spinDisplay(void){
    t=t+dt;
    glutPostRedisplay();
}

void reshape(int w, int h){
  glViewport(0,0,(GLsizei) w, (GLsizei) h );
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-30,30,-30,30,-10.0,10.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

//Interacción mouse/teclado: --------------------    -----//
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

//-------------------------------------------
int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100,100);

    glutCreateWindow ("Transformaciones");

    init ();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
      
    glutMainLoop();

    return 0;
}
