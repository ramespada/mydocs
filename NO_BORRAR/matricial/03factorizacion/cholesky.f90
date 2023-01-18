     program cholesky

        !implicit none
        ! 
        !INTEGER, PARAMETER :: m=3 !rows
        !INTEGER, PARAMETER :: n=3 !cols
        !REAL, DIMENSION(m,n) :: A 
        !REAL, DIMENSION(m,n) :: L
        !REAL :: sum1, sum2
        !INTEGER i,j,k
        ! 
        !! Assign values to the matrix
        !A(1,:)=(/ 25,  15,  -5 /)   
        !A(2,:)=(/ 15,  18,   0 /)  
        !A(3,:)=(/ -5,   0,  11 /)
        !! !!!!!!!!!!!another example!!!!!!!
        !! A(1,:) = (/ 18,  22,   54,   42 /) 
        !! A(2,:) = (/ 22,  70,   86,   62 /) 
        !! A(3,:) = (/ 54,  86,  174,  134 /) 
        !! A(4,:) = (/ 42,  62,  134,  106 /)
        ! 
        ! 
        ! 
        ! 
        ! 
        !! Initialize values
        !L(1,1)=real(sqrt(A(1,1)))
        !L(2,1)=A(2,1)/L(1,1)
        !L(2,2)=real(sqrt(A(2,2)-L(2,1)*L(2,1)))
        !L(3,1)=A(3,1)/L(1,1)
        !
        !call factorizacion(A,L)
        !print*,L

      contains
        subroutine factorizacion(A,L)
                !Cholesky decomposition (Para A, normal)
                implicit none
                integer :: j,n
                real    :: A(:,:),L(:,:)
   
                n=ubound(A,1)
                !L(1,1)=sqrt(A(1,1));L(2:,1)=A(2:,1)/L(1,1)
   
                do j=1,n
                        L(j,j)=sqrt(A(j,j)-dot_product(L(j,:j-1) , L(j,:j-1)))
                   if (j < n) then
                        L(j+1:,j)=(A(j+1:,j)-matmul(L(j+1:,:j-1),L(j,:j-1) ))/L(j,j)
                   end if
                end do
        end subroutine 
    
    end program
