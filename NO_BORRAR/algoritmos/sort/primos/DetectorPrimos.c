#include <stdio.h>
#include <stdlib.h>

int es_primo(unsigned int n)
{
	unsigned int p;
	if (!(n & 1) || n < 2 ) return n == 2;
 
	/* comparing p*p <= n can overflow */
	for (p = 3; p <= n/p; p += 2)
		if (!(n % p)) return 0;
	return 1;
}

int main(void)
{
	int p;
	printf("Introduce un número entero:");
    	scanf("%d",&p);
	printf(es_primo(p) ? "Es primo" : "No es primo");
	printf("\n");
	return 0;
}
