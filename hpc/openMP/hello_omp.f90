program hola

  use omp_lib
  implicit none
  integer :: omp_rank

   !$omp parallel private(omp_rank)
   omp_rank=0
   !$omp_rank = omp_get_thread_num()
   print '("Hello world! ",I0,"/",I0)',omp_get_thread_num(),omp_get_num_threads()
   
   !$omp end parallel

end program

!!Para correrlo:
!! >> gfortran -fopenmp testMP.f
!! >> mpirun -np 4 a.out
