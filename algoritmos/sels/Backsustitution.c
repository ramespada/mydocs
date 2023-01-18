      module backSustitution
        implicit none
        
        contains
        
        subroutine backsustitution(T,b,x)
        
                implicit none
                real, allocatable :: T(:,:)
                real, allocatable :: b(:),x(:)
                integer           :: i
                
                x=b
                do i=size(x),1,-1
                  x(i)=(x(i)-dot_product(T(i,i+1:),x(i+1:)))/T(i,i)
                end do    
              
        end subroutine
      
      end module 
