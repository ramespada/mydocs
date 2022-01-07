module grams_schmidt

      contains
      subroutine ortogonalizacion(A,Z)
        !Proceso de ortonormalización de Gram-Schmidt
        implicit none
        integer 			  :: n,i,j
        real				  :: A(:,:),Z(:,:)
        real,allocatable :: X(:,:),Y(:,:)
        n=ubound(A,1)
        X=A;
        Y=X*0.0 
        Z=0.0
        do i=1,n
                Y(:,i)= X(:,i) 
                do j=1,i
                        Y(:,i)= Y(:,i) - dot_product(X(:,i),Z(:,j))*Z(:,j) 
                end do
                Z(:,i) = Y(:,i)/sqrt(dot_product(Y(:,i),Y(:,i)))
        end do
      end subroutine
end module
