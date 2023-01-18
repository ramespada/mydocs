    module fact_QR
      
      !use grams_schmidt
      use householder
      !use givens
      
      implicit none
      contains
        
      subroutine qr(A,Q,R)
                implicit none
                integer :: n,i,j
                real :: A(:,:),Q(:,:),R(:,:)
                !real, dimension(:,:) :: Q, R

                
                
                n=ubound(A,1)
                call ortogonalizacion(A,Q)

                !Esta parte esta mal:
                R=matmul(Q,A)

      end subroutine

    end module
