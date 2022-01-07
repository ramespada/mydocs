c Objetivo:
c	Resolver  A x = b
c
c Rutinas:
c	2 tipos:
c 		- simple: -SV
c			Resuelve, factorizando A, y reemplazando la solución b por x
c
c		- expert: -SVX
c			Resuelve A* x = b  (con la adjunta de A)
c			Estima numero de condicion de A
c			Refina solución
c			Equilibra el sistema si A está pobremente escalado
c

c Rutinas computacionales usadas:
c		- Factorización:
c				- A = PLU    (en general) P=matriz de permutaciones
c				- A = LU     (matrices sin ceros en la diagonal)
c				- A =U*U=LL* (Cholesky, para Hermitianas >0) 
c			   - A = LDL*   (para Hermitianas tridiagonales e indefinidas)
c		- Métodos iterativos

c	Ejemplo:
	program main

	implicit none

	real:: A(3,3), x(3),b(3)
	integer :: i,j,pivot(3),ok

	A(1,:)=(/2.0,0.0,3.0/);
	A(2,:)=(/0.0,1.0,0.0/);
	A(3,:)=(/0.0,0.0,1.0/);

	b=(/1.0,2.0,3.0/)

	x=b
	
	print*,'La matriz A:';print*,A
	print*,'El vector b:';print*,b

	call SGESV(3, 1, A, 3, pivot, x, 3, ok)

	print*,'El vector x:';print*,x

	!print*,dot_product(A(1,:),x), dot_product(A(2,:),x), dot_product(A(3,:),x)
	print*,matmul(A,x)

	end program main
