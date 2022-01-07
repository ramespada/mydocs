//      program Hashing
//
//         use HashFunction
//         use HashTable
//         use HashSort
//         
//         implicit none
//          character(len=*),intent(in) :: str
//          integer :: hash
//          integer :: i
//      
//          hash = 5381
//      
//          do i=1,len(str)
//              hash = (ishft(hash,5) + hash) + ichar(str(i:i))
//          end do
//      
//      end program
