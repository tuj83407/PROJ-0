#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char filename[100];
	char filecontent[100];
	char delim[] = " ";
	
	printf("\nenter folder directory and filename:	");
	scanf("%[^\n]%*c", filename);//scanset character takes input until newline doesnt get encountered 
	
	printf("you entered the following filenames:  %s", filename);
	
	char *fileptr = strtok(filename, delim);
	
	while(fileptr != NULL){
		printf("\n\n\n\n-----------------------------------------------------------\n");
		printf("               Currently printing: %s \n", fileptr);
		printf("-----------------------------------------------------------\n");
		FILE *fp = fopen(fileptr, "r");
		
		if(fp == NULL){
			printf("wcat cannot open file \n");
			exit(1);
		}
		while(fgets(filecontent, 100, fp) != NULL){
			printf(" %s", filecontent);
		}
		fclose(fp);
		fileptr = strtok(NULL, delim);
	}
	printf("\n");

	exit(0);
	return 0;
}
