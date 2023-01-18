       module givens
       implicit none

      contains
        
      subroutine ortogonalizacion(A,Q)
        
        implicit none
        integer :: n
        real,intent(in) :: A(:,:)
        real,intent(inout) :: Q(:,:)
        real, allocatable  :: Id(:,:), G(:,:)
        integer :: i,j,k
        real :: theta,r,c,s
        
        n=size(A,1)
        allocate(Id(n,n))
        Id=0.0; forall(i=1:n) Id(i,i)=1.0
        
        Q=A
        do j=1,n-1, 1   !j-ésima columna
                do i=n,n-j,-1   !i-ésima fila
        
                      if (i<=j) cycle
                      if (abs(Q(i,j))<1e-5) cycle
        
                G=Id
                theta=atan2(-Q(i,j),Q(j,j))
                c=cos(theta)
                s=sin(theta)
                !r=sqrt(A(i,j)*A(i,j) + A(j,j)*A(j,j)) 
                !c= A(j,j)/r  
                !s=-A(i,j)/r

                G(j,j)=c; G(j,i)=-s
                G(i,j)=s; G(i,i)= c
                
                Q=matmul(G,Q)
        
                end do
        end do
        end subroutine
        end module
