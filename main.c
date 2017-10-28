#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int our_random(){

	int fd = open("/dev/random", O_RDONLY);
	int buffer[1];
	read(fd, buffer, sizeof(int));
	//printf("in func: %d\n", buffer[0]);
	return buffer[0];
	
}

int main (){
	int rand = our_random();
	printf("%d\n",rand);
	return 0;
}
