#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void print_error(int foo){//use on each file operation, makeshift try-catch block
	if (foo == -1){
		printf("%s\n", strerror(errno));
		exit(1); //indicates program failed -- SOURCE: https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html	
	} 
}

int our_random(){

	int fd = open("/dev/random", O_RDONLY);
	print_error(fd);

	int buffer[1];

	print_error ( read(fd, buffer, sizeof(int)) );
	print_error( close(fd) );

	return buffer[0];
	
}

void print_darray(int foo [], int len){
	int i = 0;
	for (;i<len;i++){
		printf("\trandom %d: %d\n", i, foo[i]);
	}
}

int main (){
	int rands [10];
       
	int i = 0;
	for (;i<10;i++){
		rands[i] = our_random();
	}
	
	printf("Generating random numbers:\n");
	print_darray(rands, 10);

	printf("\nWriting numbers to file...\n\n");
	
	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644 );
	print_error(fd);

	int num_bytes = write(fd, rands, sizeof(int) * 10);
	print_error(num_bytes);//if num_bytes == -1
	
	print_error( close(fd) );


	printf("Reading numbers from file...\n\n");

	fd = open("output.txt", O_RDONLY);
	print_error(fd);

	int from_file [10];
	
	num_bytes = read(fd, from_file, sizeof(int) * 10);
	print_error(num_bytes);

	print_error( close(fd) );

	printf("Verification that written values were the same:\n");
	print_darray(from_file, 10);

	return 0;
}
