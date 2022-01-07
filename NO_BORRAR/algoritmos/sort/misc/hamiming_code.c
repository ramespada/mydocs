#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 16

int i;

  
  

void initArray(int *x){
	for (i=0;i<N;i++){
		x[i]=rand()%2;
	}
}

int checkParity(int *x){
	int parity=0;

	for (i=0;i<N;i++){
		if (x[i] == 1){
			parity=parity ^ i;
		}
	}
	return parity;
}

void printArray(int *x){
	for (i=0;i<N;i++){
		printf("%d",x[i]);
	}
	printf("\n");

}

int main(){
	int bits[N];//{1,0,0,0,1,0,1,0,0,1,1,1,0,1,1,0};
	int xor;
	// Use current time as seed for random generator 
        srand(time(0)); 

	initArray(bits);

	//print initial array:
	printArray(bits);
	
	xor=checkParity(bits);
	printf("xor = %d\n",xor);
	
	bits[1]= !bits[1];
	bits[8]= !bits[8];
	
	bits[3]= !bits[3];
	
	//print modified array:
	printArray(bits);
	xor=checkParity(bits);
	printf("xor =%d\n",xor);

	return 0;
}
