program SAXPY

  use omp_lib

  implicit none
  real :: x(2**20), y(2**20)
  real :: a,start,finish
  integer :: i,np
  !init
  CALL RANDOM_NUMBER(x)
  y=1.0
  a=2.0

  call cpu_time(start)
  !$omp parallel
  !$OMP DO
  do i=1,size(x)
    y(i)= a * x(i) + y(i)
  enddo
  !$OMP END DO
  np=omp_get_num_threads()
  !$omp end parallel
  call cpu_time(finish)
  print '("Time Avg = ",f12.8," seconds. w/",i0,"threads")',finish-start,np 

endprogram
