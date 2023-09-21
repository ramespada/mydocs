main: main.o scale.o
	gcc -o main main.o scale.o
main.o: main.c
	gcc -c main.c
scale.o: scale.c
	gcc -c scale.c
clean:
	rm *.o main
