# Proyección
---

> Una vez que tenemos nuestro modelo 3D, para generar una imagen sobre la pantalla hay que proyectar el modelo sobre un plano. 

## Espacios:

  1. *Object space*. Coordenadas del mundo real (R3).

  2. *Object subspace*

  3. *Image space*: Coordenadas de la pantalla. (R2)

  4. *Image subspacea*


### Mapeo del R3 -> R2

En *openGL*:
  - `glOrtho(*xmin,xmax,ymin,ymax,zmin,zmax*)`
  - `glOrtho2D(*left,right,bottom,top*)`
  - `glFrustum(*xmin,xmax,ymin,ymax,zmin,zmax*)`
  - `gluPerspective(*fov,aspect,near,far*)`
  - `gluLookAt(*eyex,eyey,lookx,looky,lookz,upx,upy,upz*)` (posición de la camara)

  - `glViewport(*x,y,width,height*)`



### Proyecciones

  + **Paralela**

    + *Ortográfica*
    + *Axiométrica*
    + *Oblicua*

  + **Perspectiva**
    Parametros: centro de proyección, campo de visión, dirección de proyección, vector vertical.
    + *1-punto*
    + *2-puntos*
    + *3-puntos*


