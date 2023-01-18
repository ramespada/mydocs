#include<stdio.h>

/*
Rule 30:
-------
Tabla:
1) 0 0 1 | 1
2) 0 1 0 | 1
3) 0 1 1 | 1
4) 1 0 0 | 1
---
5) 1 0 1 | 0
6) 1 1 0 | 0
7) 1 1 1 | 0
0) 0 0 0 | 0
============
Como expresión lógica:
!((x1 & (x2 | x3)) | (!x1 & !x2 & !x3))
*/

#define N 50
#define N_ITER 25

int rule30(int x1, int x2, int x3){
	//int out=!((x1 & (x2 | x3)) | (!x1 & !x2 & !x3));
	//printf("%d %d %d = %d\n",x1,x2,x3,out);
	//return out;
	return !((x1 & (x2 | x3)) | (!x1 & !x2 & !x3));
}


int main(){
	int i,k;
	int r1[N]={0};
	int r2[N]={0};
	int *p1,*p2,*temp;

	p1=&r1[0];	//pointer a r1
	p2=&r2[0];	//pointer a r2

	r1[N/2]=1;	//inicialización.

	for (k=1;k<N_ITER;k++){
		for (i=1;i<N-2;i++){
			printf("%s ",*(p1+i+1)? "#":".");
			*(p2+i+1)=rule30(*(p1+i),*(p1+i+1),*(p1+i+2));
		}
		printf("\n");
		temp=p1;p1=p2;p2=temp; //swap array's pointers
		//temp=&row2[0];p2=&row1[0];p1=temp;
	}

	return 0;
}
