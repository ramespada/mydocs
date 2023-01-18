#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define for_x for (int x = 0; x < w; x++)
#define for_y for (int y = 0; y < h; y++)
#define for_xy for_x for_y
#define for_yx for_y for_x

#define MAX_ITER 50

void show(void *u, int w, int h)
{
	int (*univ)[w] = u;
	printf("\033[H");
	for_y {
		for_x{
			printf(univ[y][x] ? "\033[07m  \033[m" : "  ");
			//printf(univ[y][x] ? " # " : " . ");
		}
		printf("\033[E");
		//printf("\n");
	}
	fflush(stdout);
}
 
void evolve(void *u, int w, int h)
{
	unsigned (*univ)[w] = u;
	unsigned new[h][w];
 
	for_yx {
		int n = 0;
		for (int y1 = y - 1; y1 <= y + 1; y1++){
			for (int x1 = x - 1; x1 <= x + 1; x1++){
				if (univ[(y1 + h) % h][(x1 + w) % w])
					n++;
 			}
		}
		if (univ[y][x]) n--;
		new[y][x] = (n == 3 || (n == 2 && univ[y][x]));
	}
	for_yx{
		 univ[y][x] = new[y][x];
	}
}
void game(int w, int h)
{
	int t=0;
	unsigned univ[h][w];
	for_xy univ[y][x] = rand() < RAND_MAX / 10 ? 1 : 0;
	while (t<MAX_ITER) {
		show(univ, w, h);
		evolve(univ, w, h);
		usleep(100000);
		t++;
	}
}
 
int main(int c, char **v)
{
	//c= # de argumentos (contando el exe)
	//v= argumentos dados como un string
	int w = 0, h = 0;
	if (c > 1) w = atoi(v[1]);	//arg1 -> w
	if (c > 2) h = atoi(v[2]);	//arg2 -> h
	if (w <= 0) w = 30;
	if (h <= 0) h = 30;
	
	game(w, h);

	return 0;
}
