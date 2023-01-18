
// Implemetnación FORTRAN
//!*======================================*!    
//!*      Middle Square Algorithm         *!
//!*         (John Von Neuman)            *!
//!*--------------------------------------*!
//!*                                      *!
//!*======================================*!    
//module MSA
//  implicit none
//
//  contains
//
//  function random(n)
//
//    implicit none
//    integer, parameter :: n
//    integer :: random(n)
//    
//    integer :: seed=12345 !init value
//    
//    integer :: i
//
//    random(1)=seed
//    do i=2,n
//      random(i)= middle4(random(i-1)**2)
//    end do
//
//  end function
//
//  function middle4(n) 
//    implicit none
//    integer :: n
//    integer :: middle4,digitos
//    
//    digitos=log10(n)+1
//    
//    if (digitos<6) then
//        n=n+10**(9-digitos)
//    end if
//
//    m1=10**(digitos/2 +1)
//    m2=10**(digitos/2 +0)
//    m3=10**(digitos/2 -1)
//    m4=10**(digitos/2 -2)
//
//    middle4=mod(n,m1)*1000+mod(n,m2)*100+mod(n,m3)*10+mod(n,m4)
//    
//  end function
//end module
