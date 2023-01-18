# Introducción a *openGL*
---

## Esquema básico:

Veamos un ejemplo de un programa simple que muestra un poligono en pantalla:

```cpp
#include <GL/gl.h>
   
main(){

  InicializarUnaVentana();                 // (NO es un comando de openGL!)
   
      glClearColor (0.0,0.0,0.0,0.0);      // Color de borrado
      glClear(GL_COLOR_BUFFER_BIT);        // Borra fondo (a negro)
   
      glColor3f(1.0,1.0,1.0);              // Setea color de objetos (blanco)
 
      glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0); // Sist.de coords (left-right bottom-top near-far)
  
      glBegin(GL_POLYGON);                 // Armar poligono
        glVertex3f(0.25,0.25,0.0);
        glVertex3f(0.25,0.00,0.0);
        glVertex3f(0.00,0.25,0.0);
        glVertex3f(0.00,0.00,0.0);
      glEnd();
 
      glFlush();                           // Ejecuta el poligono 
  
  ActualizarVentanayChequiarEventos(); // (NO openGL!)
}
```


### Compilación:
Si escribimos el código en un archivo de texto llamado *`MiCodigo.cpp`* entonces para compilar simplemente vamos a la terminal y ejecutamos en el directorio donde está el código:
```  g++ MiCodigo.cpp -lGL ```
`g++` es el compilador (hay otros), luego el nombre del script, y finalmente `-lGL` es para avisar que se utiliza la librería de openGL (*GL*).


## Sintáxis básica.

Los comandos en *openGL* comienzan con **`gl`**, y luego el nombre del comando comenzando con una mayúscula. Los comandos que sirven para definir constantes generalmente comienzan con **`GL_`** y todas las letras en mayúscula.

Algunos comandos terminan con unos numeros y unas letras (por ejemplo: *glVertex3f*), el número nos dice cuantos argumentos requiere la función y la letra nos dice el tipo de dato del argumento.


|sufijo |  tipo de dato  | nombre *openGl*  |
|:------| -------------- |:-----------------|
| b     | entero 8-bit   | GLbyte           |
| s     | entero 16-bit  | GLshort          |
| i     | entero 32-bit  | GLint            |
| f     | flotante 32-b  | GLfloat          |
| d     | flotante 64-bit| GLdouble         |


Algunos comandos terimnan en **`v`** esto indica que el argumento que toma es un vector (ó *array*). por ejemplo:

```cpp
glColor3f(1.0, 0.0, 0.0);
GLfloat color_array[] = {1.0, 0.0, 0.0};
glColor3fv(color_array);
```

**``GLvoid``**


---
### Variables de estado:


## *openGL* pipeline

   1. **Creación de datos** (*shape* ó *raster/pixel*)
   2. **Lista de display** Los objetos creados pueden guardarse en una lista de display a ser utilizada posteriormente.
   3. **Evaluadores** (*Interpolación/splines*)  
   4. **Operaciones sobre vertices** (*transformaciones*)
   5. **Ensamble** (*clipping*)
   6. **Operaciones sobre pixeles **
   7. **Ensable de texturas**
   8. **Rasterización**
   9. **Operaciones sobre fragmentos**


---
## Librerías:
*OpenGL* provee de comandos muy poderosos pero de bajo nivel, por esto se suele utilizar ciertas librerías de alto nivel que facilitan la ejecución de ciertas tareas y hacen más claro el código. algunas de las más conocidas:

  + **`glu`**  *(openGL Utility Library)* Tiene rutinas para diversas tareas (se usa siempre)
  + **`glut`** *(openGL utility toolkit)* Se utiliza para menejo de pantalla (pero también tiene otro tipo de rutinas)

para incorporarlas al código hay que agregar al inicio:

```cpp
#include <GL/glu>
#include <GL/glut>
```

También cuando compilemos vamos a tener que agregarlas
```  g++ MiCodigo.cpp -lglut -LGLU -lGL ```


## Algunos comandos de *`glut`*

### Manejo de ventana:

 - **glutInit()**  Inicia *glut* (debe llamarse antes que cualquier comando de glut).
 - **glutInitDisplayMode()** Determina si usa un sistema de colores RGB ó SVH.
 - **glutInitWindowPosition(*int x , int y*)**.
 - **glutInitWindowsSize(*int width , int size*)**.
 - **glutCreateWindow()**.

### Llamada a display
 - **glutDisplayFunc()**
 - **glutPostRedisplay()**

### Corriendo el programa
 - **glutMainLoop()**
 - **glutDisplayFunc()**

### Manejo de eventos
 - **`glutReshapeFunc()`**
 - **`glutKeyboardFunc()`**
 - **`glutMouseFunc()`**
 - **`glutMotionFunc()`**

### Procesos de fondo:


### Creación de objetos 3D

Algunos objetos que pueden ser creados con `glut` incluyen: cono, cubo, esféra, tetrahedro, octahedro, dodecahedro, icosahedro, torus, tasa de té.

Todas estas formas pueden ser creadas como *wireframes* (alambres) ó como objetos sólidos. Por ejemplo: `glutWireCube()` y `glutsolidCube()`


---
## Animación


`glutSwapBuffers()`

