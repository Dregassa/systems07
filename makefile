all: main.c
	gcc -o random main.c
run: all
	./random
