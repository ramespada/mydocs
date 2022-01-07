// QUEUE ó First-IN First-OUT (FIFO)

#include <stdio.h>
#include <stdlib.h>

// Data structure for queue
struct queue
{
	int *items;	// array to store queue elements
	int maxsize;	// maximum capacity of the queue
	int front;	// front points to front element in the queue (if any)
	int rear;	// rear points to last element in the queue
	int size;	// current capacity of the queue
};

// Utility function to initialize queue
struct queue* newQueue(int size)
{
	struct queue *pt = NULL;
	pt = (struct queue*)malloc(sizeof(struct queue));
	
	pt->items = (int*)malloc(size * sizeof(int));
	pt->maxsize = size;
	pt->front = 0;
	pt->rear = -1;
	pt->size = 0;

	return pt;
}

// Utility function to return the size of the queue
int size(struct queue *pt)
{
	return pt->size;
}

// Utility function to check if the queue is empty or not
int isEmpty(struct queue *pt)
{
	return !size(pt);
}

// Utility function to return front element in queue
int front(struct queue *pt)
{
	if (isEmpty(pt))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	return pt->items[pt->front];
}

// Utility function to add an element x in the queue
void enqueue(struct queue *pt, int x)
{
	if (size(pt) == pt->maxsize)
	{
		printf("OverFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	printf("Inserting %d\t", x);

	pt->rear = (pt->rear + 1) % pt->maxsize;	// circular queue
	pt->items[pt->rear] = x;
	pt->size++;

	printf("front = %d, rear = %d\n", pt->front, pt->rear);
}

// Utility function to remove element from the queue
void dequeue(struct queue *pt)
{
	if (isEmpty(pt)) // front == rear
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	printf("Removing  %d\t", front(pt));

	pt->front = (pt->front + 1) % pt->maxsize;	// circular queue
	pt->size--;

	printf("front = %d, rear = %d\n", pt->front, pt->rear);
}

int main()
{
	struct queue *pt = newQueue(5);

	enqueue(pt, 1);
	enqueue(pt, 2);
	enqueue(pt, 3);
	enqueue(pt, 4);

	dequeue(pt);
	dequeue(pt);
	dequeue(pt);
	dequeue(pt);

	enqueue(pt, 5);
	enqueue(pt, 6);

	printf("size = %d\n", size(pt));

	if (isEmpty(pt))
		printf("Queue is empty");
	else
		printf("Queue is not empty");

	return 0;
}
//module FIFO
//  use fifo_nodes
//! fifo_nodes must define the type fifo_node, with the two field
//! next and valid, for queue handling, while the field datum depends
//! on the usage (see [[FIFO (usage)]] for an example)
//!  type fifo_node
//!     integer :: datum
//!     ! the next part is not variable and must be present
//!     type(fifo_node), pointer :: next
//!     logical :: valid
//!  end type fifo_node
// 
//  type fifo_head
//     type(fifo_node), pointer :: head, tail
//  end type fifo_head
// 
//contains
// 
//  subroutine new_fifo(h)
//    type(fifo_head), intent(out) :: h
//    nullify(h%head)
//    nullify(h%tail)
//  end subroutine new_fifo
// 
//  subroutine fifo_enqueue(h, n)
//    type(fifo_head), intent(inout) :: h
//    type(fifo_node), intent(inout), target :: n
// 
//    if ( associated(h%tail) ) then
//       h%tail%next => n
//       h%tail => n
//    else
//       h%tail => n
//       h%head => n
//    end if
// 
//    nullify(n%next)
//  end subroutine fifo_enqueue
// 
//  subroutine fifo_dequeue(h, n)
//    type(fifo_head), intent(inout) :: h
//    type(fifo_node), intent(out), target :: n
// 
//    if ( associated(h%head) ) then
//       n = h%head
//       if ( associated(n%next) ) then
//          h%head => n%next
//       else
//          nullify(h%head)
//          nullify(h%tail)
//       end if
//       n%valid = .true.
//    else
//       n%valid = .false.
//    end if
//    nullify(n%next)
//  end subroutine fifo_dequeue
// 
//  function fifo_isempty(h) result(r)
//    logical :: r
//    type(fifo_head), intent(in) :: h
//    if ( associated(h%head) ) then
//       r = .false.
//    else
//       r = .true.
//    end if
//  end function fifo_isempty
// 
//end module FIFO
//
//
//
//!Task
//
//!Implement a FIFO queue.
//
//!Elements are added at one side and popped from the other in the order of insertion.
//
//
//!Operations:
//
//   !   push   (aka enqueue)   - add element
//  !    pop     (aka dequeue)   - pop first element
// !     empty   - return truth value when empty
//
//
//!Errors:
//
// !     handle the error of trying to pop from an empty queue (behavior depends on the language and platform)
//
//
//!See
//
//!      Queue/Usage   for the built-in FIFO or queue of your language or standard library.
