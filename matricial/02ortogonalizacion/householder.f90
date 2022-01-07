module householder
  implicit none
  contains

   subroutine ortogonalizacion(A,Q)
    !Ortogonaliza A, aplicando reflexiones
     implicit none
     real :: A(:,:), Q(:,:)
     real, allocatable  :: Id(:,:), P(:,:) 
     real, allocatable :: x(:,:),u(:,:),v(:,:)
     integer :: n,m,i,j,k
     n=ubound(A,1)
    
     allocate(Id(n,n))
     Id=A;Id=0.0;forall(i = 1:n) Id(i,i) = 1.0
    
    Q=A
    do i=1,n-1  ! Para cada columna de A
            allocate(x(n+1-i,1));
            allocate(u(n+1-i,1));
            allocate(v(n+1-i,1));
            allocate(P(n+1-i,n+1-i))
    
            x(:,1) =Q(i:n,i) !Tomo un vector de col(A)
            u(:,1)=x(:,1)-norm2(x)*sign(1.0,-x(1,1))*Id(i:n,i) !Calculo la diferencia con |x|ei
            v=u/norm2(u)   !Lo normalizo (vector a usar como reflector)
            P=Id(i:n,i:n)- (2*matmul(v,transpose(v)) )!Calculo la matriz de reflexion
            !Aplico la reflección a cada columna de A.
            do j=i,n
             Q(i:n,j)=matmul(P,Q(i:n,j))
            end do
    
            deallocate(x);
            deallocate(u);
            deallocate(v)
            deallocate(P)
    end do	
    end subroutine
end module
