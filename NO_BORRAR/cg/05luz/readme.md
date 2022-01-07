# Luz

>
---
## Color 

En computación gráfica hay dos sistemas de colores que se utilizan predominantemente:
  1.**RGL**  (*red-green-blue*)
      - Generalmente se define con 6 valores hexadecimales (16 valores cada dígito). Dos dígitos por color. 
    

  2.**HSV**  (*hue-saturation-value*)


---
## Luz

El color es una propiedad intrínseca de los objetos (podemos decir que a cada objeto le corresponde un color de base **c{r}, c{g}, c{b}**), sin embargo para que este color se manifieste debe ser impactado por una *fuente de luz*, vamos a llamar a esta fuente **luz ambiente**.

Cuando la luz impacta un cuerpo se *refleja*, la reflexión aunque ocurre en un amplio rango de direcciones (depende de la superficie del cuerpo), lo hace preferentemente en algunas. Siguiendo la *ley de Lambert*: La luz se refleja en cada dirección proporcional al angulo que se forma entre la normal y la dirección de impacto, multiplicada por una constante de **difusión**. 
 

Teniendo en cuenta estos 3 procesos podemos escribir para cada color (rojo-verde-azul) las siguientes ecuaciones:

![I_{r} = b_{r}   (k_{amb}  + k_{dif}f <N, l>) + lc k_{spec} <n, l>^{g} ]()
![I_{g} = b_{g}   (k_{amb}  + k_{diff} <N, l>) + lc k_{spec} <n, l>^{g} ]()
![I_{b} = b_{b}   (k_{amb}  + k_{diff} <N, l>) + lc k_{spec} <n, l>^{g} ]()

donde:
c:color base
k_{*}coefs de luz ambiente, difusión y especular
lc: color de la fuente de luz
g= *glassiness* coef.

## Luz en openGL
Modelos de luz:
`glLightModel(*paramName, paramValue*)`
Parámetros:
   + `GL_LIGHT_MODEL_AMBIENT`
   + `GL_LIGHT_MODEL_LOCAL_VIEWER`
   + `GL_LIGHT_MODEL_TWO_SIZE`
   + `GL_LIGHT_MODEL_COLOR_CONTROL`


### Luz ambiente:
No viene de ninguna fuente en particular.

`GL_LIGHT_MODEL_AMBIENT`
```cpp
// sets global ambient light
GLfloat lmodel_ambient[]={0.2,0.2,0.2,1.0};
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
```


### Luz direccional y posicional
Direccional:
```cpp
// sets GL_LIGHT0 with direction (x=1.0,y=1.0,z=1.0) at an
infinite position (w=0.0) in homogeneous coordinates
Glfloat light_position[]={1.0,1.0,1.0,0.0};
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
```

Posicional:
```cpp
// sets GL_LIGHT0 at the position (x=1.0,y=1.0,z=1.0) that is
finite (w≠0.0) in homogeneous coordinates
Glfloat light_position[]={1.0,1.0,1.0,1.0};
glLightfv(GL_LIGHT0, GL_POSITION, light_position);

```

---
## Materiales
Propiedades de materiales:
  -`GL_AMBIENT`
  -`GL_DIFFUSE`
  -`GL_SPECULAR`
  -`GL_SHINIESS`
  -`GL_EMISSION`

Para modificar las propiedades de un material:

`glMaterial*(*cara, paramName, paramValues*)`

### Normals

`glNormal3(*nx,ny,nz*)`
``

---
## Sombreado/pintado (*shading*)
Hay distintas estrategias:
  + Sombreado plano (todo del mismo color) **`glShadeModel(GL_FLAT)`**
    - usa el valor de uno de los vértices de la superficie.
    - es rápido.
    - poco realista (misma intensidad en toda la superficie).


  + *Goraud  Shadding* (interpolación lineal) **`glShadeModel(GL_SMOOTH)`**
    - es rápido.
    - suaviza superficie.
    - no muy realista. 
    - tiende a eliminar el efecto especular.
  
  + *Phong Shadding* (interpolación lineal orientada) **`glShadeModel(GL_SMOOTH)`**
    Interpola linealmente las normales de los vértices
    - costoso computacionalmente.
    -
    -


---
## Sombras

Estrategias:
Basado en iluminación indirecta:
  + Ray tracing (incorpora tapdo y  reflexiones)
  + Radiosity (balance radiativo)

Basado en iluminación directa:
  + Ray casting


---
## Textura



### *Scan conversion*
