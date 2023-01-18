c Objetivo:
c	Resolver  min | b - Ax |
c				donde A es una matrix m x n
c					
c if ( m>=n .AND. rank(A)==n) then
c	solución única --> minimos cuadrados
c else
c	infinitas soluciones --> solución de norma mímina  min |x| que cumpla.


c Rutinas:
c	Sólo matrices generales (-GE-)!!
c

c	Si rank(A)=min(m,n)  (sistema sobredeterminado)
c			- (-LS)  Utiliza factorización QR / LQ
c			Realiza cuadrados mínimos si m>=n
c			Solución de norma mínima  si m< n

c	Si A es rango deficiente se resuelve:
c		- Por factorización ortogonal completa  
c			- (-LSX)
c			- (-LSY) (un poco más rápido que LSX, pero requiere mas recursos)
c		- Por descomposición en valores singulares
c			- (-LSS)
c			- (-LSD)  usando algoritmo divide-and-conquer
c		
c
c
c
