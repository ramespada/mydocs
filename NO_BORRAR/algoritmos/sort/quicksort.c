//!***************************************************************
//!*                      Q U I C K   S O R T                    *
//!* ----------------------------------------------------------- *
//!Note: This method is less efficient then the Heapsort method, *
//!      in particular when the given array is nearly sorted.    *
//!*                                                             *
//!*************************************************************** 

#include <stdio.h>
 
void quicksort(int *A, int len);
 
int main (void) {
  int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  int n = sizeof a / sizeof a[0];
 
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
 
  quicksort(a, n);
 
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
 
  return 0;
}
 
void quicksort(int *A, int len) {
  if (len < 2) return;
 
  int pivot = A[len / 2];
 
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
 
    if (i >= j) break;
 
    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }
 
  quicksort(A, i);
  quicksort(A + i, len - i);
}
 

//      module quickSort
//        implicit none
//
//        contains
//          subroutine sort(lista)
//            implicit none
//              integer :: lista
//              integer :: n
//              integer :: pivot,q,l,r !pivot,pivot index,left, right
//
//              n=size(l)
//              q=floor(n/2) !pivot inicial
//              l=1;r=n
//            do while (q<=n)
//              do  while (l<q .and. r>q)
//                  pivot=lista(q)
//                  if (pivot> lista(l))
//                    do r=n,q+1,-1
//                      if (lista(r)<pivot)
//                      lista([l,r])=lista([r,l])
//                      l=l+1
//                      exit
//                    end if
//                    end do
//                  end if
//              end do
//
//              if (l>1) then !Entonces 
//                 q=q-1
//              else 
//                q=q+1
//              end if
//            end do
//
//            end subroutine
//           
//      end module
//
//
//!***********************************************************
//!* Sorts an array ARR of length N into ascending numerical *
//!* order using the Quicksort algorithm. N is input, ARR is *
//!* replaced on output by its sorted rearrangement.         *
//!*********************************************************** 
//Subroutine QCKSRT(N,ARR)
//
//  Parameter(M=7,NSTACK=50,FM=7875.,FA=211.,FC=1663.,FMI=1./FM)
//! Here M is the size of subarrays sorted by straight insertion, 
//! NSTACK is the required auxuliary storage, and the remaining
//! constants are used by the random generating statements.
//
//   Dimension ARR(N), ISTACK(NSTACK)
//   JSTACK=0
//   L=1; IR=N; FX=0.
//10 If (IR-L.LT.M) Then
//     Do 13 J=L+1, IR
//	   A=ARR(J)
//	   Do 11 I=J-1,1,-1
//	     If (ARR(I).LE.A) Go To 12
//		 ARR(I+1)=ARR(I)
//11     Continue
//       I=0
//12     ARR(I+1)=A
//13   Continue
//     If(JSTACK.EQ.0) Return
//	 IR=ISTACK(JSTACK)
//	 L=ISTACK(JSTACK-1)
//	 JSTACK=JSTACK-2
//   else
//     I=L; J=IR
//	 FX=MOD(FX*FA+FC,FM) !Generate a random integer IQ between L and IR inclusive.
//	 IQ=L+(IR-L+1)*(FX*FMI)
//	 A=ARR(IQ)
//	 ARR(IQ)=ARR(L)
//20   Continue
//       If (J.GT.0) Then
//21       If(A.LT.ARR(J)) Then
//           J=J-1
//		   Go To 21
//         End If
//	   End If
//	   If (J.LE.I) Then
//	     ARR(I)=A
//		 Go To 30
//	   End If
//	   ARR(I)=ARR(J)
//	   I=I+1
//22     If (I.LE.N) Then
//         If (A.GT.ARR(I)) Then
//		   I=I+1
//		   Go To 22
//		 End If
//	   End If
//	   If (J.LE.I) Then
//	     ARR(J)=A
//		 I=J
//		 Go To 30
//	   End If
//	   ARR(J)=ARR(I) 	  	    
//	   J=J-1	 	 
//     Go To 20
//30   JSTACK=JSTACK+2
//     If (JSTACK.GT.NSTACK) Pause 'NSTACK too small!'
//	 If (IR-I.GE.I-L) Then
//	   ISTACK(JSTACK)=IR
//	   ISTACK(JSTACK-1)=I+1
//	   IR=I-1
//	 Else
//	   ISTACK(JSTACK)=I-1
//	   ISTACK(JSTACK-1)=L
//	   L=I+1
//	 End If    	 	 	    		   
//   End If
//   Go To 10
//End
//  
