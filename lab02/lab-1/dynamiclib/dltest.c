#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

main(){
	void *handle;
	int (*add)(int,int),(*subtract)(int, int),(*multiply)(int,int),(*divide)(int,int);
	char *error;

	handle = dlopen("./lib/libtest.so",RTLD_LAZY);
	if(!handle){
		fputs(dlerror(),stderr);
		exit(1);
	}

	add = dlsym(handle, "add");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	subtract = dlsym(handle, "subtract");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	divide = dlsym(handle, "divide");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	printf("add(3,5) = %d\n", (*add)(3,5));
	printf("sub(10,3) = %d\n",(*subtract)(10,3));
	printf("mul(5,10) = %d\n",(*multiply)(5,10));
	printf("div(20,4) = %d\n",(*divide)(20,4));
	dlclose(handle);
}

