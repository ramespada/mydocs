#include <stdio.h>
#include <math.h>

int main(){

	int k;
	int n=10000;
	double pi=0.0;

	for(k=0;k<=n;k++) {
		pi+=pow(-1,k)*(1.0/(2.0*k+1.0));
	};

	printf("π = %f \n", pi*4.0);

	return 0;
}
