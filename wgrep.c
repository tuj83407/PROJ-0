#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char filename[100];
	char * linecontent = " ";
	
	char delim[] = " ";
	char searchterm[100];
	
	
	printf("\nenter folder directory and filename:	");
	printf("\n");
	scanf("%[^\n]%*c", filename);//scanset character takes input until 
	                             //newline doesnt get encountered 
	printf("you entered the following filenames:  %s", filename);
	
	
	
	printf("\n\nenter search term:	");
	printf("\n");
	scanf("%[^\n]%*c", searchterm);
	printf("you entered the following search term:  %s", filename);
	
	
	
	
	char *fileptr = strtok(filename, delim);
	
	while(fileptr != NULL){
		int linecount = 0;
		size_t len = 0;
		printf("\n\n-----------------------------------------------------------\n");
		printf("               Currently Searching : %s \n", fileptr);
		printf("-----------------------------------------------------------\n\n\n\n");
		FILE *fp = fopen(fileptr, "r");
		int tempmatch = 0;
		if(fp == NULL){
			printf("wgrep cannot open file \n");
			exit(1);
		}
		//while(fgets(filecontent, 100, fp) != NULL){
		//	printf(" %s", filecontent);
		//}
		while(linecontent != NULL){
			getline(&linecontent, &len, fp);
			//printf(" %s", linecontent);
			linecount++;
			//printf("LINE %d",linecount);
			for(int i = 0; i < len; i++){
				if(linecontent[i] == searchterm[0]){
					tempmatch = 1;
					for(int s = 1; s < strlen(searchterm); s++){
					 	if(linecontent[i+s] != searchterm[s]){
					 		tempmatch = 0;
					 		break;
					 	}
					}		
				}
				if(tempmatch == 1){
				printf("LINE %d: %s",linecount, linecontent);
				//linecontent = NULL;
				tempmatch = 0;
				break;
				}
			}
			free(linecontent);
		}
		fclose(fp);
		fileptr = strtok(NULL, delim);
	}
	printf("\n");

	exit(0);
	return 0;
}
