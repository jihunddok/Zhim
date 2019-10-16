/*main.c*/
#include <stdio.h>
#include <dlfcn.h>
#include "libtest.h"

main(){
	printf("add(1,2 = %d\n",add(1,2));
	printf("sub(5,3) = %d\n",subtract(5,3));
	printf("mul(7,4) = %d\n",multiply(7,4));
	printf("div(10,2) = %d\n",divide(10,2));
}
