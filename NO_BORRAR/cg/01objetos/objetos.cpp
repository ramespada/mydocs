#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

//Preparo ambiente
void init(void){
  glClearColor(1.0,1.0,1.0,1.0);
  glShadeModel(GL_FLAT);
}

void puntos(void){
  glBegin(GL_POINTS);
      glColor3f(1.0,0.0,1.0);
      /*Otras propiedades:
      glIndexf(1.0);           //Inidice de color
      glNormal3f(0.0,1.0,0.0); //vector normal
      glTexCoord();           //Textura
      glEdgeFlag(GL_TRUE);           //Si es ó no un "edge"(puente entre nodos)
      glMaterial();*/          //Prop de material
    glVertex2f(-2.5,-1.6);
  glEnd();

  GLfloat nodo[] = {-5.5,-3.2};
  GLfloat color[] = {1.0,0.5,0.6};
  glBegin(GL_POINTS);
      glPointSize(2.0);
      glColor3fv(color);
    glVertex2fv(nodo);
  glEnd();

}

void lineas(void){
  glBegin(GL_LINES);
      glColor3f(1.0,0.2,0.3);
      glLineWidth(2.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.3,-1.0);
  glEnd();

  GLfloat nodos[]={0.1,1.0,2.0,3.0,4.0,1.0};
  glBegin(GL_LINE_STRIP);
      glLineStipple(1,0x3F07);
      glEnable(GL_LINE_STIPPLE);
    int i;
    for (i=0;i<5;i+=2){
      glVertex2f(nodos[i],nodos[i+1]);
    }
  glEnd();
  //glBegin(GL_LINE_LOOP);
  //    glColor3f();
  //  glVertex2fv();
  //glEnd();
}

void poligonos(void){

  glEnableClientState(GL_VERTEX_ARRAY); //para especificar coords como arrays.
  GLfloat triangulo[]= {2.5,4.0, 3.0,5.0, 4.0,3.0};
  glVertexPointer(2,GL_FLOAT,0,triangulo);
  glBegin(GL_TRIANGLES);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    // Si conoces los vectores normales a cada nodo los podes agregar con:
    //glNormal3fv(n1); (Es información útil.)
  glEnd();

  glBegin(GL_QUADS);
  GLubyte allIndices[] = {4, 5, 6, 7, 1, 2, 6, 5, 
                       0, 1, 5, 4, 0, 3, 2, 1, 
                      0, 4, 7, 3, 2, 3, 7, 6};
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
  glEnd();

  /*glBegin(GL_POLYGON);
    glColor3f();
    glVertex2f();
  glEnd();
*/
}

void formasPrimitivas(void){
    glColor3f(0.0,1.0,0.3);
  glRectf(2.0,3.0,5.0,6.0);//xmin,ymin,xmax,ymax
}


void display(void){

  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();

    puntos();  
    
    lineas();
    
    poligonos();

    formasPrimitivas();

    //glFlush(); //Da la señal para que renderice.
    //glFinish()a
    glPopMatrix();
    glutSwapBuffers();
}


void reshape(int w, int h){ 
  //glutReshapeFunc() le pasa a esta función w y h

  
  glViewport(0,0,(GLsizei) w, (GLsizei) h );//re ajusta pixels para que ocupen toda la ventana 
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //sistema de coordenadas
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10,10,-10,10,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
}

//-------------------------------------------
int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Objetos");

    init ();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

      
    glutMainLoop();

    return 0;
}
