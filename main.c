#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


char* our_random(){

	int fd = open("/dev/random", O_RDONLY);
	char a[];
	read(fd, a, sizeof(int));
	return a;
	
}

int main (){
	char * rand = our_random();
	int a[] = rand;
	printf("%d",a[0]);
  	return 0;
}
