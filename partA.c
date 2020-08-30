#include <stdio.h>
int main() {
	char filename[100];
	char filecontent[100];
	printf("enter folder directory and filename");
	scanf("%s", &filename);
	FILE *fp = fopen("%s", filename, r);
	if(fp == NULL){
		printf("cannot open file\n");
	}
	while(fgets(filecontent, 100, fp) != NULL){
		printf("%s", filecontent);
	}
	fclose(fp);
	
	return 0;
}
