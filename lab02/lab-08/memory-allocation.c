#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int width;
int height;

int **sum_matrix;
void print(int **arr);
void sum_of_matrix(int **arr1, int **arr2);
void free_mem(int **arr);
main(){


int **matrix_1;
int **matrix_2;
	int i,j;
	srand(time(NULL));
	printf("input row colum : ");
	
	scanf("%d %d",&height,&width);

	printf("construct matrix[%d][%d]\n",height,width);
	
	matrix_1 = (int**)malloc(sizeof(int*) * height);
	matrix_2 = (int**)malloc(sizeof(int*) * height);
	sum_matrix = (int**)malloc(sizeof(int*) * height);
	
	for (i = 0; i < height; i++){
		matrix_1[i] = (int*)malloc(sizeof(int)*width);
		matrix_2[i] = (int*)malloc(sizeof(int)*width);
		sum_matrix[i] = (int*)malloc(sizeof(int)*width);
	}

	for (i = 0; i< height ; i++){
		for(j = 0; j < width; j++){
			matrix_1[i][j] = rand()%50;
			matrix_2[i][j] = rand()%50;
		}
	}
	printf("---matrix 1---\n");
	print(matrix_1);
	printf("\n---matrix 2---\n");
	print(matrix_2);
	printf("\n---sum of matrix---\n");
	sum_of_matrix(matrix_1,matrix_2);

	free_mem(matrix_1);
	free_mem(matrix_2);
	free_mem(sum_matrix);
}
void print(int **arr){
	int i,j;
	for (i = 0; i< height ; i++){
		for(j = 0; j < width; j++){
			printf(" [%2d] ",arr[i][j]);
		}
		printf("\n");
	}
	
}
void sum_of_matrix(int **arr1, int **arr2){
	int i,j;
	for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            sum_matrix[i][j]=arr1[i][j] + arr2[i][j];
			
        }
    }
	print(sum_matrix);
}
void free_mem(int **arr){
	int i;
	for(i = 0; i < height; i++){
		free(arr[i]);
	}
	free(arr);
}