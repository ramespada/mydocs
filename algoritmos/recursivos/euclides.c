#include<stdio.h>
#include<math.h>

int MCD(int n,int m){
	int G;
	if (m==0){
		G=n;
	}
	else{
		G=MCD(n, m%n);
	}

	return G;
}

int main(){
	int n,m;

	printf("Introduce un número entero:");
    	scanf("%d",&n);

	printf("Introduce un número entero:");
    	scanf("%d",&m);

	printf("el maximo comun divisor entre %d y %d, es : %d\n",n,m,MCD(n<m? n : m,n<m? m : n ));

	return 0;
}

// Implentación en FORTRAN
//	program Euclides 
//	implicit none
//	integer ::  n
//
//	print*,"Ingrese un entero"
//	read*, n
//	
//	print*,n,"!=",MCD(n)
//
//	contains
//
//	recursive function MCD (M, N) result (G)
//		implicit none
//		integer, intent (in) :: M, N
//		integer :: G
//		if (N == 0) then
//			G = M
//		else
//			G = MCD(N, modulo (M, N))
//		end if
//	end function MCD
//
//	end program
