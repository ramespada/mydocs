//**********************************************
//*            M E R G E   S O R T             * 
//*                (n*logn)                    *
//**********************************************
#include <stdio.h>
#include <stdlib.h>
 
void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}
 
void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
 
int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    merge_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
//        module mergeSort
//    
//          contains
//    
//          subroutine sort(lista)
//            implicit none
//             integer :: lista(:)
//             integer :: n,n2,p,i,j,jp,j2p
//             logical :: impar=.false.
//              
//             n=size(lista)
//             if (mod(n,2)/=0) then
//               impar=.true.
//               n=n-1
//             end if
//             n2=n/2
//             
//             p=1;i=1
//             do while ( p<=n2 )
//                p=2**i
//                do j=1,n-p,p
//                  jp=j+p; j2p=j+2*p
//      call merge(lista(j:jp-1),lista(jp:j2p),lista(j:j2p))
//                end do
//                i=i+1
//             end do
//              
//              !Si es n es impar, hay que incorporar el último elemento
//              if (impar)  then
//                call merge(lista(1:n),lista((n+1):(n+1)), lista)
//              end if
//          end subroutine
//        
//    
//          subroutine merge(a,b,c)  
//            implicit none
//             integer, intent(in) :: a(:),b(:)
//             integer :: c(:)
//             integer :: n,m,nm,i,j,k  !indices: i(a) ; j(b) ; k(c)
//            
//             n=size(a);m=size(b); nm=n+m
//    
//            i=1;j=1;k=1
//            do while (i<=n .and. j<=m)
//              if (a(i)>b(j)) then   !saco de b
//                c(k) = b(j); j=j+1; k=k+1
//              else                  !saco de a
//                c(k) = a(i); i=i+1; k=k+1
//              end if
//            end do
//
//            if (i>n) then
//              c(k-1:nm)=b(j:m)
//            else if (j>m) then
//              c(k-1:nm)=a(i:n)
//            else
//              continue
//            end if
//          end subroutine
//    
//        end module
