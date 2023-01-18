# Factorización

## Tipos de factorizacion


### Factorizacion Lower-Upper (LU)
Descompone la matriz **A** en dos matrices **L** y **U**,

<center>
A = L U
</center>
 donde **L** es triangular inferior, y **U** es triangular superior. [`./LU.f90`](./LU.f90)


### Factorizacion QR

Descompone a la matriz **A** en dos matrices **Q** y **R**,
<center>
A = Q R
</center>
 donde **Q** es una matriz ortogonal (Q<sup>-1</sup>=Q<sup>T</sup>)y **R** es tirangular superior [`./QR.f90`](./QR.f90)


### Factorizacion de Schur
<center>
A = Q U Q<sup>\*</sup>
</center>
donde **Q** es una matriz ortogonal y **U** es una matriz triangular superior cuya diagonal coincide con los autovalores de **A** [`./schur.f90`](./schur.f90)


### Descomposición en valores singulares *(SVD)*
Descompone **A** en tres matrices **U**, **&Sigma;** y **V<sup>&#9733;</sup>**,
<center>
A = U &Sigma; V<sup>&#9733;</sup>
</center>

donde **U** y **V** son matrices unitarias (**U** **U<sup> &#9733; </sup>** = **U<sup> &#9733; </sup>**=**I** )y **&Sigma;** es diagonal cuyos valores son los valores singulares de **A** [`./SVD.f90`](./SVD.f90).


### Forma canónica de Jodan
 Descompone **A** en una matriz **S** y una matriz **J** y la inversa de **S**
(1)
<center>
A = S J S<sup>-1</sup>
</center>

donde A y J son matrices similares, J se conoce coo matriz de Jordan canónica. [`./jordan.f90`](./jordan.f90)
