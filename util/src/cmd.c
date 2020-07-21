#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void usage() {
  printf("./cmd [command] [task alphabet]\n");
}

int main(int argc, char *argv[]){
  if(argc < 2){
	printf("ERROR: Command is not found\n");
	exit(1);
  }

  if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
	usage();
	exit(1);
  }

  char *cmd = argv[1];

  char arg[4096];
  if(argc >= 3){
	int cur = 0, pos = 0;
	while(pos < strlen(argv[2])){
	  arg[cur++] = argv[2][pos++];
	}
  }

  char systemCmd[4096];
  sprintf(systemCmd, "bash ../util/scripts/%s.sh %s", cmd, arg);
  system(systemCmd);
  
  return 0;
}
