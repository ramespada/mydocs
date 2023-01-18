#include<stdio.h>
int factorial(int n){
	if (n==1){return 1;}
	else{return n*factorial(n-1);}
}

int main(){
	int n;

	printf("Ingrese un numero entero");
	scanf("%d",&n);

	printf("%d!=%d\n",n,factorial(n));
	return 0;
}

// Implementación en FORTRAN
//	program factorial 
//	implicit none
//	integer ::  n
//
//	print*,"Ingrese un entero"
//	read*, n
//	
//	print*,n,"!=",factorial(n)
//
//	contains
//
//	recursive function factorial(N) result(F)
//		implicit none		
//		 integer, intent(in) :: N
//		 real :: F
//		
//		if(N<=l)then
//	 		F= 1
//	 		else
//	 		F = N*factorial(N-1)
//	 	end if
//	 end function factorial
//
//	end program
