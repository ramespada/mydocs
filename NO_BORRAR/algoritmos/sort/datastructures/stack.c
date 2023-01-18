//STACK ó Last In, First Out (LIFO)

// C program for array implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent a stack 
struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
  
// Function to return the top from stack without removing it 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    struct Stack* stack = createStack(100); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 
  
    printf("%d popped from stack\n", pop(stack)); 
  
    return 0; 
} 

//module stack
// 
//  public
// 
//  ! Define the data-structure to hold the data
//  type stack_var
//     integer, allocatable :: data(:)
//     integer              :: size = 0
//  end type stack_var
// 
//  ! Set the size of allocated memory blocks
//  integer, parameter, private :: block_size = 10
// 
//contains
// 
//  ! Push ----------------------------------------------------------------------
//  subroutine push(s, e)
//    type(stack_var), intent(inout) :: s
//    integer, intent(in)            :: e
//    integer, allocatable :: wk(:)
//    if (.not. allocated(s%data)) then
//       ! Allocate space if not yet done
//       allocate(s%data(block_size))
// 
//    elseif (s%size == size(s%data)) then
//       ! Grow the allocated space
//       allocate(wk(size(s%data)+block_size))
//       wk(1:s%size) = s%data
//       call move_alloc(wk,s%data)
// 
//    end if
// 
//    ! Store the data in the stack
//    s%size = s%size + 1
//    s%data(s%size) = e
//  end subroutine push
// 
//  ! Pop -----------------------------------------------------------------------
//  function pop(s)
//    integer :: pop
//    type(stack_var), intent(inout) :: s
//    if (s%size == 0 .or. .not. allocated(s%data)) then
//       pop = 0
//       return
//    end if
//    pop = s%data(s%size)
//    s%size = s%size - 1
//  end function pop
// 
//  ! Peek ----------------------------------------------------------------------
//  integer function peek(s)
//    type(stack_var), intent(inout) :: s
//    if (s%size == 0 .or. .not. allocated(s%data)) then
//       peek = 0
//       return
//    end if
//    peek = s%data(s%size)
//  end function peek
// 
//  ! Empty ---------------------------------------------------------------------
//  logical function empty(s)
//    type(stack_var), intent(inout) :: s
//    empty = (s%size == 0 .or. .not. allocated(s%data))
//  end function empty
// 
//end module stack
//!===============================================================================
//!PROGRAM 
//program tstack
//  use stack
//  implicit none
//  type(stack_var) :: s
//  integer         :: v
// 
//  call push(s,1)
//  call push(s,2)
//  call push(s,3)
//  call push(s,4)
// 
//  do
//     if (empty(s)) exit
//     v = pop(s)
//     write(*,'(a,i0)') 'Popped value off stack = ',v
//  end do
//end program tstack
//!===============================================================================
//
//! A stack is a container of elements with   last in, first out   access policy.   Sometimes it also called LIFO.
//
//! The stack is accessed through its top.
//
//! The basic stack operations are:
//
//!       push   stores a new element onto the stack top;
//!       pop   returns the last pushed stack element, while removing it from the stack;
//!       empty   tests if the stack contains no elements.
//
//
//!     Sometimes the last pushed stack element is made accessible for immutable access (for read) or mutable access
//!     (for write):
//
//!           top   (sometimes called peek to keep with the p theme) returns the topmost element without modifying the
//!           stack.
//
//
//!           Stacks allow a very simple hardware implementation.
//
//!           They are common in almost all processors.
//
//!           In programming, stacks are also very popular for their way (LIFO) of resource management, usually memory.
//
//!           Nested scopes of language objects are naturally implemented by a stack (sometimes by multiple stacks).
//
//!           This is a classical way to implement local variables of a re-entrant or recursive subprogram. Stacks are
//!           also used to describe a formal computational framework.
//
//!           See stack machine.
//
//!                          Many algorithms in pattern matching, compiler construction (e.g. recursive descent parsers), and machine
//!                          learning (e.g. based on tree traversal) have a natural representation in terms of stacks.
//
//
//!   Task
//!   Create a stack supporting the basic operations: push, pop, empty. 
