#include <stdio.h>

int add(int x, int y){
	int result = 0;
	printf("add : %d + %d = ", x,y);
	return x+y;
}

int sub(int x, int y){
	printf("sub : %d - %d = ",x,y);
	return x-y;
}

int mul(int x, int y){
	printf("mul : %d * %d = ", x,y);
	return x*y;
}
int div(int x, int y){
	printf("div : %d / %d = ",x,y);
	return x/y;
}

