#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

static GLfloat x1=2.0;
static GLfloat dx1=0.5;
static GLfloat x2=2.0;
static GLfloat dx2=0.5;
static GLfloat t=0.0;
static GLfloat dt=0.01;

static GLfloat a1=5.0;
static GLfloat a2=5.0;
static GLfloat pcolor[]={0.0,0.0,0.0};

static GLfloat vel=0.1;
static GLfloat omega=0.5*100;



void iniciar(){
  glClearColor(1,1,1,1); //Color de borrado.
  glOrtho(-10,10,-10,10,-5,5);

}

void dibujar(){
  glClear(GL_COLOR_BUFFER_BIT);

  //glLoadIdentity();
  glPushMatrix();  //Trae matriz
    glTranslatef(x1,x2,0.0);
    glRotatef(omega*t,0,0,1);
    glColor3f(0.2,0.2,0.2);
      glutWireCube(3.0);
  glPopMatrix();//Destruye la matriz

  glPushMatrix();  //Trae matriz
    glTranslatef(a1,a2,0.0);
    glColor3fv(pcolor);
      glutWireCube(dx2);
  glPopMatrix();//Destruye la matriz


  //glFlush(); // Limpia buffer. Usar con SINGLE_BUFFER
  glutSwapBuffers(); //Interacambia buffers (usar con DOUBLE_BUFFER)
}

void actualizar(){
    t=t+dt;
    glutPostRedisplay();

    if (abs(x1-a1)<dx1 & abs(x2-a2)<dx2) {
      cout << "Hay colision!" << endl;
      pcolor[0]=1.0;
      pcolor[1]=0.0;
    }
    else{
      pcolor[0]=0.0;
      pcolor[1]=1.0;
    }
}

void teclado(unsigned char tecla, int x , int y){
  switch (tecla) {
    case 'w':
        x2+=dx2;
        break;  
     case 's':
        x2-=dx2; 
        break; 
     case 'd':
        x1+=dx1;
        break; 
     case 'a':
        x1-=dx1;
        break;
     default:
        break;
 }
}

int main(int argc, char** args){

    glutInit(&argc, args);  //Inicializar glut

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  // Modo (color RGB) y Buffer Doble)
    glutInitWindowSize(200,200);                // Tamaño ventana
    glutInitWindowPosition(100,80);             // Posición ventana
    glutCreateWindow("Titulo ventana");      // Abre ventana

    iniciar();
    glutDisplayFunc(dibujar);       // Cual es la función para dibujar.

    glutKeyboardFunc(teclado);       //Funcion del teclado
    
    glutIdleFunc(actualizar);       //Actualiza escena
  

    glutMainLoop();
    return 0;
}

