#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

void my_perror(const char *s);			

main(int argc, char *argv[]){
	FILE *f;

/*	if (argc < 2){
		printf("Usage: strerror_show nofilename\n");
		exit(1);
	}*/
	if ((f = fopen(argv[1],"r")) == NULL){// nofile
	my_perror("fopen");
		exit(1);
	}

	printf("Open a file \"%s\".\n",argv[1]);

	fclose(f);
}
void my_perror(const char *s){
	fprintf(stdout, "%s : %s\n",s,strerror(errno));
}
