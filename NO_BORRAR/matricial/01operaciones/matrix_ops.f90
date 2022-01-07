        program matrix_operations

                implicit none
                real,dimension(3,3) :: A, B
                real,dimension(3)   :: x,y
                real      :: k
                
                k=0.2;
                x=(/1,0,2/);
                y=(/0,2,2/);
                data A/1,2,3,5,5,5,-2,0,1/
                data B/4,2,1,5,1,5,-2,3,3/

                 print*,"A ="; write(*,'(3f6.2)') A
                 print*,"B ="; write(*,'(3f6.2)') B
                 print*,"x ="; write(*,'(3f6.2)') x
                 print*,"y ="; write(*,'(3f6.2)') y

                !Transponer matriz
                print*,"At ="; write(*,'(3f6.2)') transpose(A);

                !SaXPY (Scalar a X Plus Y)
                print*,"k*x+y ="; write(*,'(3f6.2)') k*x+y;

                !Inner (dot) Product
                print*,"<x , y> ="; write(*,'(f6.2)') dot_product(x,y);

                !Gaxpy
                print*,"y + Ax ="; write(*,'(3f6.2)') y+ matmul(A,x);
                
                !Matrix-Matrix Multiplication
                print*,"AB ="; write(*,'(3f6.2)') matmul(A,B);
 
                !Outer Product
                print*,"x * y ="; write(*,'(3f6.2)') spread(x,dim=1,ncopies=size(y))*spread(y,dim=2,ncopies=size(x));
                !print*,spread(x,dim=1,ncopies=size(y))*spread(y,dim=2,ncopies=size(x))

                !Kronecker Product 
        
        end program
