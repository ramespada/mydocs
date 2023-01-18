#include <stdio.h>
int main() {
    int n,i,ok,p;
    printf("Introduce un número entero:");
    scanf("%d",&n);
    for(i = 1;i<=n;i++) {
        ok = 0;
        for(p = 2;p<i;p++) {
            if(i%p == 0) { ok = 1; break; }
        }
        if(ok != 1) printf("%d, ",i); 
    }
    printf("\n");
    return 0;
}
//Implementación FORTRAN:
//   module cribaEratostenes
//  ! Criba de Eratóstenes.
//  !***Arma una lista con todos los primos menores a "n".***
//      implicit none
//      contains
//
//        function criba(N)  result(criba)
//	         implicit none
//	         integer :: N
//           	 integer, allocatable :: criba(:)
//	         integer :: i,j
//
//        	allocate(criba(n));	criba=(/(i,i=1,n)/)
//        
//          do j=2,n,1
//        	  if (criba(j)==0) then
//        	     cycle
//        	  else
//        	     criba((/(i,i=j*2,n,j)/))=0
//        	  end if
//          end do
//
//          criba=pack(criba,criba/=0) 
//        end function
//        
//      end module
