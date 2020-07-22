#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void usage() {
  printf("USAGE: ./dl [url] [problem]\n");
  printf("USAGE: ./dl [provider] [contest] [problem]\n\n");
  printf("provider:\n");
  printf("  (atc, atcoder) | (cf, codeforces)\n");
  printf("contest:\n");
  printf("  contest name or number (ex: abc171, 1380 <- Edu CR 91\n");
}

int main(int argc, char *argv[]) {
  --argc;
  if(argc != 1 && argc != 2 && argc != 3){
	printf("ERROR: the number of arguments must be 2 or 3, but got %d\n", argc);
	exit(1);
  }

  if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
	usage();
	exit(1);
  }

  char systemCmd[4096];
  if(argc == 2) {
	sprintf(systemCmd, "bash ../util/scripts/download.sh %s %s", argv[1], argv[2]);
  } else {
	sprintf(systemCmd, "bash ../util/scripts/download.sh %s %s %s", argv[1], argv[2], argv[3]);
  }

  system(systemCmd);

  return 0;
}
