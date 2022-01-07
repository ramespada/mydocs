# Transformaciones
--
> Veamos como transformar los objetos para que representen distintas formas de movimiento (traslaciones, rotraciones) y deformaciones (estiramientos y compresiones).


Las transformaciones van a resultarnos útiles para:
  - Posicionar elementos en la escena 3D
  - Modelar la escena, representar movimientos de los elementos.
  - 

### Traslación
![\bf{\hat{x}} = \bf{x} + \bf{u}](http://www.sciweavers.org/tex2img.php?eq=1%2Bsin%28mc%5E2%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)


### Rotación
![\bf{\hat{x}} = \bf{R\,x}](http://www.sciweavers.org/tex2img.php?eq=1%2Bsin%28mc%5E2%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)

### Estiramiento

#### Deformaciones normales
![\bf{\hat{x}} = \bf{\underline{\underline{D}}}\, \bf{x}](http://www.sciweavers.org/tex2img.php?eq=1%2Bsin%28mc%5E2%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)


#### Deformaciones transversales

![\bf{\hat{x}} = \bf{\underline{\underline{A}}}\, \bf{x}](http://www.sciweavers.org/tex2img.php?eq=1%2Bsin%28mc%5E2%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=)



## Transformaciones con `openGL`

- `glTranslate(*u, v, w*)`
- `glRotate(*angulo, vx, vy, vz*)`: Rotación respecto del vector de coordenadas (*vx,vy,vz*)
- `glScale(*sx, sy, sz*)`
- `glLoadMatrix(*array*)`: Carga matriz de transformación.
-  `glMultMatrix(*array*)` : Multiplica la matriz cargada por el vector que se ponga como argumento. 
- `glLoadIdentity()`: Carga la matriz identidad.



