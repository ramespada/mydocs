#include <stdio.h>
 
void shell_sort (int *a, int n) {
    int h, i, j, t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = a[i];
            for (j = i; j >= h && t < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = t;
        }
    }
}
 
int main (int ac, char **av) {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    shell_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
 
//!***************************************************************
//!*          Sorting an array with the Shell method             *
//!* ----------------------------------------------------------- *
//!* REFERENCE:                                                  *
//!*      "NUMERICAL RECIPES By W.H. Press, B.P. Flannery,       *
//!*       S.A. Teukolsky and W.T. Vetterling, Cambridge         *
//!*       University Press, 1986" [BIBLI 08].                   *
//!* ----------------------------------------------------------- *
//!* SAMPLE RUN:                                                 *
//!*                                                             *
//!* Table to be sorted:                                         *
//!*                                                             *
//!* 102.2 837.1 270.3 484.0 164.8 236.6 805.3 142.6 988.2  23.2 *
//!* 352.8   7.4 745.3 691.9 907.8 674.6 918.7 854.5 894.6 845.9 *
//!* 207.4 116.6 992.9 291.4 974.7 494.5 115.0 262.6 831.1 554.4 *
//!* 135.3 937.0 383.4 567.8 640.7 894.0 147.0 754.9 266.1 673.7 *
//!* 579.2 271.0 345.8 927.9 229.9  31.0 663.1 295.8 823.6  30.0 *
//!*  82.1 987.1   1.7 661.4 580.2 415.0 553.6 577.1 593.7 334.0 *
//!* 853.8 183.1 255.2 793.3 692.3 137.7 820.9 871.2 224.9 814.9 *
//!* 335.0 509.0  53.5 141.2 725.4 462.4 805.6 652.7 641.2 609.3 *
//!*                                                             *
//!* Sorted table (Shell method):                                * 
//!*                                                             *
//!*   1.7   7.4  23.2  30.0  31.0  53.5  82.1 102.2 115.0 116.6 *
//!* 135.3 137.7 141.2 142.6 147.0 164.8 183.1 207.4 224.9 229.9 *
//!* 236.6 255.2 262.6 266.1 270.3 271.0 291.4 295.8 334.0 335.0 *
//!* 345.8 352.8 383.4 415.0 462.4 484.0 494.5 509.0 553.6 554.4 *
//!* 567.8 577.1 579.2 580.2 593.7 609.3 640.7 641.2 652.7 661.4 *
//!* 663.1 673.7 674.6 691.9 692.3 725.4 745.3 754.9 793.3 805.3 *
//!* 805.6 814.9 820.9 823.6 831.1 837.1 845.9 853.8 854.5 871.2 *
//!* 894.0 894.6 907.8 918.7 927.9 937.0 974.7 987.1 988.2 992.9 *
//!*                                                             *
//!*                                                             *
//!***************************************************************
//PROGRAM SORT2
//
//real    A(100)     !Table to be sorted
//real    MAX_VALUE  !Maximum value of table
//integer Count(1)   !Current value of system clock
//
//  !initialize random number generator
//  call System_Clock(Count(1))
//  call Random_Seed(Put=Count)
//
//  N=80  !initialize size of table
//  MAX_VALUE = 1000
//
//  !generate random table of numbers (from 0 to 1000)
//  do i=1, N
//    call Random_Number(x)  !returns random x >= 0 and <1  
//    A(i)=MAX_VALUE*x
//  end do
//
//  print *,' '
//  print *,'Table to be sorted:'
//  call TWRIT(N,A)
// 
//  !call sorting subroutine
//  call SHELL(N,A)
//
//  print *,' '
//  print *,'Sorted table (Shell method):'
//  call TWRIT(N,A)
//
//  print *,' '
//  stop
//
//END
//
//
//!*****************************************************
//!* Sorts an array ARR of length N in ascending order *
//!*            by the Shell-Mezgar method             *
//!* ------------------------------------------------- *
//!* INPUTS:                                           *
//!*	    N	  size of table ARR                  *
//!*          ARR	  table to be sorted                 *
//!* OUTPUT:                                           *
//!*	    ARR   table sorted in ascending order    *
//!*                                                   *
//!* NOTE: The Shell method is a N^3/2 routine and can *
//!*       be used for relatively large arrays.        *                             *
//!*****************************************************         
//SUBROUTINE SHELL(N,ARR)
//parameter(ALN2I=1./0.69314718,TINY=1.E-5)
//  real ARR(N)
//  LOGNB2=INT(ALOG(FLOAT(N))*ALN2I+TINY)
//  m=n
//  do nn=1,LOGNB2
//    m=m/2; k=n-m
//    do j=1,k
//      i=j
//10    continue
//      l=i+m
//      if(ARR(l).LT.ARR(i)) then
//        t=ARR(i)
//	ARR(i)=ARR(l)
//	ARR(l)=t
//	i=i-m
//	if(i.GE.1) GOTO 10
//      end if
//    end do
//  end do
//  return
//END
//
//!write table of size N to standard output
//SUBROUTINE TWRIT(N,ARR)
//real ARR(N)
//  print *,' '
//  WRITE(*,10) (ARR(I),I=1,N)
//  return
//10 FORMAT(10F6.1)
//END
//
//!end of file sort2.f90
//
