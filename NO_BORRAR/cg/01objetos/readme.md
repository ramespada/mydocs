# Formas y objetos

> Cómo representar objetos, y trabajar con ellos.

## Preparando el ambiente de trabajo
Antes de agregar objetos necesitamos limpiar el ambiente de trabajo y definir el espacio en el que vamos a trabajar.

```cpp
glClearColor(0.1,0.1,0.1,0.1);  // Defino color de borrado
glClear(GL_COLOR_BUFFER_BIT);
```

| Buffer           |   Nombre                |
|:---------------- | ----------------------- |
| Color            | `GL_COLOR_BUFFER_BIT`   |
| Profundidad      | `GL_DEPTH_BUFFER_BIT`   |
| Acumulación      | `GL_ACCUM_BUFFER_BIT`   |
| Stencil          | `GL_STENCIL_BUFFER_BIT` |

Antes hay que setiar el valor de cada buffer (por ejemplo con los comandos: `glClearColor()`,`glClearDepth()`, `glClearIndex()`,`glClearAccum()`,`glClearStencil()`)


## Sistema de cordenadas



## Puntos, Lineas y Poligonos

 + **Puntos**: Se representan con un vector *(x,y,z)* también llamado *nodo* ó *vertex*

 + **Lineas**: Se representan como un conjunto de puntos, donde se especifica los vértices de cada segmento. Pueden ser *abiertos* ó *cerrados* (si los nodos de los extremos son el mismo).

 + **Polígonos**: Son el area que queda adentro de lineas cerradas. Algunas restricciones que se imponen es que las lineas de los poligonos *no pueden intersectarse*. Además todos los poligonos deben ser *convexos*. Por último, los poligonos no pueden contener agujeros internos (pues no serían convexos).

La razón de estas restricciones está vinculada a que permite que el renderizado sea más rápido.

Si queremos obtener formas más complejas, teniendo en cuenta que con la union de poligonos simples podemos generar polígonos más complejos, se recurre a técnicas de mallado (*tesselations*).

### Vertices
Para definir vertices se utiliza la función `glVertex*()`. Este comando debe ir entre medio de `glBegin()` y `glEnd()`.

Dentro del bloque glBegin(() puede tomar de argumento: `GL_POINTS`, `GL_LINES`,`GL_LINE_STRIP`,`GL_LINE_LOOP`,`GL_TRIANGLES`,`GL_TRIANGLE_STRIP`,`GL_TRIANGLE_FAN`,`GL_QUADS`,`GL_QUAD_STRIP`,`GL_POLIGON`

Además de las coordenadas (`glVertex*()`) existen otros atributos que podemos definir:

 + `glVertex()`--> *Coordendas*
 + `glColor()` --> *Color*
 + `glIndex()` --> *Indice*
 + `glNormal()` --> *Vector normal*
 + `glTexCoord()` --> *Textura*
 + `g.EdgeFlag()` --> **
 + `glMaterial()` --> *Prop. del material*
 + `glArrayElement()`--> **
 + `glEvalCoord()` --> **
 + `glEvalPoint()` --> **
 + `gCallList()` --> **


```cpp
glBegin(GL_POINTS);
  glColor3f(0.0,1.0,0.0);
  glVertex3f(1.0,2.0,3.0);
...

glEnd();
```

## Manejo de estado

Los estados (color, textura, etc.) de un objeto están siempre apagados por default ya que disminuyen la velocidad de renderizado. Para activarlos ó descativarlos existen los comandos `glEnable()` y `glDisable()`.
Variables de estados que pueden ser activadas/desactivadas son, por ejemplo, *GL_BLEND*,*GL_DEPETH_TEXT*, *GL_LINE_STIPPLE*, *GL_LIGHTING*, etc.

Para chequiar si alguna variable de estado está prendida se usa `glIsEnabled()`.


## Atributos

  + `glPushAttrib()`
  + `glPopAttrib()`
  + `glPushClientAttrib()`
  + `glPopClientAttrib()`
 
 
## Vectores normales a una superficie:

```cpp
GLfloat d1[3], d2[3], norm[3];    
for (j = 0; j < 3; j++) {    
   d1[j] = vdata[tindices[i][0]][j] - vdata[tindices[i][1]][j];    
   d2[j] = vdata[tindices[i][1]][j] - vdata[tindices[i][2]][j];    
}
normcrossprod(d1, d2, norm); 
glNormal3fv(norm);
```

## Subdivision:

```cpp
void subdivide(float u1[2], float u2[2], float u3[2],
                float cutoff, long depth)
{
   GLfloat v1[3], v2[3], v3[3], n1[3], n2[3], n3[3];
   GLfloat u12[2], u23[2], u32[2];
   GLint i;

   if (depth == maxdepth || (curv(u1) < cutoff &&
       curv(u2) < cutoff && curv(u3) < cutoff)) {
      surf(u1, v1, n1); surf(u2, v2, n2); surf(u3, v3, n3);
      glBegin(GL_POLYGON);
         glNormal3fv(n1); glVertex3fv(v1);
         glNormal3fv(n2); glVertex3fv(v2);
         glNormal3fv(n3); glVertex3fv(v3);
      glEnd();
      return;
   }
   for (i = 0; i < 2; i++) {
      u12[i] = (u1[i] + u2[i])/2.0;
      u23[i] = (u2[i] + u3[i])/2.0;
      u31[i] = (u3[i] + u1[i])/2.0;
   }
   subdivide(u1, u12, u31, cutoff, depth+1);
   subdivide(u2, u23, u12, cutoff, depth+1);
   subdivide(u3, u31, u23, cutoff, depth+1);
   subdivide(u12, u23, u31, cutoff, depth+1);
}
```
