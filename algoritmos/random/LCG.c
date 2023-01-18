#include <stdio.h>
#include <math.h>
 
int n=10;

int main()
{
      int random[n];

      int seed=12345; 	  //init value
      int m=pow(2,12);    //modulus
      int a=10;           //multiplier
      int c=7;            //increment

      int i; 
 
      random[0]=seed;

      for (i=1;i<n;i++){
      	random[i]=(random[i-1]*a+c)%m;
      }

      for (i=1;i<n;i++){
	printf("%d\n",random[i]);
      }

      return 0;
}


// Implementación FORTRAN
//!*=================================*!
//!* Linear congruential generator   *!
//!*       (Lehmer generator)        *!
//!*                                 *!
//!*---------------------------------*!
//
//module LCG
//  implicit none
//  
//  contains
//
//    function random(n)
//      implicit none
//      integer, parameter :: n
//      integer :: random(n)
//
//      integer :: seed=12345 !init value
//      integer :: m=2**32    !modulus
//      integer :: a=10       !multiplier
//      integer :: c=7        !increment
//
//      integer :: i !index
// 
//      random(1)=seed
//
//      do i=2,n
//        random(i)=mod(random(i-1) * a + c , m)
//      end do
//
//    end function
//
//end module
//
