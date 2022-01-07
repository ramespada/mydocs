program determinante
        implicit none
          real, dimension(3,3) :: A
          data A/ 2,-1, 1,-1,-2, 1,-1,-1,-1/
          print*,"Matriz A =" 
          write(*,'(3f6.2)') A
          write(*,'(a9 f6.3)') "det(A): ",det(A,3, 0)
          write(*,'(a9 f6.3)') "per(A): ",det(A,3, 1)
         
        contains
         
          recursive function det(a,n,permanent) result(accumulation)
            ! setting permanent to 1 computes the permanent.
            ! setting permanent to -1 computes the determinant.
            real, dimension(n,n), intent(in) :: a
            integer, intent(in) :: n, permanent
            real, dimension(n-1, n-1) :: b
            real :: accumulation
            integer :: i, sgn
            if (n .eq. 1) then
              accumulation = a(1,1)
            else
              accumulation = 0
              sgn = 1
              do i=1, n
                b(:, :(i-1)) = a(2:, :i-1)
                b(:, i:) = a(2:, i+1:)
                accumulation = accumulation + sgn * a(1, i) * det(b, n-1, permanent)
                sgn = sgn * permanent
              enddo
            endif
          end function det


end program
