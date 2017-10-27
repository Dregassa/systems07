#include <stdio.h>
#include <stdlib.h>
#include <fnctl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>



int main (){
  int fd = open("/dev/random", O_RDONLY);
  int* a;
  read(fd, a, sizeof(int));

  return 0;
}
