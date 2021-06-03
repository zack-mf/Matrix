#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#define BUF_MAX 1024

#define MAP(x) (x==0)?x:(10-x)
#define N 9

int matrix_arr[N][N]={0};

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
	char buf[BUF_MAX];		/*缓冲区*/
	FILE *input_fp; 		/*文件指针*/
	FILE *output_fp;
 	int len;				/*行字符个数*/
	int line=0;	     		/*文本的行数*/
	char int_str[16]={0};

	if(argc < 3){
		printf("%s input_file output_file\n", argv[0]);
		exit(1);
	}

	if((input_fp = fopen(argv[1],"r")) == NULL)
	{
		printf("fail to open %s\n", argv[1]);
		exit(1);
	}

	if((output_fp = fopen(argv[2],"w")) == NULL)
    {
        printf("fail to open %s\n", argv[2]);
        exit(1);
    }

	fwrite("source array:\n", strlen("source array:\n"), 1, output_fp);
	while(fgets(buf,BUF_MAX,input_fp) != NULL)
	{
		len = strlen(buf);
		//printf("%s\n", buf);
		if(line < N){
			fwrite(buf, len, 1, output_fp);
			get_number(buf, ",", matrix_arr[line++], N);
			memset(buf, '\0', BUF_MAX);
		}
	}
	fwrite("\n", strlen("\n"), 1, output_fp);
	fclose(input_fp);

    fwrite("ts array:\n", strlen("ts array:\n"), 1, output_fp);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(matrix_arr[j][i] != 0){
				sprintf(int_str, "%d,", matrix_arr[j][i]);
            }else{
				sprintf(int_str, " ,");
            }
            if(j == N-1){
				fwrite(int_str, strlen(int_str)-1, 1, output_fp);
			}else{
				fwrite(int_str, strlen(int_str), 1, output_fp);
			}
			memset(int_str, '\0', (int)( sizeof(int_str) / sizeof(int_str[0]) ));
		}
		fwrite("\n", strlen("\n"), 1, output_fp);
	}

	fwrite("from ts array calculate map array:\n", strlen("from ts array calculate map array:\n"), 1, output_fp);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(matrix_arr[j][i] != 0){
				sprintf(int_str, "%d,", MAP(matrix_arr[j][i]));
			}else{
				sprintf(int_str, " ,");
			}
			if(j == N-1){
				fwrite(int_str, strlen(int_str)-1, 1, output_fp);
			}else{
				fwrite(int_str, strlen(int_str), 1, output_fp);
			}
				memset(int_str, '\0', (int)( sizeof(int_str) / sizeof(int_str[0]) ));
			}
			fwrite("\n", strlen("\n"), 1, output_fp);
        }

	fclose(output_fp);
	
}
