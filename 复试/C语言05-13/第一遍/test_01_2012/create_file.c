#include <stdio.h>
#include <stdlib.h>

struct vector{
	long x;
	long y;
}vectorArray[20];

void main(){
	FILE *fp;
	int i = 0,j=0;
	for(i = 0; i < 12; i++){
		scanf("%ld%ld",&vectorArray[i].x, &vectorArray[i].y);
	}
	if((fp = fopen("D:\\org.bat", "wb")) == NULL){//将内存中的数据读入到二进制文件中去。
		printf("cannot open this file\n");
		exit(0);
	}
	else{
		for(i = 0; i < 12; i++){
			fwrite(&vectorArray[i].x,4,1,fp);
			fwrite(&vectorArray[i].y,4,1,fp);
		}
	}
	fclose(fp);
	printf("Successful! \n");
}