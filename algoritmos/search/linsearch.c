//******************************************************
//*           L I N E A R    S E A R C H               *
//* -------------------------------------------------- *
#include <stdio.h>

int lsearch (int *a, int n, int x) {
    int i = 0, j = n - 1;
    for (i=0;i<n;i++) {
        if (a[i] == x) {
            return i+1;
        }
    }
    return -1;
}


int main () {
    int a[] = {-31, 0, 1, 2, 2, 4, 65, 83, 99, 782};
    int n = sizeof a / sizeof a[0];
    int x = 2;

    printf("%d is at index %d\n", x, lsearch(a, n, x));
    x = 5;

    return 0;
}


//Implementación FORTRAN:
//  module linSearch 
//    implicit none
//
//    contains
//
//      function search(L,target) result(position)
//         implicit none
//          integer, intent(in) :: target
//          integer, intent(in) :: L(:)
//          integer             :: i, position
//          
//          do i=1,size(L)
//            if (target==L(i)) then
//              position=j
//              return
//            end if
//          end do
//          
//          print*,"No se encontró",target
//          position=0
//    end function
//  end module
