all: main.c
	gcc -o test_random main.c
run: all
	./test_random
