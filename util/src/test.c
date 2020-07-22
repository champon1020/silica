#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void usage(){
  printf("USAGE: ./test [problem]\n");
}

int main(int argc, char *argv[]) {
  if(argc < 2){
	printf("ERROR: no task\n");
	exit(1);
  }

  if(!strcmp(argv[1], "-h")){
	usage();
	exit(1);
  }

  char systemCmd[4096];
  sprintf(systemCmd, "bash ../util/scripts/test.sh %s", argv[1]);
  system(systemCmd);

  return 0;
}
