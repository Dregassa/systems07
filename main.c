#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int our_random(){

	int fd = open("/dev/rando", O_RDONLY);
	if (fd == -1){
		printf("%s\n", strerror(errno));
		exit(1); //indicates program failed -- SOURCE: https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html	
	} 
	int buffer[1];

	if ( read(fd, buffer, sizeof(int)) == -1) {
		printf("%s\n", strerror(errno));
		exit(1);	
	}

	return buffer[0];
	
}

int main (){
	int rand = our_random();
	printf("%d\n",rand);
	return 0;
}
