#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  --argc;
  if(argc != 1 && argc != 3){
	printf("ERROR: the number of arguments must be 1 or 3, but got %d\n", argc);
	exit(1);
  }

  char systemCmd[4096];
  if(argc == 1) {
	sprintf(systemCmd, "bash ../util/scripts/download.sh %s", argv[1]);
  } else {
	sprintf(systemCmd, "bash ../util/scripts/download.sh %s %s %s", argv[1], argv[2], argv[3]);
  }

  system(systemCmd);

  return 0;
}
