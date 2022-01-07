program asa

      use fact_QR
      !use givens
      implicit none
       integer, parameter :: n = 4
       real :: A(n, n) = reshape([16.0,  5.0,  9.0,  4.0, &
                                   3.0, 10.0,  6.0, 15.0,&
                                   2.0, 11.0,  7.0, 14.0,&
                                  13.0,  8.0, 12.0,  1.0], [n, n])
       real :: q(n, n), r(n, n)

       print*, "A:"
       print*, A

       call qr(A,q,r)

       print*, "Q:"
       print*, Q
       print*, "R:"
       print*, R
end program 
