#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024

#define MAP(x) (x==0)?x:(10-x)
#define N 9

int matrix_arr[N][N]={
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {1, 2, 3, 4, 5, 6, 7, 8, 9}
                            };

void get_number(char *buf, const char *slipt_s, int *array, int size){
	char *slipt_buf[N], *p;
	int i = 0;
	p = NULL;
	p = strtok(buf, slipt_s); 
	while(p)
	{
		slipt_buf[i] = p;
		++i;
		p = strtok(NULL, slipt_s);  
	}                
	for (i = 0; i < N; ++i)
	{
		if(i < size)
			array[i] = atoi(slipt_buf[i]);
	}
}

void main(int argc,char *argv[]){
	char buf[MAX_LINE];		/*缓冲区*/
	FILE *fp; 				/*文件指针*/
 	int len;				/*行字符个数*/
	int line=0;	     		/*文本的行数*/

	if(argc < 2){
		printf("please input the matrix.txt path\n");
		exit(1);
	}

	if((fp = fopen(argv[1],"r")) == NULL)
	{
		printf("fail to read %s\n", argv[1]);
		exit(1);
	}
	while(fgets(buf,MAX_LINE,fp) != NULL)
	{
		len = strlen(buf);
		//printf("%s\n", buf);
		if(line < N)
			get_number(buf, ",", matrix_arr[line++], N);
	}

	printf("source array:\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", matrix_arr[i][j]);	
		}
		printf("\n");
	}

	printf("ts array:\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", matrix_arr[j][i]);
		}
		printf("\n");
	}

	printf("from ts array calculate map array:\n");
	for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                        printf("%d ", MAP(matrix_arr[j][i]));

                }
                printf("\n");
        }
	
}
