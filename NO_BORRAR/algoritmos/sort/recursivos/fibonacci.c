#include <stdio.h>

int fibonacci(int n){
	if (n<=2){
		return 1;
	}
	else{
		return fibonacci(n-2)+fibonacci(n-1);
	}
}


int main(){
	int n;

	printf("Ingrese un numero entero");
	scanf("%d",&n);


	printf("El %d-ésimo numero de la serie de fibonacci es %d\n",n,fibonacci(n));

	return 0;
}




//Implentación en FORTRAN
//	program factorial 
//	implicit none
//	integer ::  n
//
//	print*,"Ingrese un entero"
//	read*, n
//	
//	print*,"El ",n,"-éstimo numero de fibonacci es:",FIBONACCI(n)
//
//	contains
//
//	recursive function FIBONACCI (N) result (F)
//		implicit none
//		integer, intent (in) :: N
//		real :: F
//		if (N <= 2) then
//			F=l
//		else
//			F = FIBONACCI(N-l) + FIBONACCKN-2)
//		end if
//		end function FIBONACCI
//
//	end program
