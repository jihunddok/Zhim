#include <stdio.h>
#include <errno.h>
#include <string.h>

main(){
	int i = 0;
	printf("%d\n",sys_nerr);
	printf("5d\n",sizeof(*sys_errlist));
	strerror(134);
	for (i = 0; i < sizeof(*sys_errlist);i++){
		printf("%s\n",sys_errlist[i]);
		strerror(i);
	}
	return;
}
