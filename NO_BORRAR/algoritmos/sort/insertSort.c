
#include <stdio.h>
 
void insertion_sort(int *a, int n) {
	for(size_t i = 1; i < n; ++i) {
		int tmp = a[i];
		size_t j = i;
		while(j > 0 && tmp < a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = tmp;
	}
}
 
int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    insertion_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
 

//        module insertionSort
//            implicit none 
//            contains
//                      
//              subroutine sort(lista)
//                implicit none
//                integer :: lista(:)
//                integer :: i,j
//          
//                do i=2,size(lista)  !Scaneamos toda la lista
//                  j=1+count(lista(:i-1)<lista(i))  !Buscamos la posición nueva de l(i)
//                  call insert(lista,i,j)           !Poner el elemento l(i) en l(j)
//                end do
//              end subroutine
//
//              subroutine insert(l,pi,pf) !Inserta l(pi) en l(pf) y re-acomoda l
//                implicit none
//                  integer :: l(:)
//                  integer :: pi,pf  !posición inicial y final
//                  integer :: i
//
//                  l(pf:pi-1)=l([pi,(/(i,i=pf,pi-1)/)]) !Swap
//              end subroutine
//              
//        end module
