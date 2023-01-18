#include <stdio.h>
#include <math.h>


int es_primo(unsigned int n)
{
        unsigned int p;
        if (!(n & 1) || n < 2 ) return n == 2;

        /* comparing p*p <= n can overflow */
        for (p = 3; p <= n/p; p += 2)
                if (!(n % p)) return 0;
        return 1;
}

int FactoresPrimos(int n)
{
	int i;
	if (n==1){return 0;}
	if (es_primo(n)){printf("%d",n);}

	for(i=(n+2/2); i>1; i-- ){
		if (es_primo(i)){
	        	if ( n%i == 0 ) {
	        	 	while ( n%i == 0 ){
	        	 	     n=n/i;
			 	     printf(" %d ",i);
	        	 	};
	        	 	FactoresPrimos(n);
			 	return 0;
	       		};
		};
	};
	return 0;
};

int main(){
	int n;
	printf("Introduce un número entero:");
    	scanf("%d",&n);
	printf("%d = ",n);
	FactoresPrimos(n);
	printf("\n");
	return 0;
};
