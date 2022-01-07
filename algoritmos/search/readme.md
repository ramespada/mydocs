# Searching

> Algoritmos de búsqueda


## Búsqueda Lineal

Para listas no necesariamente ordenadas, el algoritmo de *fuerza bruta* sería recorrerla elemento por elemento chequiando en cada instante si coincide con el elemento buscado (*target*) [`./linsearch.c`](./linsearch.c).


## Búsqueda Binaria

Para listas ordenadas. Un algoritmo significativamente más rápido [`./binsearch.c`](./binsearch.c).

```fortran
  function binsearch(A,n,target) result(position)
       implicit none
        integer, intent(in) :: n
        integer, intent(in) :: A(:)
        integer, intetn(in) :: target
        integer             :: i,position,R,L,M
      
        do while(L+1>=R) 
            M=(L+R)/2
            if(target< A(M) ) then
               R=M
             else if (target>A(m)) then
               L=M
             else
               position=M 
               return
            end if
        end do
        
        position=0
  end function
```



## Quick Search

[`./quicksearch.c`](./quicksearch.c)
